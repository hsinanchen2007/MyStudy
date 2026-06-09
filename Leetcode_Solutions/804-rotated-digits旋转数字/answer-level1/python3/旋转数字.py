### 解题思路
好数的标准：
1. 不包含347中任意一个
2. 可以包涵任意个数2569
3. 可以包涵任意个数个018
如果是好数，则累计，返回最终好数个数

all(iterable)：iterable -- 元组或列表。如果iterable的所有元素不为0、''、False或者iterable为空，all(iterable)返回True，否则返回False；
all(d not in '347' for d in S)：如果S里每一位都不在347里，则返回True（1）
any(d in '2569' for d in S)：如果S里有任意一位在2569里，则返回True（1）

对上述两个结果做and操作，都为真的情况下，and的结果是1；
ans累计好数个数

疑问：如果某数只包涵2569呢？反转后不就是相同的数吗？如何体现这个判断？


### 代码

```python3
class Solution:
    def rotatedDigits(self, N: int) -> int:
        ans = 0
        for x in range(1, N+1):
            S = str(x)
            ans += (all(d not in '347' for d in S) and any(d in '2569' for d in S))
        return ans
#作者：LeetCode

            

                
             

```