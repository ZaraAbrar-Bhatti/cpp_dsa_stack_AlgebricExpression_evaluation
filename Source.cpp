#include <iostream>
#include <string>
#define max 30
using namespace std;
class stack_arr{
public:
	char *stack = new char[max];
	int top;
	stack_arr(){
		top = -1;
		for (int i = 0; i <= max; i++){
			stack[i] = 0;
		}
	}
	void push(char opt){
		if (top == max - 1){
			cout << "Stack Overflow." << endl;
		}
		else{
			top = top + 1;
			stack[top] = opt;
		}
	}
	char pop(){
		char temp;
		if (top < 0){
			cout << "Stack Underflow." << endl;
			return -1;
		}
		else{
			temp = stack[top];
			top = top - 1;
			return temp;
		}
	}
};
bool cheak_open_brkts(string exp){
	stack_arr brackets;
	int counter = 0;
	char c;
	for (int i = 0; i < exp.length(); i++){
		c = exp[i];
		if (c == '(' || c == '{' || c == '['){
			brackets.push(c);
			counter = counter + 1;
		}
		else if (c == ')' || c == '}' || c == ']'){
			counter = counter - 1;
			char store;
			switch (c){
			case ')':
				store = brackets.pop();
				if (store != '(')
					return false;
				break;
			case'}':
				store = brackets.pop();
				if (store != '{')
					return false;
			case']':
				store = brackets.pop();
				if (store != '[')
					return false;
				break;
			default:
				break;
			}
		}
		else
			continue;
	}
	if (counter == 0){
		return true;
	}
	else
		return false;
	
}

int main(){
	string expression;
	cout << "Enter an algebric expression for verification whether the expression is valid or not :" << endl;
	getline(cin, expression);
	if (cheak_open_brkts(expression)){
		cout << "Valid Algebric Expression" << endl;
	}
	else{
		cout << "Invalid Algebric Expression" << endl;
	}
	system("pause");
	return 0;
}