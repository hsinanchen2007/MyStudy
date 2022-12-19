### 解题思路
每次消去最右边的1，就减少了很多计算量。
![image.png](https://pic.leetcode-cn.com/f4ba1d6ca213a5ec66af5a13564b929467b8da6860e1250ecfdef2c315460457-image.png)
### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
             n=n&(n-1);
             count++;
        }
        return count;
    }
};
```