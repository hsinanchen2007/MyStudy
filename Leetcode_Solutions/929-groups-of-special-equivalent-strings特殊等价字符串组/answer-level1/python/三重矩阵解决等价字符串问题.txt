### 解题思路
考虑到等价字符串主要看奇偶位字符数量，考虑使用三重矩阵。最内层是两个dictionary

### 代码

```python3
class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        count = 0
        set_ = [[{},{}] for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(A[i])):
                if j % 2 == 0:
                    if A[i][j] not in set_[i][0]:
                        set_[i][0][A[i][j]] = 1
                    else:
                        set_[i][0][A[i][j]] += 1
                else:
                    if A[i][j] not in set_[i][1]:
                        set_[i][1][A[i][j]] = 1
                    else:
                        set_[i][1][A[i][j]] += 1
        temp = []
        for i in range(len(A)):
            if set_[i] not in temp:
                temp.append(set_[i])
                print(set_[i])
                count += 1
        return count
```