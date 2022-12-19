### 解题思路
本题类似“计算2的幂” 在不适用递归和循环的情况下，使用二进制
“4”的二进制特点：只有1位是1，而且1后的0的个数是偶数
伪代码：
判断num如果小于0，不符合题意
转化成二进制
判断二进制中只有一个1
找到1的索引，切片
计算1后面的0的个数
返回题意


### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num<=0:
            return False
        num_bin=bin(num)
        num_bin_str=str(num_bin)
        if num_bin_str.count('1')==1:
            signal=num_bin_str.find('1')
            num_bin_str=num_bin_str[signal:]
            num_zero=num_bin_str.count('0')
            if num_zero%2==0:
                return True
            else:
                return False
        else:
            return False    



```