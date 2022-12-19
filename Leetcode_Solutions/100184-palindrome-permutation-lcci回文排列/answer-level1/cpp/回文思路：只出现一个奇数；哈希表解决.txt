### 解题思路
回文：
1. 只有一个字母出现奇数次，其他字母全部出现偶数次
2. 全部出现偶数次，则可判定为回文。

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
      
        int hash[128];
        for(int i=0; i<128; i++){//initial
            hash[i]=0;
        }

        //store the appearance time of each letter
        for(int i=0; i<s.size(); i++){
            hash[s[i]]++;
        }

        //依次判断是否只出现奇数次或偶数次
        int count =0;
        for(int i=0; i<128; i++){
            if(hash[i]%2==1) count++;
        }

        if(count ==1 || count ==0){
                return true;
        }
        return false;
    }
};
```