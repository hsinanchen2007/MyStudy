### 解题思路
两个方法速度差不多，内存消耗双指针稍微少0.3MB左右，相差不大！

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        # Soultion 1: 两次遍历
        # res = [0] * len(A)
        # i = 0
        # for a in A:
        #     if a % 2 == 0:
        #         res[i] = a
        #         i += 2
        # i = 1
        # for a in A:
        #     if a % 2 != 0:
        #         res[i] = a 
        #         i += 2
        # return res

        # Solution 2: 双指针:在找到一个偶数位是奇数的前提下,找奇数位上的偶数,找到之后在交换.
        j = 1
        for i in range(0, len(A), 2):
            if A[i] % 2 == 1:
                while A[j] % 2 == 1:
                    j += 2
                A[i], A[j] = A[j], A[i]
        return A
```