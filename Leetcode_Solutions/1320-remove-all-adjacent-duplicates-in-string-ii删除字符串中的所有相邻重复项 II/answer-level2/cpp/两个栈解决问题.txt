### 解题思路
构建两个栈，一个栈用来进行比较，压入不一样的字符；另一个栈用来记录该字符重复出现的数目。
当数目达到要求后，直接对其同步进行出栈即可。

上面的操作也可以使用stack<pair<char,int>>来实现。

在进行字符输出的时候，很容易会写的一个错误是直接把top元素依次输出。这里需要注意的是，还有一个**重复的数目**限制，这点在输出的时候需要注意一下！

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int size = s.size();
        stack<char> stk;
        stack<int> num;
        for(int i=0;i<size;i++)
        {
            if(!stk.empty() && s[i] == stk.top())
            {
                num.top() = num.top() + 1;
                if(num.top() == k)
                {
                    num.pop();
                    stk.pop();
                }
            }else{
                stk.push(s[i]);
                num.push(1);
            }
        }
        string res;
        while(!stk.empty())
        {
            //将每个子母的重复数目记录下来，然后输出出去
            int size = num.top();
            for(int j=0;j<size;j++)
            {
                res = stk.top() + res;
            }
            stk.pop();
            num.pop();
        }
        return res;
    }
};
```