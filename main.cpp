#include <array>
#include <format>
#include <iostream>
#include <cstdint>

extern "C" std::uint64_t fibonacci(std::uint32_t index);

static const std::array<std::uint64_t, 7> expected_values = {0, 1, 1, 2, 3, 5, 8};

static bool are_tests_successful;

void test_fib(std::uint32_t index) {
	std::uint64_t expected_res = expected_values[index];
	std::uint64_t res = fibonacci(index);
	if (res != expected_res) {
		std::cerr << std::format("Index {}: Expected {} but got {}.\n", index, expected_res, res);
		are_tests_successful = false;
	}
}

void run_tests() {
	are_tests_successful = true;

	for (std::uint32_t i = 0; i < expected_values.size(); i++) {
		test_fib(i);
	}

	if (!are_tests_successful) {
		std::exit(0);
	}
}

int main(int argc, char* argv[]) {
	run_tests();

	if (argc < 2) {
		std::cerr << "Expected `fib <index>`, but got 0 arguments.\n";
	}

	std::uint32_t index = std::stoi(argv[1]);
	std::uint64_t res = fibonacci(index);
	std::cout << "fib(" << index << ") = " << res;
}
