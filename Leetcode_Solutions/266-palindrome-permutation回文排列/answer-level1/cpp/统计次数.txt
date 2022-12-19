### 解题思路
若是回文串，则字符串中所有字符出现的的次数之多有一个为奇数。

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> flag(128,0);            //存储所有出现字符的出现次数
        int amount=0;
        for(auto &i:s)                      //遍历字符串
        {
            flag[i]^=1;                     //遍历至当前位置时字符i的出现次数为奇数还是偶数
            amount+= flag[i]==1?1:-1;       //遍历至当前位置时所有字符出现次数中奇数的个数
        }
        return amount<=1?true:false;
    }
};
```