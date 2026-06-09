# 题解

## 三指针

 1. 定义$0$的右界$bound\_0=0$,$2$的左界$bound\_2=n-1$，$n$为数组长度。$cur$为当前元素。
 2. 当$cur<=bound\_2$时，进入循环：
 	* 若$nums[cur]==0$，此时和$0$的右界$bound\_0$进行交换，并更新右界和$cur$，即$bound\_0+=1,cur+=1$。
 	* 若$nums[cur]==2$，和$2$的左界$bound\_2$进行交换，并更新左界，向左移动，即$bound\_2-=1$。
 	* 若$nums[cur]==1$，则将$cur$指向下一元素

### 复杂度分析
 - 时间复杂度：$O(\log (n))$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        bound_0=0
        bound_2=n-1
        cur=0
        while(cur<=bound_2):
            if(nums[cur]==0):
                nums[cur],nums[bound_0]=nums[bound_0],nums[cur]
                bound_0+=1
                cur+=1
            elif(nums[cur]==2):
                nums[cur],nums[bound_2]=nums[bound_2],nums[cur]
                bound_2-=1
            else:
                cur+=1
```