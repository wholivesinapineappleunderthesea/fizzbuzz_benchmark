#include <stdio.h>
#include <iostream>
#include <chrono>

class FizzBuzzer {
public:
	virtual void RunOnce(long n) = 0;
	std::chrono::milliseconds TimedRuns(long runs, long n) {
		const auto start_time = std::chrono::steady_clock::now();
		for (long i = 0; i < runs; i++) RunOnce(n);
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time);
	}
};

class FizzBuzzIncremental : public FizzBuzzer {
public:
	void RunOnce(long n) {
		int fizzplace = 3;
		int buzzplace = 5;

		int i = 0;
		// no remainder with a numerator of zero, thus satisfies both conditions
		printf("FizzBuzz\n");
		i++;
	_reswitch:;
		switch (((i == buzzplace) << 1) + (i == fizzplace)) {
		case 0:
			printf("%d\n", i);
			goto _check_reswitch;
		case 1:
			printf("Fizz\n");
		_increment_fizz_and_continue:;
			fizzplace += 3;
			goto _check_reswitch;
		case 2:
			printf("Buzz\n");
			buzzplace += 5;
			goto _check_reswitch;
		case 3:
			printf("FizzBuzz\n");
			buzzplace += 5;
			goto _increment_fizz_and_continue;
		}
	_check_reswitch:;
		if (i++ < n) goto _reswitch;
	}
};

class FizzBuzzSimple : public FizzBuzzer {
public:
	void RunOnce(long n) {
		for (long i = 0; i < n; i++) {
			bool b = false;
			if (i % 3) {
				printf("Fizz");
				b = true;
			}
			if (i % 5) {
				printf("Buzz");
				b = true;
			}
			if (b) {
				puts("");
			} else {
				printf("%d\n", i);
			}

			
		}
	}
};


int main(int argc, char** argv, char** envp) {
	FizzBuzzIncremental inc;
	const auto inctime = inc.TimedRuns(50, 10000);
	FizzBuzzSimple sim;
	const auto simtime = sim.TimedRuns(50, 10000);
	
	
	
	
	std::cout << inctime.count() << "ms taken for incremental method.\n";
	std::cout << simtime.count() << "ms taken for simple method.\n";
	








	return 0;
}
