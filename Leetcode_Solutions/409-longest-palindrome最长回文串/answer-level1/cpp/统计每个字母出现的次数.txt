### 解题思路
- 定义map统计每一个字母出现的次数
- 遍历map,如果是偶数，全部使用，如果是奇数，减一使用
- 最后，如果有奇数个字母出现，那么只能出现一次，+1即可。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length() == 0)
            return 0;
        unordered_map<char, int> m;
        for(auto a : s){
            ++m[a];
        }
        int res = 0, p = 0;
        for(auto a : m){
            if(a.second % 2 == 0)
                res += a.second;
            else{
                res += a.second - 1;
                p = 1;                    
            }
            //cout << a.first << " " << a.second <<endl;
        }
        res += p;
        return res;
    }
};
```