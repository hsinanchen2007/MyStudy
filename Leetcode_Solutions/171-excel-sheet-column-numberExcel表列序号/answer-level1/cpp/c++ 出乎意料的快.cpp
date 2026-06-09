![leetoce171.png](https://pic.leetcode-cn.com/87efb0b175ea3706ae85d9d5cfba72a94ae3f5f6cd561e0149109e00038a8d18-leetoce171.png)
```
class Solution {
public:
    int titleToNumber(string num) {
            if(!num.length()){
                return 0;
            }
            int __res = 0;
            int len   = num.length();
            for(char i : num){
                __res = __res + (i-'A'+1)*addN(26,--len);
            }
            return __res;
        }
        int addN(int i,int n){
            return (int)pow(i,n);
        }
};
```
