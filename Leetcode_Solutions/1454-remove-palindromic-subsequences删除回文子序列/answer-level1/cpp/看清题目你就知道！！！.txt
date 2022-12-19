### 解题思路
子序列而非子串！！！

### 代码

```cpp
class Solution {
public:
    int removePalindromeSub(string s) {
        //1、贪心算法解决回文串 
        string temp=s;reverse(s.begin(),s.end());
        if(s.size()==0)
            return 0;
        else if(s==temp)
            return 1;
        else
            return 2;
    }
};
```