Python中没有Bitset数据结构，但是不妨碍使用
非背包方法
```
class Solution:
    def canPartition(self, nums):

        flag = 1                        # 初始化
        sumnums = 0
        for i in nums:
            sumnums += i                # 记录和
            flag = flag | flag << i     # 记录所有可能的结果

        if sumnums % 2 == 0:            # 和为偶数才有解
            sumnums //= 2
        else:
            return False

        target = 1 << sumnums           # 目标和

        if target & flag != 0:          # 目标位置上不为0
            return True
        else:
            return False
```


[https://blog.csdn.net/qq_29921623/article/details/100581100]()