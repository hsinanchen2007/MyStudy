### 解题思路
此处撰写解题思路
遍历即可，相同时碰见R，就让temp++，else temp--，只要出现零，那就证明成对出现，cnt++
### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        if(s.size()<=0)
        return 0;
        int cnt=0;
        int temp=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
            temp++;
            else{
                temp--;
            }
            if(temp==0)
            cnt++;
            //为左为右都是为零时清空。
        }
        return cnt;
    }
};
```