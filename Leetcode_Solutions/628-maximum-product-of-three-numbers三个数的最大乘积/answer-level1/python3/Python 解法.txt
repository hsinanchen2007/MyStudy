### 解题思路
1、代码写的有点繁琐，但是能通过
2、思路很简单，先倒序排序，对正数和负数分开判断，注意：负数最多只取两个
3、比较一下倒叙后的nums的前面三个和最后两个负数的大小，如果最后两个负数比前面三个正数都大，那么就可以取第一个正数*两个负数
4、如果都是负数：那么倒序后，前面三个数的乘积是最大的。
5、上述文字写的有点啰嗦，可以直接看代码

### 代码

```

class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        ##先排序
        nums.sort(reverse=True)
        ##找负数的个数,不可能取负数的三个值，所以只可能取负数的两个值
        count = 0
        for i in range(len(nums)):
            if nums[i]<0:
                count = len(nums)-i
                if count>=2:
                    fushu = nums[-count:][-2:]
                break
        zhengshu_three = nums[0]*nums[1]*nums[2]
        if count >=2:
            zheng_fu_three = nums[0]*fushu[-2]*fushu[-1]
            if zheng_fu_three>=zhengshu_three:
                return zheng_fu_three
        return zhengshu_three
        
       
```