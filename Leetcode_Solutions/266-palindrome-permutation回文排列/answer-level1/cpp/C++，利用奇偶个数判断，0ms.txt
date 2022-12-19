### 解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
7.6 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int size = s.size();
        bool status = size % 2 ? true : false;
        vector<int> ascii(256, 0);
        for(int i = 0; i < s.size(); ++i){
            ascii[s[i]]++;
        }
        for(int i = 0; i < 256; ++i){
            if(ascii[i] % 2){
                if(status){
                   status = false;
                   continue;
                }
                return status;
            }
        }
        return true;
    }
};
```