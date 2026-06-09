### 解法1：一列一列加（竟然通过了。。。）
执行用时 :1672 ms, 在所有 Python3 提交中击败了5.27%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了7.04%的用户

思路：
遍历整个输入（除去头尾）
当前位置储雨值=min(当前位置左侧最大值，当前位置右侧最大值)-当前位置的值
如果大于零则累加
### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        for i in range(1, len(height)-1):
            left_max = max(height[0: i])
            right_max = max(height[i+1:])
            temp = min(left_max, right_max) - height[i]
            if temp > 0:
                ans += temp
        return ans
```
### 解法2：一行一行加（超时）
思路：
temp用来计算当前行相邻两个墙之间的积水量
### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        for i in range(1, len(height)-1):
            left_max = max(height[0: i])
            right_max = max(height[i+1:])
            temp = min(left_max, right_max) - height[i]
            if temp > 0:
                ans += temp
        return ans
```
### 解法3：动态
执行用时 :60 ms, 在所有 Python3 提交中击败了56.93%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了9.56%的用户

思路：
![image.png](https://pic.leetcode-cn.com/1f0fbb30869e4f516b78375df6caa2e6df44fc622bae6c5e9c0a0351a9c9a866-image.png)
雨水=整个面积-红色阴影面积-蓝色引用面积-墙的面积
### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) < 3:
            return 0
        max_height = 0
        cnt_right = 0
        for i in range(len(height)):
            if height[i] > max_height:
                max_height = height[i]
            cnt_right += max_height

        max_height = 0
        cnt_left = 0
        for i in range(len(height)-1, -1, -1):
            if height[i] > max_height:
                max_height = height[i]
            cnt_left += max_height

        ans = cnt_right + cnt_left - len(height) * max(height) - sum(height)
        return ans
```
### 解法4：栈
执行用时 :56 ms, 在所有 Python3 提交中击败了68.56%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了7.04%的用户

思路：
遍历整个数组，将对应索引current入栈stk
当height[current]大于height[stk[-1]]的时候
    在栈中寻找与其匹配的索引(出栈)，并计算current和匹配索引之间的雨水值，并相加
        计算顺序如图：current=3时，匹配到索引1，计算块1的值
                     current=6时，匹配到索引4，计算块2的值
                     current=7时，匹配到索引4，计算得0；匹配到索引3，计算块3的值
                     current=10时，匹配到索引8，计算块4的值
    直至栈空
![image.png](https://pic.leetcode-cn.com/a4a58b3b3905f8b105a2876a6d7abef62545787f6ad5c0a60d3818fcac1b7183-image.png)

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        stk = [0]
        for current in range(1, len(height)):
            while len(stk) > 0 and height[current] > height[stk[-1]]:
                # 先出栈后计算 因为相邻的两堵墙不可能存雨水
                top = stk.pop(-1)
                # 栈空了 current对应的墙和栈中所有匹配墙之间的雨水计算结束
                if len(stk) == 0:
                    break
                # 这里是依照图片所示一大块一大块计算的
                bounded = min(height[current], height[stk[-1]]) - height[top]
                cnt = bounded * (current - stk[-1] - 1)
                ans += cnt
            stk.append(current)
        return ans
```