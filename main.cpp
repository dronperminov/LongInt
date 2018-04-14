#include <iostream>
#include <vector>
#include <string>

#include "LongInt.h"

struct TestT {
	LongInt op1;
	LongInt op2;
	LongInt obtained;
	LongInt expected;

	char op;
	bool correct;
};

TestT testMe(char op, const LongInt &a, const LongInt& b, const LongInt &res) {
	TestT test;

	test.op1 = a;
	test.op2 = b;
	test.expected = res;
	test.op = op;

	switch (op) {
		case '+':
			test.obtained = a + b;
			break;

		case '-':
			test.obtained = a - b;
			break;

		case '*':
			test.obtained = a * b;
			break;

		case '/':
			test.obtained = a / b;
			break;

		case '%':
			test.obtained = a % b;
			break;
	}

	test.correct = test.obtained == test.expected;

	return test;
}

void printTestResults(const std::vector<TestT>& tests) {
	size_t results = 0;

	for (size_t i = 0; i < tests.size(); i++) {
		results += tests[i].correct;

		std::cout << "Test" << (i + 1) << ". ";

		if (tests[i].correct)
			std::cout << "OK";
		else
			std::cout << "Failed: " << tests[i].op1 << " " << tests[i].op << " " << tests[i].op2 << " = " << tests[i].expected << " != " << tests[i].obtained;
		
		std::cout << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;
	std::cout << results << " / " << tests.size() << " (" << (100 * results / tests.size()) << "%)" << std::endl << std::endl;
}

void additions() {
	std::vector<TestT> adds;

	adds.push_back(testMe('+', 0, 0, 0));

	adds.push_back(testMe('+', 0, 25, 25));
	adds.push_back(testMe('+', 0, -25, -25));
	adds.push_back(testMe('+', -25, 0, -25));
	adds.push_back(testMe('+', 25, 0, 25));

	adds.push_back(testMe('+', -12, 25, 13));
	adds.push_back(testMe('+', 12, -25, -13));
	adds.push_back(testMe('+', -12, -25, -37));
	adds.push_back(testMe('+', 12, 25, 37));

	adds.push_back(testMe('+', 123456789, 987654321, std::string("1111111110")));
	adds.push_back(testMe('+', 987654321, 123456789, std::string("1111111110")));
	adds.push_back(testMe('+', -123456789, 987654321, std::string("864197532")));
	adds.push_back(testMe('+', -987654321, 123456789, std::string("-864197532")));
	adds.push_back(testMe('+', -123456789, -987654321, std::string("-1111111110")));
	adds.push_back(testMe('+', -987654321, -123456789, std::string("-1111111110")));

	std::cout << "Test of additions LongInt" << std::endl;
	printTestResults(adds);
}

void subtractions() {
	std::vector<TestT> subs;

	subs.push_back(testMe('-', 0, 0, 0));

	subs.push_back(testMe('-', 0, 25, -25));
	subs.push_back(testMe('-', 0, -25, 25));
	subs.push_back(testMe('-', -25, 0, -25));
	subs.push_back(testMe('-', 25, 0, 25));

	subs.push_back(testMe('-', -12, 25, -37));
	subs.push_back(testMe('-', 12, -25, 37));
	subs.push_back(testMe('-', -12, -25, 13));
	subs.push_back(testMe('-', 12, 25, -13));

	subs.push_back(testMe('-', 123456789, 987654321, std::string("-864197532")));
	subs.push_back(testMe('-', 987654321, 123456789, std::string("864197532")));
	subs.push_back(testMe('-', -123456789, 987654321, std::string("-1111111110")));
	subs.push_back(testMe('-', -987654321, 123456789, std::string("-1111111110")));
	subs.push_back(testMe('-', -123456789, -987654321, std::string("864197532")));
	subs.push_back(testMe('-', -987654321, -123456789, std::string("-864197532")));

	std::cout << "Test of subtractions LongInt" << std::endl;
	printTestResults(subs);
}

void multiplications() {
	std::vector<TestT> mults;

	mults.push_back(testMe('*', 0, 0, 0));

	mults.push_back(testMe('*', 0, 25, 0));
	mults.push_back(testMe('*', 0, -25, 0));
	mults.push_back(testMe('*', -25, 0, 0));
	mults.push_back(testMe('*', 25, 0, 0));

	mults.push_back(testMe('*', -12, 25, -300));
	mults.push_back(testMe('*', 12, -25, -300));
	mults.push_back(testMe('*', -12, -25, 300));
	mults.push_back(testMe('*', 12, 25, 300));

	mults.push_back(testMe('*', 123456789, 987654321, std::string("121932631112635269")));
	mults.push_back(testMe('*', 987654321, 123456789, std::string("121932631112635269")));
	mults.push_back(testMe('*', -123456789, 987654321, std::string("-121932631112635269")));
	mults.push_back(testMe('*', -987654321, 123456789, std::string("-121932631112635269")));
	mults.push_back(testMe('*', -123456789, -987654321, std::string("121932631112635269")));
	mults.push_back(testMe('*', -987654321, -123456789, std::string("121932631112635269")));

	std::cout << "Test of multiplications LongInt" << std::endl;
	printTestResults(mults);
}

void divisions() {
	std::vector<TestT> divs;

	divs.push_back(testMe('/', 0, 25, 0));
	divs.push_back(testMe('/', 0, -25, 0));

	divs.push_back(testMe('/', -12, 25, 0));
	divs.push_back(testMe('/', 12, -25, 0));
	divs.push_back(testMe('/', -12, -25, 0));
	divs.push_back(testMe('/', 12, 25, 0));

	divs.push_back(testMe('/', 123456789, 987654321, 0));
	divs.push_back(testMe('/', 987654321, 123456789, 8));
	divs.push_back(testMe('/', -123456789, 987654321, 0));
	divs.push_back(testMe('/', -987654321, 123456789, -8));
	divs.push_back(testMe('/', -123456789, -987654321, 0));
	divs.push_back(testMe('/', -987654321, -123456789, 8));

	divs.push_back(testMe('/', std::string("121932631112635269"), -987654321, -123456789));
	divs.push_back(testMe('/', std::string("121932631112635269"), 987654321, 123456789));
	divs.push_back(testMe('/', std::string("-121932631112635269"), 987654321, -123456789));
	divs.push_back(testMe('/', std::string("-121932631112635269"), -987654321, 123456789));

	divs.push_back(testMe('/', std::string("121932631112635269"), -123456789, -987654321));
	divs.push_back(testMe('/', std::string("121932631112635269"), 123456789, 987654321));
	divs.push_back(testMe('/', std::string("-121932631112635269"), 123456789, -987654321));
	divs.push_back(testMe('/', std::string("-121932631112635269"), -123456789, 987654321));

	std::cout << "Test of divisions LongInt" << std::endl;
	printTestResults(divs);
}

void modulus() {
	std::vector<TestT> mods;

	mods.push_back(testMe('%', 0, 25, 0));
	mods.push_back(testMe('%', 0, -25, 0));

	mods.push_back(testMe('%', 10, 25, 10));
	mods.push_back(testMe('%', 10, -25, 10));
	mods.push_back(testMe('%', 25, 10, 5));
	mods.push_back(testMe('%', -25, 10, -5));
	mods.push_back(testMe('%', 25, -10, 5));
	mods.push_back(testMe('%', -25, -10, -5));

	mods.push_back(testMe('%', 10, 25, 10));
	mods.push_back(testMe('%', 15, 25, 15));
	mods.push_back(testMe('%', 20, 25, 20));
	mods.push_back(testMe('%', 25, 25, 0));
	mods.push_back(testMe('%', 30, 25, 5));
	mods.push_back(testMe('%', 31, 25, 6));
	mods.push_back(testMe('%', 32, 25, 7));
	mods.push_back(testMe('%', 33, 25, 8));

	mods.push_back(testMe('%', std::string("121932631112635269"), 987654321, 0));
	mods.push_back(testMe('%', std::string("121932631112635270"), 987654321, 1));
	mods.push_back(testMe('%', std::string("121932631112635369"), 987654321, 100));
	mods.push_back(testMe('%', std::string("121932631112737279"), 987654321, 102010));

	std::cout << "Test of modulus LongInt" << std::endl;
	printTestResults(mods);
}

void factorials() {
	for (int i = 0; i <= 50; i++) {
		LongInt n = i;
		std::cout << n << "! = " << n.factorial() << std::endl;
	}
}

int main() {
	additions();
	subtractions();
	multiplications();
	divisions();
	modulus();

	factorials();
}