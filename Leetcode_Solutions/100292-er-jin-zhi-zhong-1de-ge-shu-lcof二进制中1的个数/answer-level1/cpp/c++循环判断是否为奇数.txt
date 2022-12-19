### 解题思路
 ### 1.判断第零位是否是1（也就是判断是否是奇数）
 ###2. 向右移动一位 
 ###解法：
while(n>0)
{
    if(n&1) //判断是否为奇数,是奇数返回一
    count++;
    n>>=1;//n向右移动一位
}
###相似的写法：
 while(n>0)
        {
            //n&1是判断n为奇数，当n为奇数的时候返回一
            if (n%2 == 1) count++;
            //n右移一位，代表除二操作
             n/=2;
        }
### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n>0)
        {
            //n&1是判断n为奇数，当n为奇数的时候返回一
            if (n%2 == 1) count++;
            //n右移一位，代表除二操作
             n/=2;
        }
        return count;
    }
};
```