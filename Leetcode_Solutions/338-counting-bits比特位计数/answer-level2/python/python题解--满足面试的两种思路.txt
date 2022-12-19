### 1.使用位运算
![image.png](https://pic.leetcode-cn.com/5673f0862f5a617d7fccd71adc7a581a3f5a2eef0776309044b3986a5ef08c8a-image.png)

- 相信刷过剑指offer的小伙伴应该知道,判断一个数的二进制数中有多少个1,这个问题有几种不同的解法,我在这里只写一种效率最高的方法
- 使用 `n&(n-1)`来进行运算,找出一个数中有多少个1,`n&(n-1)`相当于将`n`的最后一位的1变成0
- 例如:数字`7`的二进制为`0111`,`7&(7-1)`,相当于`0111&(0110)=0110 `
- 时间复杂度`O(n*m))`,m为n的二进制长度
### 代码
```
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        result = []
        for i in range(num+1):
            temp = 0
            while i:
                i = i&(i-1)
                temp += 1
            result.append(temp)

        return result
```

### 2.奇偶数规律的DP(参考大神的)
![image.png](https://pic.leetcode-cn.com/28a2c481723da3a72e9851b2649a46ba17c092106bb6711d0229c964b6c6befa-image.png)

- 奇数的二进制中一的位数等于前面的偶数的二进制中1的个数加1,也就是前面偶数的最后一位的0变成1
- 偶数的二进制中一的位数等于自身除以2的数的二进制中1的个数,偶数除以2相当于右移一位,也就是将最后面的0移出去,不影响1的个数

### 代码

```python
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        result = [0]*(num+1)
        for i in range(1,num+1):
            if 1 & i:
                result[i] = result[i-1] + 1
            else:
                result[i] = result[i/2]
        return result

```