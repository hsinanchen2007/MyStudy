### 解题思路
定义： 单调栈就是栈内元素递增或者单调递减的栈，并且只能在栈顶操作。单调栈的维护是O(n)的时间复杂度，所有元素只会进进栈一次

性质：
1. 单调栈里面的元素具有单调性；
2. 元素加入栈前会把栈顶破坏单调性的元素删除；
3. 使用单调栈可以找到元素向左遍历的第一个比他小的元素（单增栈），也可以找到元素向左遍历第一个比他大的元素（单减栈）；
4. 一般使用单调栈的题目具有以下的两点：
5. 离自己最近（栈的后进先出的性质）
6. 比自己大（小）、高(低)；


### 代码

```python3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d, stack = {}, []

        for num in nums2:
            while stack and num > stack[-1]:
                d[stack.pop()] = num
            stack.append(num)
        
        return [d.get(item, -1) for item in nums1]
```