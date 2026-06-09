## 暴力法
两次循环
第一次循环，对于数组中每一个数 $nums[i]$ 进行遍历
第二次循环，从当前数的下一个数 $nums[j]$ ,其中 $j>i$ 继续遍历，计算$tmp=min(height[i],height[j])*(j-i)$,表示两个高度的较小值乘两个高度的索引差(宽).保留最大的面积.
时间复杂度过高，超出时间限制.
### 复杂度分析

 - 时间复杂度：$O\left(n^{2}\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        n=len(height)
        max_area=0
        for i in range(n):
            for j in range(i+1,n):
                tmp=min(height[i],height[j])*(j-i)
                max_area=max(tmp,max_area)
        return res
```





## 双指针法
### 算法流程：
分别设置$i,j$为数组的两端，将$height[i],height[j]$中的较小索引朝向较大索引移动。在这个过程中，设置最大面积变量$max\_area$保存最大面积。

### 移动规则合理性：

 - 水池面积$Area(i,j)=min(height[i],height[j])*(j-i)$,即两个高度的较小值乘两个高度的索引差(宽)。
 - 水池面积由宽和高决定，更长的宽和更高的高可使面积变大。试想，$i,j$向内缩一步，导致宽度-1，会导致:
   ***若向内移动的是短板，水池的短板 $min(h[i],h[j])$不变或变大，因此水池面积 $Area(i,j)$可能增大**。
   ***若向内移动的是长板，水池的短板 $min(h[i],h[j])$不变或变小，水池的面积一定小于当前水池面积**。
综上，始终向内移动较短索引。
 




### 复杂度分析

 - 时间复杂度：$O\left(n\right)$，一次扫描
 - 空间复杂度：$O\left(1\right)$，不借助额外空间

### Python

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area=0
        i=0
        j=len(height)-1
        while(i<j):
            tmp=min(height[i],height[j])*(j-i)
            max_area=max(tmp,max_area)
            if(height[i]>=height[j]):
                j-=1
            else:
                i+=1
        return max_area
```

