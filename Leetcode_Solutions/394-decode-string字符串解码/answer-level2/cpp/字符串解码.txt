### 算法分析
1. 使用栈strStack存储字符串，numStack存储数字
2. 定义字符串result用于存储结果，定义num=0存储中间数字
3. 遍历字符串s，i = 0 : s.size() - 1
4. 如果字符s[i] == '[', 则入栈result到strStack，入栈num到numStack
5. 如果字符s[i] == ']'，则出栈numStack栈顶元素count，出栈strStack栈顶元素str，
   遍历count：str += result, result = str
6. 如果字符s[i]为数字，计算num = num * 10 + s[i]
7. 否则result += s[i]
8.  返回result
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string result;
        int num = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                strStack.push(result);
                result = "";

                numStack.push(num);
                num = 0;
            }
            else if (s[i] == ']')
            {
                int count = numStack.top();
                numStack.pop();

                string str = strStack.top();
                strStack.pop();

                for (int j = 0; j < count; j++)
                {
                    str += result;
                }

                result = str;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
            }
            else
            {
                result.push_back(s[i]);
            }            
        }        
        
        return result;
    }
};