### 解题思路
可以修改元素的相对顺序，因此当发现目标元素时，将当前数组的最后一个元素转移到当前位置即可。

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        len1=len(nums)
        d=0
        while d<len1:
            if nums[d]==val:
                nums[d]=nums[len1-1]
                len1-=1
            else:
                d+=1
        return len1
```

![image.png](https://pic.leetcode-cn.com/3f131f53500c8326e915036326809dbb07fd0da7d2b8658f590937034df68bde-image.png)
