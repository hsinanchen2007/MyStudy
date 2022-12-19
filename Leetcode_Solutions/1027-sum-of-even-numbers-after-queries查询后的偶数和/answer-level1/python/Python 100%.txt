### 解题思路
为了提升性能 其实就是在上一次查询结果的基础上 判断 这次要加上去的是奇数还是偶数 对应A数组中的数字当前是奇数还是偶数 就可以在上次查询的基础上以O(1)的时间复杂度完成操作 整体时间复杂度O(n)

### 代码

```python
class Solution(object):
    def sumEvenAfterQueries(self, A, queries):
        """
        :type A: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        answer = []
        lastValue = sum([i for i in A if (i & 1) == 0])
        for q in range(len(queries)):
            #print(q)
            val, index = queries[q][0], queries[q][1]
            if (A[index] & 1) == 0: # target even
                if (val & 1) == 0: # this even 
                    answer.append(lastValue + val)
                    lastValue += val
                else: # this odd
                    answer.append(lastValue - A[index])
                    lastValue -= A[index]
            else:# target odd
                if (val & 1) == 0: # this even 
                    answer.append(lastValue)
                else: # this odd
                    answer.append(lastValue + A[index] + val)
                    lastValue += (A[index] + val)
            A[index] += val
        return answer
```