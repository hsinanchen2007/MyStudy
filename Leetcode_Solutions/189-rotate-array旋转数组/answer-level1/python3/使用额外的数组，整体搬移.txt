### 解题思路
此处撰写解题思路
2）使用额外的数组，整体搬移
        """
        # 2）使用额外的数组，整体搬移
        # [1, 2, 3, 4, 5, 6, 7] 
        #      备份 |
        # tmp_nums = [1, 2, 3, 4]
        #  0 ~ len(nums)-k
        # 后面k个往前拷贝
        # [5, 6, 7, 4, 5, 6, 7]
        # 在把      |   把备份的重新拷贝过来
        # [5, 6, 7, 1, 2, 3, 4]
![image.png](https://pic.leetcode-cn.com/b80dab9a9767d8b118c600725034e0edc76a27e04e1f69bb163b3b920a8d4867-image.png)

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 会超时
        # for i in range(k):
        #     tmp = nums[-1]
        #     for j in range(len(nums)-2,-1,-1):
        #         nums[j+1] = nums[j]
        #     nums[0] = tmp
        # 使用额外的数组，整体搬移
        tmp_nums = nums[0:len(nums)-k]
        if tmp_nums == nums:
            return
        print(tmp_nums)
        nums[0: k] = nums[len(nums)-k:len(nums)]
        print(nums)
        nums[k: len(nums)] = tmp_nums
        print(nums)
```