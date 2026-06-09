### 解题思路
最初思路是每修改一次数组再算出偶数和，提交后超出时间限制
之后转换了思路，先算出原数组的偶数，进行两次修改位置数字的奇偶判断，
第一次判断即将要修改的数组位置是否为偶数，若为偶数则在之前的偶数和上减去（避免之后的重复加减），
第二次判断修改后的数是否为偶数，若是则偶数和加上此数，若不是加入列表

### 代码

```python3
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        answer = []
        oushuhe = sum([v for v in A if v%2==0])     #首先算出原数组的偶数和
        for i,j in queries:
            if A[j]%2 == 0:oushuhe -= A[j]          #第一次判断原位置的奇偶性
            A[j] = A[j] + i
            if A[j]%2 == 0:                         #第二次判断修改后位置的奇偶性
                oushuhe += A[j]
                answer.append(oushuhe)
            else:
                answer.append(oushuhe)
        return answer
```