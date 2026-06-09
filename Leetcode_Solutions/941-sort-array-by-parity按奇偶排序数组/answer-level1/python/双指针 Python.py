思路：双指针，时间复杂度O(n),空间复杂度O(1)。优化，在需要前后指针需要交换时，判断后指针执行的对象是否是偶数，如果不是，后指针向前移动，直到遇到偶数，或与前指针重合。这样可以减少对比和移动。例如：[2,4,6,8,10]，普通双指针需要移动，而改进后的方法无需移动。


```
class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        i,j=0,len(A)-1
        while i!=j:
            if not A[i]&1:
                i+=1
                continue
            if not A[j]&1:
                A[i],A[j]=A[j],A[i]
            j-=1
        return A
            
```
