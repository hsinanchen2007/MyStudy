### 算法分析
1. 定义n = tokens.size()，定义tmpStack用于存储字符串
2. 从头遍历tokens，i = 0 : n-1
3. 如果tokens[i]是数字，入栈
4. 否则出栈前两个数字并计算，将计算结果入栈
5. 遍历结束，返回栈顶元素
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O((n + 1)/2)
### 源码
```C++ []
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> tmpStack;
        
        for (int i = 0; i < n; i++)
        {
            string str = tokens[i];
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = tmpStack.top();
                tmpStack.pop();

                int left = tmpStack.top();
                tmpStack.pop();

                int result = evalNumbers(left, right, str);
                tmpStack.push(result);
            }
            else
            {
                int val = stoi(str);
                tmpStack.push(val);
            }            
        }
        
        return tmpStack.top();
    }

    int evalNumbers(int left, int right, string operation)
    {
        if (operation == "+")
        {
            return left + right;
        }
        else if (operation == "-")
        {
            return left - right;
        }
        else if (operation == "*")
        {
            return left * right;
        }
        else if (operation == "/")
        {
            return left / right;
        }
        return 0;
    }
};