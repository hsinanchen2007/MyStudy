### 解题思路
执行用时 :44 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :15.3 MB, 在所有 Python3 提交中击败了14.01%的用户

思路：
1. 找每个高度对应的最大矩形面积：这个高度对应的宽度等于左右两侧第一个高度小于此高度的位置之间的长度
3. 所以对一个位置来说，所有位于这个位置左侧的，比此位置高的高度对应的最大矩形面积都可以计算出来
4. 最左右两侧分别添加高度为0的柱子，则所有原来的柱子都比0高，对应最大矩形面积均可计算出来
4. 因此，从左向右依次将高度对应的索引入栈
5. 当当前高度小于栈顶索引对应高度的时候，栈内对应告诉大于当前高度的索引依次出栈，计算对应最大矩形面积
![image.png](https://pic.leetcode-cn.com/cb6abc19b5afa9c08c6ed66a3e5d8d5d4150e01024481cce440ee41070cdb5ac-image.png)

### 代码

```python3
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights = [0] + heights + [0]  # 哨兵
        max_squ = 0
        stk = []
        for i in range(len(heights)):
            while stk and heights[i] < heights[stk[-1]]:
                h = heights[stk.pop()]  # 出栈
                while stk and heights[stk[-1]] == h:
                    stk.pop()
                w = i - stk[-1] - 1
                max_squ = max(h*w, max_squ)
            stk.append(i)
        return max_squ          
```
### 解题思路
官方暴力法的优化：Python3超时

思路：
两个指针i和j，计算以i和j为两端的宽度对应的最大矩形面积

### 代码

```python3
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_squ = 0
        for i in range(len(heights)):
            max_h = heights[i]
            for j in range(i, len(heights)):
                w = j - i + 1
                max_h = min(max_h, heights[j])
                max_squ = max(max_h*w, max_squ)
        return max_squ        
```