#### 算法思路
我们遍历一遍数组，并更新最小值和次小值，如果遍历到结尾找到了比次小值大的数，返回`True`，否则返回`False`。
#### 参考代码
```
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        min_num,sec_num = float('inf'),float('inf')  # 初始化最小值，次小值
                                                     
        for i in nums:                               
            min_num = min(i,min_num)                 # 维护min_num为最小值
            if i > min_num:                          # 找到了次小值
                sec_num = min(i,sec_num)             
            if i > sec_num:                          # 找到了第三大的数
                return True

        return False
```
#### 复杂度分析
- 时间复杂度：$O(N)$,$N$为数组的长度，我们遍历了一遍数组。
- 空间复杂度：$O(1)$,我们使用了`min_num`,`sec_num`保存结果。

![白色背景关注.jpg](https://pic.leetcode-cn.com/47d1b5430e869ed420bb0c6e8a90250773528ccf1bf6d4d43aef80dd326eeef9-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
