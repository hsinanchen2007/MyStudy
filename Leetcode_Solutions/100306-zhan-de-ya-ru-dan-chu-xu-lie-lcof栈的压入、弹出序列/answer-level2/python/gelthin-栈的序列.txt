### 解题思路
纯自己写的代码，写得磕磕巴巴，可能不太好。写的过于复杂。
本质上还是同[主站 946 题](https://leetcode-cn.com/problems/validate-stack-sequences/)的官方题解，贪心做法。
只能处理栈中各个元素都不同的情形，例如 
[1,2,4,3,2] [2,3,4,2,1] 无法解决。




题解中[一个找规律的解法](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/zhao-gui-lu-by-xixihahag/)还不错， 可以往后跳，但不能越过还未pop 的数字往前跳动，

### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if pushed == [] and popped == []:
            return True
        if len(pushed) != len(popped):
            return False
        
        stack = []
        n = len(pushed)
        i, j = 0, 0
        while True:
            if stack and stack[-1] == popped[j]:
                j += 1
                stack.pop()
                if j == n:
                    return True
            else:
                while i<n and j<n and pushed[i] != popped[j]:
                    stack.append(pushed[i])
                    i += 1
                if i<n and pushed[i] == popped[j]: # 找到了这个数，i,j 各自前进一位
                    i += 1  
                    j += 1
                    if i==n and j==n:
                        return True
                else: # 遍历完了 pushed[] 仍然找不到， 说明这个数可能在之前就进了 stack, 序列不对。
                    return False

```