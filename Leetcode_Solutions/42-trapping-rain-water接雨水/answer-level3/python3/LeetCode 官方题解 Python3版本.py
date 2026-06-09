参考官方题解，写了对应了四种方法的python3版本。

- 方法一：暴力破解法的实现：

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        length = len(height)
        i = 1
        while i < length - 1:  
            max_left, max_right = 0, 0
            j = i
            while j >= 0:  # 寻找i位置左边最大bound
                max_left = max(max_left, height[j])
                j -= 1  # j一个一个的减到0
            j = i
            while j < length:  # 寻找i位置右边最大bound
                max_right = max(max_right, height[j])
                j += 1  # j一个一个的加到length
            ans += min(max_left, max_right) - height[i]
            i += 1
        return ans
```
时间复杂度： $O(n^2)$。数组中的每个元素都需要向左向右扫描。
空间复杂度 $O(1)$ 的额外空间。
通过测试用例314 / 315 个，最后一个用例，长度为10732，未能通过。



- 方法二：动态规划法的实现

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        if length == 0:  # 特判height为空的情况，直接返回0。
            return 0

        ans = 0  # 声明ans、left_max、right_max等变量
        left_max = [0] * length
        right_max = [0] * length

        # 从左往右边寻找每个位置的left_max
        left_max[0] = height[0]
        i = 1
        while i < length:
            left_max[i] = max(height[i], left_max[i - 1])
            i += 1
        
        # 从右往左寻找每个位置的right_max
        right_max[length - 1] = height[length - 1]
        i = length - 2
        while i >= 0:
            right_max[i] = max(height[i], right_max[i + 1])
            i -= 1

        # 利用left_max和right_max计算容量
        i = 1
        while i < length - 1:
            ans += min(left_max[i], right_max[i]) - height[i]
            i += 1

        return ans

```

时间复杂度：$O(n)$，存储最大高度数组，需要两次遍历，每次 $O(n)$ 。最终使用存储的数据更新$\text{ans}$ ，$O(n)$。
空间复杂度：$O(n)$ ，额外空间。和方法 1 相比使用了额外的 $O(n)$ 空间用来放置$\text{left_max}$ 和 $\text{right_max}$ 数组。
执行用时 :80 ms, 在所有 Python3 提交中击败了26.42%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了28.11%的用户



- 方法三：基于栈的方法实现

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        ans, current = 0, 0  # 声明ans、current变量来保存结果和游标位置
        st = []  # st里面保存的是位置下标
        length = len(height)
        while current < length:
            while len(st) and height[current] > height[st[-1]]:  # 当st不为空且当前条块高度大于st中最后一个下标所对应条块的高度时，就形成了一个洼地，可以计算洼地存雨多少了。
                top = st[-1]  # 先获得中间条块的下标
                st.pop()  # 再弹出中间条块，这时st[-1]所对应的条块，就变成了洼地的左边界。
                if len(st) == 0:  # 如果st为空了，说明这个洼地计算完成了。
                    break
                distance = current - st[-1] - 1  # 计算底边
                bound_height = min(height[current], height[st[-1]]) - height[top]  # bound_height可能为0，只有st通过pop回退到一定位置（也就是不断左移左边界），才能有min(height[current], height[st[-1]])>height[top]，此时才能得到一个有效的bound_height。而distance也会因为st通过pop回退到一定位置（也就是不断左移左边界）而变大。
                ans += distance * bound_height  # ans可以会因为bound_height为0而为0。当bound_height有效时，ans也会最终加上一个有效值。
            st.append(current)  # 把当前最新下标保存进去
            current += 1  # 先保存再自增

        return ans
```

时间复杂度：$O(n)$。单次遍历 $O(n)$ ，每个条形块最多访问两次（由于栈的弹入和弹出），并且弹入和弹出栈都是 $O(1)$ 的。
空间复杂度：$O(n)$。 栈最多在阶梯型或平坦型条形块结构中占用 $O(n)$ 的空间。
执行用时 :64 ms, 在所有 Python3 提交中击败了52.06%的用户
内存消耗 :14 MB, 在所有 Python3 提交中击败了28.11%的用户



- 方法四：基于双指针方法的实现

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        ans, left, right = 0, 0, len(height) - 1
        left_max, right_max = 0, 0
        while left < right:
            if height[left] < height[right]:  # 满足该条件，即，left更小，以left为有效bound_height。
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    ans += (left_max - height[left])  # 每次就计算一个位置对应能够积累的水珠数量就行了。
                left += 1
            else:  # 否则right更小，以right为有效bound_height。
                if height[right] >= right_max:  # 
                    right_max = height[right]
                else:
                    ans += (right_max - height[right])  # 同样，只用计算一个位置对应能够积累的水珠数量。
                right -= 1
        return ans
```
时间复杂度：$O(n)$，单次遍历的时间O(n)。
空间复杂度：$O(1)$ ，`left, right,  left_max 和 ight_max` 只需要常数的空间。
执行用时 :32 ms, 在所有 Python3 提交中击败了99.55%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了28.30%的用户