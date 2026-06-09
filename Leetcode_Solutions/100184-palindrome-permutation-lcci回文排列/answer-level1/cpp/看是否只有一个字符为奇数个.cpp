### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int mp[128] = {0};
        for(int i = 0;i < s.size();++i)
        mp[s[i]]++;
        int flag = 0;//判断是否只有一个落单的
        for(int i = 0;i < 128;++i){
            if(mp[i] % 2 == 1){
                if(flag == 0)
                flag = 1;
                else
                return false;
            }

        }
        return true;

    }
};
```