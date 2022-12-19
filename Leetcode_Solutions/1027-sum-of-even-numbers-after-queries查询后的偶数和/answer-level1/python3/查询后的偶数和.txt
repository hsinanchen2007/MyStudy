### 解题思路
我的思路1 - 超时：考察数组的遍历，若A的长度为m，queries的长度为n。
	超出时间限制

复杂度分析：                                                             
	• 时间复杂度：o(m*n)
	• 空间复杂度：o(1)

我的思路2：把A的遍历查抽离出来，对变化的A中的某个数进行判断，然后求sums即可，直接看代码叭
	

复杂度分析：                                                                        
	• 时间复杂度：o(n)
	• 空间复杂度：o(1)



### 代码
思路一：
```python
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        answer = []
        sums = 0
        for q in queries:
            A[q[1]] += q[0]
            for x in A:
                if x % 2 == 0:
                    sums += x
            answer.append(sums)
            sums = 0
        return answer

```

思路二：

```python
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        answer = []
        sums = 0
        for x in A:
            if x % 2 == 0:
                sums += x
        pre_a = 0
        for q in queries:
            pre_a = A[q[1]]
            A[q[1]] += q[0]
            if abs(pre_a%2) == 1 and abs(A[q[1]]%2) == 0:
                sums += A[q[1]]
            elif abs(pre_a%2) == 0 and abs(A[q[1]]%2) == 1:
                sums -= pre_a
            elif abs(pre_a%2) == 0 and  abs(A[q[1]]%2) == 0:
                sums += q[0]
            answer.append(sums)
        return answer
```