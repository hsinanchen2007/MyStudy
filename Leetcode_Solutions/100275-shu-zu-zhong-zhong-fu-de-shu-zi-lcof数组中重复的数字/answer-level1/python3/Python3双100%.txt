初始化一个长度为 n 的数组，全部用 -1 填满，表示所有位置都没有被访问过
因为给到的 nums 的范围是 0 ~ n-1，所以 nums 上的每个值都可看作是访问数组的位置索引
在遍历过程中，若该位置的值为 -1，说明该位置没有被访问过，所以令该位置上的值修改为任意不是 -1 的数
若该位置上的值不为 -1，则说明此位置之前被访问过，即重复访问，返回该值即可

```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        if not nums:
            return None;
        ls = [-1] * len(nums)
        for num in nums:
            if ls[num] == -1:
                ls[num] = num
            else:
                return num


```

![image.png](https://pic.leetcode-cn.com/fcf74c0b57a98dec696d0bc1f04d8c40f705a10ba51178abdb6deb79f5a915b9-image.png)
