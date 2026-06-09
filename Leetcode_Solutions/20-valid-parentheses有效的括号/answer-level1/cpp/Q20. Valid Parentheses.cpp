C++面向对象思路实现isValid(string)判断字符串是否是有效的括号对。
```
#include <iostream>

/*
C++面向对象思路实现isValid(string)判断字符串是否是有效的括号对。
1. 括号对是可初始化(init)，可添加(addParentheses)的；
2. 将括号进行编码，左括号编码为n，则右括号编码为-n；
3. 利用栈这一数据结构的特性，判断当前字符和栈顶字符是否配对。
*/
class Solution {
public:
    // 因为是提交平台测试，所以需要为构造函数提供括号对作为默认参数
    Solution(string str = "(){}[]") {
        this->init(str);
    }

public:
    // C++实现：判断字符串s是否是有效的括号
    bool isValid(string s) {
        std::stack<int> parenthesesEnCodeStk;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            int charEnCode = this->getCharEnCode(s[i]);
            // 忽略其它字符
            if (charEnCode == 0)
                continue;

            // 左括号
            if (charEnCode > 0) {
                // 若栈内左括号数量已经大于等于测试串长度的一半了，即使后面全是正确的右括号，也不够了
                if (parenthesesEnCodeStk.size() >= len / 2)
                    return false;

                // 将左括号压入栈顶
                parenthesesEnCodeStk.push(charEnCode);
            } else {
                // 右括号配对失败：堆栈已空，或者栈顶左括号与当前右括号不成对
                if (parenthesesEnCodeStk.empty() || charEnCode + parenthesesEnCodeStk.top() != 0)
                    return false;

                // 右括号配对成功，栈顶左括号弹出栈
                parenthesesEnCodeStk.pop();
            }
        }

        // 如果栈内还有左括号，表示配对失败；反之。
        return parenthesesEnCodeStk.empty();
    }

    // 初始化
    void init(string parenthesesStr) {
        m_parenthesesEnCodeMap.clear();

        int len = parenthesesStr.length() / 2;
        for (int i = 0; i < len; ++i) {
            this->addParentheses(parenthesesStr[i * 2], parenthesesStr[i * 2 + 1]);
        }
    }

    // 添加括号对，同时为其编码
    void addParentheses(char leftChar, char rightChar) {
        int nSize = m_parenthesesEnCodeMap.size();
        int nEnCode = nSize / 2 + 1;
        m_parenthesesEnCodeMap.insert(std::make_pair(leftChar, nEnCode));
        m_parenthesesEnCodeMap.insert(std::make_pair(rightChar, -nEnCode));
    }

private:
    // 查找括号的编码
    int getCharEnCode(char c) {
        std::map<char, int>::iterator itFind = m_parenthesesEnCodeMap.find(c);
        if (itFind == m_parenthesesEnCodeMap.end())
            return 0;
        else
            return itFind->second;
    }

private:
    // 存放括号的编码
    std::map<char, int> m_parenthesesEnCodeMap;
};

int main() {
    Solution slt;
    string testStr("");
    std::cout << slt.isValid(testStr);
    return 0;
}
```

附上C语言的实现版本。使用数组和top指向模拟实现出栈和入栈操作，还需要注意退出函数时释放之前分配的内存。
```
bool isValid(char* s) {
	unsigned len = strlen(s), i = 0, top = 0;
	char* leftCharStk = (char*)malloc(len / 2 * sizeof(char));
	for (i = 0; i < len; ++i) {
		char curChar = s[i];
		if (curChar != '(' && curChar != '{' && curChar != '[' &&
			curChar != ')' && curChar != '}' && curChar != ']')
			continue;

		if (curChar == '(' || curChar == '{' || curChar == '[') {
			if (top >= len / 2)
				goto GOTO_EXIT;

			leftCharStk[top++] = curChar;
		} else {
			if (top <= 0)
				goto GOTO_EXIT;

			char topChar = leftCharStk[top - 1];
			if (topChar == '(' && curChar != ')' ||
				topChar == '{' && curChar != '}' ||
				topChar == '[' && curChar != ']')
				goto GOTO_EXIT;

			--top;
		}
	}

GOTO_EXIT:
	free(leftCharStk);
	return top == 0 && i >= len;
}
```

另外再附上评论区脚本语言简洁的实现方法的C++版本（随手写的，并不简洁了）。但是这种方法时间复杂度达到了O(n^2)，所以并不推荐。
```
class Solution {
public:
    bool isValid(string s) {
        string::size_type pos = string::npos;
        while (true) {
            if (s.length() == 0)
                return true;

            pos = s.find("()");
            if (pos != string::npos) {
                s.replace(pos, 2, "");
                continue;
            }

            pos = s.find("{}");
            if (pos != string::npos) {
                s.replace(pos, 2, "");
                continue;
            }

            pos = s.find("[]");
            if (pos != string::npos) {
                s.replace(pos, 2, "");
                continue;
            }

            break;
        }

        return s.length() == 0;
    }
};
```
我果真不适合写题解，写文章啊！