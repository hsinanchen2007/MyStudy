### 解题思路
- 遍历B数组，每个B元素与A中前m个元素逐个比较，其他的是缓存不要比较
- 如果B元素小于A元素，则在当前位置插入，同时pop()操作去掉一个缓存；记得m+1(此时应认为A的有效长度为m+1)
- 如果前m个都不小于A，则将A[m]缓存替换成B元素，别忘了m+1

### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        if m==0:
            A[:]=B    
 
        for num_B in B:
            for cur_index in range(0,m):
                if num_B <= A[cur_index]:
                    A.insert(cur_index,num_B)
                    A.pop()
                    m=m+1
                    break
                if cur_index==m-1:
                    A[m]=num_B
                    m+=1

   
```