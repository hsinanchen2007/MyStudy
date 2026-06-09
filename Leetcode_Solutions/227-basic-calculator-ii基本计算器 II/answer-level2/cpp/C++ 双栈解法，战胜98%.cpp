## 基本计算器 II

> LeetCode 第 227 题
>
> 难度：
>
> - `中等`
>
> tags：
>
> - `栈`

## 题目描述

实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，`+`， `-` ，`*`，`/` 四种运算符和空格 ` `。 整数除法仅保留整数部分。

**示例 1:**

```
输入: "3+2*2"
输出: 7
```

**示例 2:**

```
输入: " 3/2 "
输出: 1
```

**示例 3:**

```
输入: " 3+5 / 2 "
输出: 5
```

**说明：**

- 你可以假设所给定的表达式都是有效的。
- 请**不要**使用内置的库函数 `eval`。

------

## 思路

设立 `nums` 和 `ops` 两个栈，分别存储数字和操作符。

- 当读取到一个字符，并且对应的栈为空时，直接入栈。
- 当 push 数字时，若 ops 栈顶为 `*` 或 `/`，则使用 nums 栈顶、当前数字和 ops 栈顶进行计算，结果存回 nums
- 当 push 操作符时，若 ops 栈顶不为空，则一定是 `+` 或 `-`
  - 若操作符为 `*` 或 `/`，直接 push
  - 若操作符为 `+` 或 `-`，那么先用当前 ops 的栈顶计算，再压入当前操作符
- NOTE：要注意，数字可能有多位



```cpp
class Solution {
public:
  int calculate(string s) {
    if (s.empty()) return 0;
    stack<long int> nums;
    stack<char> ops;
    long int num = 0;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (ch == ' ') continue;
      if (!isdigit(ch)) {  // 标点符号
        if (ops.empty()) { // ops 栈为空
          ops.push(ch);
        } else { // ops 栈不为空，栈顶一定是 + 或 -
          if (ch == '*' || ch == '/')
            ops.push(ch);
          else {
            char op = ops.top();
            ops.pop();
            long int n2 = nums.top();
            nums.pop();
            long int n1 = nums.top();
            nums.pop();
            n1 = op == '+' ? n1 + n2 : n1 - n2;
            nums.push(n1);
            ops.push(ch);
          }
        }
      } else { // 数字
        num *= 10;
        num += ch - '0';
        if (i == s.size() - 1 || !isdigit(s[i + 1])) {
          if (nums.empty()) {
            nums.push(num);
          } else {
            if (ops.top() == '+' || ops.top() == '-') {
              nums.push(num);
            } else {
              long int t = nums.top();
              nums.pop();
              char op = ops.top();
              ops.pop();
              t = op == '*' ? num * t : t / num;
              nums.push(t);
            }
          }
          num = 0;
        }
      }
    }
    while (!ops.empty()) {
      long int b = nums.top();
      nums.pop();
      long int a = nums.top();
      nums.pop();
      char op = ops.top();
      ops.pop();
      long int t;
      if (op == '+') {
        t = a + b;
      } else if (op == '-') {
        t = a - b;
      } else if (op == '*') {
        t = a * b;
      } else {
        t = a / b;
      }
      nums.push(t);
    }
    return nums.top();
  }
};
```

