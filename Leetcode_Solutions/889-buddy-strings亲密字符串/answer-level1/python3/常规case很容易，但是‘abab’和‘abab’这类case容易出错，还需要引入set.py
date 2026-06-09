### 解题思路
常规case很容易，但是‘abab’和‘abab’这类case容易出错，还需要引入set

### 代码

```python3
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        len_A = len(A)
        len_B = len(B)

        if len_A != len_B or len_A < 2:
            return False

        val_A = ''
        val_B = ''
        diff_count  = 0
        has_same_ch = False
        ch_set = set()
        for index in range(len_A):
            if has_same_ch == False:
                if A[index] in ch_set:
                    has_same_ch = True
                else:
                    ch_set.add(A[index])
            if A[index] != B[index]:
                diff_count += 1
                if diff_count > 2:
                    return False
                if val_A == val_B:
                    val_A = A[index]
                    val_B = B[index]
                else:
                    if val_A != B[index] or val_B != A[index]:
                        return False
        
        if diff_count == 0:
            return has_same_ch

        return not(diff_count%2)

```