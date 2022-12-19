### 解题思路
方案一：
本题本质还是找最小值，那么我们首先考虑通用的做法，朴素的分治法。
此代码适用任何情况（即使数组是乱序的也可以用这个通用解法）的求最小值，并没有利用本身的数据特点
代码如下：
### 代码

```python3
#朴素分治法
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        def findmin(numbers,left,right):
            if left>=right:
                return numbers[left]
            if right-left==1:
                return min(numbers[right],numbers[left])
            mid = (left+right)//2
            min_left = findmin(numbers,left,mid)
            min_right = findmin(numbers,mid+1,right)
            return min(min_left,min_right)
        re = findmin(numbers,0,len(numbers)-1)
        return re
        


```
方案二：
既然题目还有数组部分有序的条件，我们就可以把这个条件加入我们朴素分治代码里。
加入条件即意味着对朴素分治法的“剪枝”。
当mid的值比右边小，显然从mid到right都不会有最小值，right=mid
当mid的值比右边打，显然从left到mid都不会有最小值，left=mid
这种方法妙就妙在我们不需要斤斤计较边界条件（因为分治法已经保证了能够得到正确结果，“剪枝”只作为锦上添花），例如上面的mid=right的情况，从而避开了复杂的分析边界情形。


```
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        def findmin(numbers,left,right):
            if left>=right:
                return numbers[right]
            if right-left==1:
                return min(numbers[right],numbers[left])

            mid = (left+right)//2
            if numbers[mid]<numbers[right]:
                right=mid
            if numbers[mid]>numbers[right]:
                left=mid

            min_left = findmin(numbers,left,mid)
            min_right = findmin(numbers,mid+1,right)
            return min(min_left,min_right)
        re = findmin(numbers,0,len(numbers)-1)
        return re
```


        