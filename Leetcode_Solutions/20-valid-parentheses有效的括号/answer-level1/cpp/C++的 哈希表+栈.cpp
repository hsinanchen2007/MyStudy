### 解题思路
Hash map + stack 
![批注 2020-04-08 220620.jpg](https://pic.leetcode-cn.com/526ed44c0a5c67f5c858828ab3137c0d67342e46e967de97f16a73a0c02e1b52-%E6%89%B9%E6%B3%A8%202020-04-08%20220620.jpg)

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) 
    {
        map<char,char> mp;
        mp.insert(pair<char,char>('[',']'));
        mp.insert(pair<char,char>('{','}'));
        mp.insert(pair<char,char>('(',')'));
        stack<char> st;
        if(s.empty())
        {
            return true;
        }
        int len = s.size();
        int i = 1;
        st.push(s[0]);
        while (i<len)
        {
            if(mp[st.top()] == s[i])
            {
                st.pop();
                i++;
                if(st.empty() && i<len)
                {
                    st.push(s[i]);
                    i++;
                }
            }
            else
            {
                st.push(s[i]);
                i++;
            }
        }
        return st.empty(); 
    }
};
```