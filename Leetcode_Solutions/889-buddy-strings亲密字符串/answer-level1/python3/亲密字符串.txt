### 解题思路
咋感觉是面向测试用例编程...

交换且仅交换一次A中的两个字母；

### 代码

```python3
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) == 0 or len(B) == 0:  # 示例5的情况：A或B为空
            return False
    
        if sorted(A) != sorted(B):   # 排除了字母不同的，和长度不同的情况
            return False

        if len(A) == len(set(A)):   # 示例2的情况：如果每一个字母都是唯一一次出现，A和B相等，则不可能A中字母交换后可以得到B
            if A == B:
                return False

        diff = 0
        for i in range(len(A)):
            if A[i] != B[i]:
                diff += 1
        
        if diff > 2:
            return False
        else:
            return True

```