### 解题思路
此题类似于括号匹配问题，可以将字符为R时进栈，字符为L时出栈。
 设置一个变量，利用一个for循环遍历字符串的每一个数组。当字符为R时变量加一，当字符为L时变量减一，
  则当变量为0时，说明已经有平衡的RL字符串。记录变量为0的次数ans，return这个次数。

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int n=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')
            n++;
            if(s[i]=='L')
            n--;
            if(n==0)
            ans++;
        }
        return ans;
        
    }
};
```