
本题难点，**原地修改**
且在$O(1)$**空间**下完成
## 双指针1
### 算法流程：
 1. 定义指针$i=0$
 2. 从第一个元素开始遍历，对于$nums[j]$: 判断条件$nums[j]!=val$，如果满足，将这个值填入$nums[i]$,并令$i=i+1$,指向下一位置
 3. 最后一次$i$加了1，所以返回长度时无需加1.

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$,只扫描了一遍
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n=len(nums)
        i=0
        for j in range(n):
            if(nums[j]!=val):
                nums[i]=nums[j]
                i=i+1
        return i
```


## 双指针2
另外一种双指针写法，首尾交换
### 算法流程：
 1. 定义左指针$l=0$和右指针$r=n$ **特别注意：**这里右指针$r=n$，这样可以将很多特例如：[1],1包含在内
 2. 执行循环$l<r$
 	* 如果$nums[l]==val$,则交换$nums[l]$和$nums[r]$,表示，如果左端值等于$val$,则和右端交换。并令右端$r=r+1$,表示这个位置已经放了$val$,和下一位置交换
 	* 若不满足条件，则令左端指向下一元素$l=l+1$
 
 3. 返回$l$,这里因为右指针初始化为$n$,可结合例子，发现i即为最终长度
 
**重点：**
一定要结合例子体会右指针初始化为数组长度$n$

### 复杂度分析

 - 时间复杂度：$O\left(n\right)$,只扫描了一遍
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n=len(nums)
        l=0
        r=n
        while(l<r):
            if(nums[l]==val):
                nums[l],nums[r-1]=nums[r-1],nums[l]
                r=r-1
            else:
                l=l+1
        return l
```

