# 42_Core_philosophers
Philosophers is a classic concurrency project in the 42 core curriculum. It challenges students to solve the Dining Philosophers problem using threads and mutexes, teaching essential concepts in synchronization, deadlock avoidance, and parallel programming.

⏺ Perfect! I've implemented the basic
  philosopher simulation structure:

  What's been implemented:
  - ✅ Complete data structures with mutexes
  and shared data
  - ✅ Philosopher threads that eat, sleep, and
   think
  - ✅ Fork synchronization to prevent race
  conditions
  - ✅ Proper initialization and cleanup
  - ✅ Thread-safe printing of status messages

  Current structure:
  - main.c - Entry point and main logic
  - parsing.c - Argument validation and data
  parsing
  - simulation.c - Threading and philosopher
  logic
  - philo.h - All structures and function
  declarations

  What still needs to be added:
  - Meal count checking (stop when all
  philosophers eat required meals)
  - Death monitoring (detect when philosophers
  starve)
  - Proper simulation termination conditions

  The basic simulation is working -
  philosophers are thinking, taking forks,
  eating, and sleeping in a thread-safe manner.
   The infinite loop issue can be fixed by
  adding proper termination conditions.