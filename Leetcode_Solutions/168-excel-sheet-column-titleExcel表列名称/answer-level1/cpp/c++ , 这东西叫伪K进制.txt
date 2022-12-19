![leetcode168.png](https://pic.leetcode-cn.com/80ebb72e47022a3c8775759c6fda92c8059c4a8f81adbb3152df589b82865233-leetcode168.png)
```
class Solution {
public:
    string convertToTitle(int num) {
            if(num<1){
                return "";
            }
            int size     = 26;
            string __res = "";
            int len      = 0;
            long cur     = 1;
            while(num >= cur){
                num = num - cur;
                cur = cur * size;
                ++len;
            }
            while(len--){
                cur   = cur/size;
                __res = __res + string(1,'A'+num/cur);
                num   = num % cur;
            }
            return __res;

    }
};
```
