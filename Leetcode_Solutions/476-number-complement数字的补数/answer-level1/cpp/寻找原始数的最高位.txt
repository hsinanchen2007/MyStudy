### 解题思路
寻找数字的最高位，之后用最高位对应的数减去原始数，返回答案。
![image.png](https://pic.leetcode-cn.com/e94890da99561f488ffa5134b0e4d725febe868794edadabc6b09e49adf0ba88-image.png)

### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        unsigned int original = num;
        int n = 0 ;
        while(original>0)
        {
            n++;
            original = original>>1;
        }
        return pow(2,n)-num-1;
    }
};
```