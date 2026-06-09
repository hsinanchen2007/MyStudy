```
class Solution(object):
    def firstMissingPositive(self, nums):
        bitmap = 0
        for num in nums:
            bitmap = bitmap | 1<<(num-1) if 0<num<=len(nums) else bitmap
        count = 1
        while bitmap&1:
            # print(bin(bitmap))
            bitmap >>= 1
            count += 1
        return count
```


利用python无限大int的位图法，其他语言可以自己用无符号整型数组实现一个位图类
bitmap | 1<<(num-1) 将第num-1位置上的0置为1
'0b1011'在第三个位置即第三个数缺失