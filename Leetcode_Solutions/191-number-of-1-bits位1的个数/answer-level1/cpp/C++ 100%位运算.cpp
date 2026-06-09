### 解题思路
位运算 与上题思路一致

### 代码

```cpp
/*位运算 与上题思路一致*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        int i=32;
        while(i--){
            if(n&1) ans++;
            n >>= 1;
        }
        return ans;
    }
};
```
![image.png](https://pic.leetcode-cn.com/3b40b5d6a0328ec9fd346254e79cdeb7b15acee4ffffdd58f6832d0dc838726c-image.png)
