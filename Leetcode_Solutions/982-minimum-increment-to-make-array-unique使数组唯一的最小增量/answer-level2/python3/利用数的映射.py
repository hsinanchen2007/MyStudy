### 解题思路
将列表空间开辟到题目限制的两倍(原因就算每个数都为40000递增最多到80000)所以开辟两倍
然后用哈希表的方法，若某个数的统计个数B[i]不为1则Min_Operation +=B[i]-1,则i+1的数目为B[i]-1
依次类推到数组尾部为止

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        B = [0]*80003
        for i in A:
        	B[i] +=1
        i =0
        Min_count=0
        while i<80002:
        	if B[i] >1:
        		Min_count +=B[i]-1
        		B[i+1] +=B[i]-1
        		B[i] =1
        	else:
        		pass
        	i +=1
        return(Min_count)
```