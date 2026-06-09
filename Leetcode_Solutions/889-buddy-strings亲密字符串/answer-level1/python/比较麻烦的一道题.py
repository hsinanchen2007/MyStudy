### 解题思路
这道题需要考虑四种情况：A和B长度不等、A和B完全一致，需要进一步判断里面有两个相同元素、A和B只有一个位置的元素不同、A和B有两个位置的元素不同，需要进一步判断是否交换后一致

### 代码

```python3
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        temp1, temp2, temp3 = '', '', ''
        if len(A) != len(B):
            return False
        if A == B:
            set_ = {}
            for i in range(len(A)):
                if A[i] not in set_:
                    set_[A[i]] = 1
                else:
                    return True
        for i in range(len(A)):
            if A[i] != B[i]:
                if temp1 == '':
                    temp1 = B[i]
                    temp3 = A[i]
                elif temp2 == '':
                    temp2 = B[i]
                    if temp1 != A[i] or temp2 != temp3:
                        return False
                else:
                    return False
        if temp1 == '' or (temp1 != '' and temp2 == ''):
            return False
        return True

```