### 解题思路
1.32位逐一与1按位&操作
2.如果是求0的个数，则按位|操作

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        for(int i=0;i<32;i++){
            if(n & (1<<i))
                num++;
        } 
        return num;       
    }
};
```