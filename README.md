# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

Student submission:

The PID algorithm is used for both steering and throttle.  I had to use a PID on the throttle because I could not get stable steering PID parameters at high speeds on the corners.  I used the unmodified CTE value for both PID loops. The negative of the steering PID control value was used for the steering value.  The absolute value of the throttle PID was subtracted from one for the throttle value.  No conversions were made and the steering and throttle positions from the simulator where not used.  Just the CTE value was only used.  I only used the integral constant on the steering PID and it was very small. I did not use it for the throttle PID as it only seemed to slow the response down.  The car gets around the track without going over the edge but drives somewhat erratic.

It is very difficult to get smooth steering.  The CTE value given by the simulator seems to be a function of linearly interpolated points between the waypoints. This causes high errors after each waypoint due to the sharp change in direction.  I had to use a high differential value on the steering PID to compensate for these high disturbances and had to use a low integral value so it would allow for a quick response.  This allows the car to go somewhat fast but it is constantly oscillating across the center line of the road.

My goal was to go as fast as possible but I could only reach about 65 mph on the long stretch.  This is because the car is constantly compensating for the error jumps at the waypoints which makes it drive back and forth over the centerline. I could slow it down considerably to smooth it out but then that is no fun since no other cars are on the road.

I use negative values on the throttle to quickly slow down.  The brake lights also show up when you do this.  If you do not go negative then the car will just coast with a zero value.  I use a very high differential constant on the acceleration PID so when the vehicle gets close to the edge of the road on a curve it will slow down very fast to make the curve. It took some time to twiddle this so it only braked on curves and not from the fast change in direction at the waypoints.

The integral value on the steering PID was required but only a very small value could be used and not much over or under that value.  Twiddling around that very small value aloud me to go about 4 mph higher but that is it.  Any higher or lower caused under or over dampening which results in the car going off course.

I believe I could of spent more time twiddling the constants but my progress was getting slower and slower.  I kept finding my way back to the same magnitudes.  I tried implementing an auto tuning method similar to the twiddling algorithm but was unsuccessful in getting good values.  The simulator updates are very slow and so my method did not have enough time to develop so I just removed it.  I did however simulate it manually to get the values I have now.  One parameter at a time.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

