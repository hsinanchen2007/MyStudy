### 解题思路

统计奇偶个数

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
		int bac[255]={0};
        int tmp=0;
        for(auto &i:s){
            if(++bac[i]%2==1)tmp++;
            else tmp--;
        }
        return tmp<2;
    }
};
```