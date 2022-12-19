### 解题思路
通过n&(n-1)这个操作，可以起到消除最后一个1的作用。
所以可以通过执行n&(n-1)操作来消除n末尾的1，消除了多少次，就说明有多少个1。
### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0)
        {
            n=n&(n-1);
            count++;
        }

        return count;
    }
};
```