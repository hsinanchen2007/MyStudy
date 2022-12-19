### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0)
        {
            count++;
            n = n & (n - 1);//一个数和比他小的数做位与运算之后，会将其最后一位的1变为0；
        }
        return count;
    }
};
```