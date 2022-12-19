
看到这个题，最开始犹豫怎么在原数组操作，但是突然想到，数组除了考虑遍历，还能考虑双指针，我双指针能不能用来解决这个问题呢？

那首先得想我双指针想干什么，我最终目的是什么，
我最终想把0都往后移，其他数值还得保持不变，所以双指针是用来交换位置的，但是不能一low一high的首位交换，首位交换就改变了原数组的顺序，那么我同时顺序遍历的交换呢？

那我**设置一个i用来交换位置，设置一个j用来遍历去找到所有不是0的数，都和i进行交换，交换之后i+=1**，这样i就保存的全是不为0的数，j就遍历将0换到后面去，如图：

![image.png](https://pic.leetcode-cn.com/23804eb5a952177e8e2e5450b4fdbf93ca5e30095e2badcb1dec7f599c4b4a01-image.png)


```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # if not nums:
        #     return None
        
        i = 0
        for j in range(len(nums)):
            if nums[j] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        
        return nums
```


![image.png](https://pic.leetcode-cn.com/ed13d6dee101ec12e30a100ae5597a37526c7c6b2b2357c44ca58f81f30bee00-image.png)
