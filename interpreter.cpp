#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

auto execute(std::stack<int>& stack, char op) -> void {
  auto operand1 = stack.top(); stack.pop();
  auto operand2 = stack.top(); stack.pop();
  switch (op) {
    case '+': stack.push(operand1 + operand2); break;
    case '-': stack.push(operand1 - operand2); break;
    case '*': stack.push(operand1 * operand2); break;
    case '/': stack.push(operand1 / operand2); break;
  }
}

auto interpret(const std::vector<std::string>& elems) -> int {
  auto stack = std::stack<int>();
  for (int i = 0; i < elems.size(); i++) {
    if (elems[i] == "+") {
      execute(stack, '+');
    } else if (elems[i] == "-") {
      execute(stack, '-');
    } else if (elems[i] == "*") {
      execute(stack, '*');
    } else if (elems[i] == "/") {
      execute(stack, '/');
    } else {
      auto n = boost::lexical_cast<int>(elems[i]);
      stack.push(n);
    }
  }
  return stack.top();
}

auto main() -> int {
  auto line_string = std::string();
  while (true) {
    std::cout << "> " << std::flush;
    std::getline(std::cin, line_string);
    if (line_string == ":quit") {
      break;
    }
    auto elems = std::vector<std::string>();
    boost::algorithm::split(elems, line_string, boost::is_space());
    auto result = interpret(elems);
    std::cout << "= " << result << std::endl;
  }
  std::cout << "Bye!" << std::endl;
}
