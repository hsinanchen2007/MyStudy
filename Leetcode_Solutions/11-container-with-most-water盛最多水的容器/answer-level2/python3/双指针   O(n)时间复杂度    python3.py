### 解题思路
定义头列表的头指针和尾指针
计算头指针和尾指针之间的面积，如果该面积大于当前最大值，则更新最大值
如果头指针所指向元素的值大于尾指针所指向的值，尾指针减一，continue
如果尾指针所指向元素的值大于头指针所指向的值，尾指针加一，continue（因为面积总被较短的那个值所限制）
如果头指针等于尾指针，跳出循环

![盛水.png](https://pic.leetcode-cn.com/9ab34085eeb6b9d9c2a8c3e6dcd5b03f473722249a6c0b3c4af11b4406e95df8-%E7%9B%9B%E6%B0%B4.png)

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxw = 0
        head = 0
        tail = len(height)-1
        while head < tail:
            if (tail-head)*min(height[tail], height[head]) > maxw:
                maxw = (tail-head)*min(height[tail], height[head])
            if height[head] > height[tail]:
                tail -= 1
            else:
                head += 1
        return maxw
```