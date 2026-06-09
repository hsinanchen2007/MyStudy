#### [1332. 删除回文子序列](https://leetcode-cn.com/problems/remove-palindromic-subsequences/)

#### 题解

  + 此题是删除回文子序列，而非字串，子序列只要求顺序不变，不必相邻
  + 因为只有a，b，所以最多的操作也只有2次，单独挑出所有的a或者所有的b进行删除
  + 当原字符串为空的时候返回0，当原字符串为回文串的时候返回1，其他进行上述操作都返回2
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 0) return 0;
        bool flag = true;
        for(int i = 0; i <= s.size()/2; i++)
            if(s[i] != s[s.size()-i-1])
                {
                    flag = false;
                    break;
                }
        return flag ? 1 : 2;
    }
};
```
