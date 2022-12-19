这题本身难度不大，但是有一个点需要注意：  
> 精度问题，像 python、javaScript 之类的语言记得在除 10 后进行一次整形转换

```
class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum = 0
        mul = 1
        while (n > 0):
            num = n % 10
            num =  int(num)
            n /= 10
            n =  int(n)
            sum += num
            mul *= num
        return mul - sum
```

>搜索订阅号 Apelife
>关注后回复 图解，分享给你leetcode动态图解解题集
>定期为大家分享题解，学习经验，解题思路等

