### 解题思路
通过按位与1来判断是否有1。这里采用自右向左来判断1的个数，通过左移flag中1的位置，来与n按位与，判断n中是否有1。

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // n为uint32_t,最多有32个1
        uint32_t flag = 1;
        int count = 0;
        while(flag){
            // 通过flag的1左移来与n按位与，从左到右计算1的个数
            // 当超过32位时，flag为0,循环结束
            if(n & flag){
                // 如果当前flag位置有1，count加1
                count++;
            }
            flag = flag << 1;   // flag检验位数向左移一位
        }
        return count;
    }
};
```

### 解题思路
n - 1能让最右边的1变成0

第一种情况，最右边是1,减1之后最右边的1变成0

第二种情况，最右边不是1,那么减1之后最右边的1（假设是从右到左第n位）变成0,前n-1位的0变成1,但是第n位左边没有变化。相当于右边n位取反。所以用n & (n - 1)，将第一个1清零。左边不变。
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            // 只要n>0,说明n中必包含1
            count++;
            // n - 1能让最右边的1变成0
            // 第一种情况，最右边是1,减1之后最右边的1变成0
            // 第二种情况，最右边不是1,那么减1之后最右边的1（假设是从右到左第n位）变成0,前n-1位的0变成1,但是第n位左边没有变化。相当于右边n位取反。所以用n & (n - 1)，将第一个1清零。左边不变。
            n = n & (n - 1);
        }
        return count;
    }
};
```