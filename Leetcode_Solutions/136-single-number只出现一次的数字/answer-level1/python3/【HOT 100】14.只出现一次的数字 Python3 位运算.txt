
啊啊啊啊啊啊啊啊啊啊啊啊，在焦虑其他事情中，先这样写吧，

位运算就可以不用其他空间保存数字了，异或操作，相异为1，相同为0，那么数组中出现两次的数字都会被异或操作的相同设置为0，然后剩下只出现一次的那个数字了

```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        
        for i in nums:
            res = res ^ i
            
        return res
```

附：祈祷我能早点（这周出结果）拿到北京offer。。。拜托了。。。（写于1024节日）

![image.png](https://pic.leetcode-cn.com/d0cd99952c882722a4d944d61436bc3b59acf55325263d04b26fdd3b2f7b4296-image.png)
