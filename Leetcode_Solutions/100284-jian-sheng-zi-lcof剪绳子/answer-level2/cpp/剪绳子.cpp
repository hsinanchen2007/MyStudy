### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int b = n % 3;
        int a = n / 3;
        if(b == 0){
            return pow(3,a);
        }else if(b == 1){
            return pow(3,a-1)*4;
        }else if(b == 2){
            return pow(3,a)*2;
        }
      return 0;  
    }
};
```
双百通过；借鉴被人的证明思路![screenshot-leetcode-cn.com-2020.03.20-22_22_28.png](https://pic.leetcode-cn.com/48b480f1fae9732543e4a3aa029991c2006590313961f45d1beb764ca6c600a7-screenshot-leetcode-cn.com-2020.03.20-22_22_28.png)
