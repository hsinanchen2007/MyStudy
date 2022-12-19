### 解题思路
执行用时 :360 ms, 在所有 Python3 提交中击败了81.60%的用户
内存消耗 :20.4 MB, 在所有 Python3 提交中击败了12.50%的用户

1. 从左向右生成单调递减栈的时候注意：栈底元素是A的第一个元素，栈顶元素时A的最小值
2. 从右向左计算最大宽度时候注意：栈顶元素不大于当前元素索引
3. 因为栈顶索引对应元素是整个数组的最小值，最大宽度>=数组最后一个元素索引-栈顶元素，所以搜索到数组倒数第二个元素到栈顶元素的宽度不可能是最大宽度，因此栈顶元素可以在搜索完数组最后一个元素后出栈而不会影响之后从右向左的搜索计算
### 代码

```python3
class Solution:
    def maxWidthRamp(self, A: List[int]) -> int:
        # 从左向右生成单调递减栈 栈底元素是A的第一个元素 栈顶元素时A的最小值
        stk = []
        for i in range(len(A)):
            if not stk or A[stk[-1]] > A[i]:
                stk.append(i)

        # 从右向左计算最大宽度
        max_len = 0
        for i in range(len(A)-1, 0, -1):
            while stk:
                if stk[-1] > i:
                    stk.pop()
                else:
                    if A[i] >= A[stk[-1]]:
                        max_len = max(i - stk[-1], max_len)
                        stk.pop()
                    else:
                        break
        return max_len
        
```