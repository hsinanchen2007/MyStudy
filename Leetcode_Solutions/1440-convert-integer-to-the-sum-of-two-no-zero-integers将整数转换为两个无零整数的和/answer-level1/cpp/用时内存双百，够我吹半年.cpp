### 解题思路
代码并不完善，思路就是从最后一位开始，遇到大于1的数就取1，（遇到1就取2，前一位减1，遇到0就取1，前一位减1）其实这两步可以合为一步。遇到小于1的数就取2，前一位减1。最后用n减去得到的数就可以得到另一个数，只要遍历一遍就可以了。望各位大神多多提意见。

### 代码

```cpp
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> sum(2);
        int s = n;
        int t = 1;
        if(n < 11)
        {
            sum[0] = 1;
            sum[1] = n - 1;
            return sum;
        }
        if(n == 11)
        {
            sum[0] = 2;
            sum[1] = n - 2;
            return sum;
        }
        if(n < 20)
        {
            sum[0] = 1;
            sum[1] = n - 1;
            return sum;
        }
        while(s >=9)
        {
            if(s % 10 > 1)
            {
                s /= 10;
                sum[0] =  t * 1  + sum[0];
            }
            else if(s % 10 == 1)
            {
                s = s / 10 - 1;
                sum[0] = 2 * t + sum[0];    
            }
            else if(s % 10 == 0)
            {
                sum[0] = 1 * t + sum[0];
                s = s / 10 - 1;
            }
            t *= 10;
        }
        sum[1] = n - sum[0];
        return sum;
    }
};
```