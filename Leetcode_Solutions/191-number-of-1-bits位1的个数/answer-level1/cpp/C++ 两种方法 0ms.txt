#### 方法一：需要一个位掩码，也就是只有一位为1的值，每次左移一位，和n做按位与，如果大于0，统计加一，这是最常规的操作
#### 但是这个有优化方法，做完与当前位就没用了，按位异或置零，当n为0时停止，比官方第二种方法(n&=(n-1))快，0ms超越100%
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        uint32_t factor = 0x01;
        while(n>0)
        {
            if(n&factor) 
            {
                result++;
                n ^= factor;
            }
            factor = factor<<1;
        }
        return result;
    }
};
```
#### 方法二代码：
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n>0)
        {
            n=n&(n-1);
            result++;
        }
        return result;
    }
};
```

