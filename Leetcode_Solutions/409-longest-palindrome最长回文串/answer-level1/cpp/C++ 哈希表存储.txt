### 解题思路


### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map(100);
        int res = 0;
        bool flag = 0;  //判断是否有奇数个数
        for(int i = 0;i < s.size();i++)
            map[s[i]]++;
        for(int i = 0;i < map.size();i++){
            if(map[i]%2) flag = true;
            res += map[i] / 2 * 2;  // 保证取的是偶数
        }
        if(flag) res += 1;  //若有奇数的个数，则加1
        return res;
    }
};
```