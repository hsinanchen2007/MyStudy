- 时间复杂度O(N)
- 空间复杂度O(1)，使用了三个变量  

只需要维护左边数组的变量tmp，但是tmp并**不是实时存放遍历过的最大值**，也就是说我们会用另外一个变量m记录遍历过的最大值；  
遍历过程：  
初始化tmp为A[0]，遍历A，当有元素小于tmp时，表示该位置可能是分界点，记录该位置到pos；  将tmp更新为当前的最大值m，继续遍历，当遍历结束，pos即是分界点的位置
```
class Solution:
    def partitionDisjoint(self, A):
        tmp,pos,m = A[0],0,A[0]
        for i in range(1,len(A)):
            m = max(m,A[i])
            if A[i]<tmp:
                pos = i
                tmp = m
        return pos+1
```
再多说几句：  
这样更新tmp可以保证tmp存放的是左边数组的最大值，如果每次更新的话，得到的最大值不能保证属于左边数组，可能是属于右边数组的