![image.png](https://pic.leetcode-cn.com/24dc69041e72474ce1197f911c192f5d6ae1890fac054b326e69330cdef44ab3-image.png)
```
class Solution {
public:
    string reverseParentheses(string s) 
    {
        //用栈来记录括号，这样方便找到与左括号匹配的右括号
        stack<int> ss;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') ss.push(i);
            else if(s[i]==')')
            {
                //对字符串直接反转
                reverse(s.begin()+ss.top(),s.begin()+i);
                ss.pop();
            }
            else continue;//遇到字母直接下一次循环
        }
        //去掉s中的括号
        string res="";
        for(auto it:s)
        {
            if(it!=')'&&it!='(') res+=it;
        }
        return res;
    }
};
```

