### 解题思路
维护一个单调非递增栈，当遇到一个比栈顶元素的高度还要高的值时，说明之前有一个洼地能存储雨水。
每次存储的量为（栈顶元素左右两边高度的最小值-栈顶元素的高度）*左右两边的距离

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        stack=[]
        res=0
        for i,v in enumerate(height):
            while stack and v>height[stack[-1]]:
                t=stack.pop()
                if not stack:
                    break
                left=stack[-1]
                res+=(min(v,height[left])-height[t])*(i-left-1)
            stack.append(i)
        return res
```