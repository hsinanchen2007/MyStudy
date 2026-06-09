### 解题思路
本题本质还是检查括号是否匹配，可以利用栈记录括号在字符串中的位置，当出现‘（’和‘）’时，出栈，其余情况时入栈。最后栈内剩余的就是需要删除的括号在字符串中的位置。
### 代码

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;  //储存结果的字符串
        stack<int> stacks;  //栈内存储的是括号的位置，用int类型即可，我第一次写的是char类型，一直报数组越界。。。。
        int len = s.length();
        vector<bool> flag(len, true);  //维护一个长度为字符串长度的数组，字符对应的bool值为True时加到结果字符串
        for(int i = 0; i < len; i ++)
        {
            if(s[i] == '(' || s[i] == ')')  
            {//栈不为空，且栈顶元素对应的字符为‘（’，s[i]为‘）’时，栈顶元素出栈
                if(!stacks.empty() && (s[i] == ')' && s[stacks.top()] == '(')) stacks.pop(); 
                else
                stacks.push(i);
            }
        }
        while(!stacks.empty())
        {
            flag[stacks.top()] = false;  //栈内剩余元素对应的字符删除
            stacks.pop();
        }
        for(int i = 0; i < len; i ++)
        if(flag[i]) ans += s[i];
        return ans;
    }
};
```