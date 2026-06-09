### 解题思路
执行用时 :256 ms, 在所有 Python3 提交中击败了75.32%的用户
内存消耗 :14.3 MB, 在所有 Python3 提交中击败了6.06%的用户

异常曲折的思路：
1. 具体数字没有意义，将劳累的一天记为1，不劳累的一天记为-1，由[9,9,6,0,6,6,9]得到[1,1,-1,-1,-1,-1,1]
2. 我们需要一段时间内劳累的天数大于不劳累的天数，即1的数量大于-1的数量，即一段序列的和大于0
3. 时刻-1到时刻-1的序列和为0，分别计算后续所有时刻到时刻-1的序列和，得到cnt=[0,1,2,1,0,-1,-2,-1]
4. 那么时刻i到时刻j的序列和等于cnt[j]-cnt[i]（实际上由于添加了-1时刻索引都增加了1）
5. 我们需要找一个最长的序列满足时刻i到时刻j的序列和大于0，即从右向左找比时刻j小且距离最远的时刻i，即转化成了单调栈问题，参考“最大宽度坡”问题
### 代码

```python3
class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        temp = []
        for i in hours:
            if i > 8:
                temp.append(1)
            else:
                temp.append(-1)
        for i in range(1, len(temp)):
            temp[i] += temp[i-1]
        temp = [0] + temp

        stk = []
        for i in range(len(temp)):
            if not stk or temp[i] < temp[stk[-1]]:
                stk.append(i)

        max_len = 0
        for i in range(len(temp)-1, -1, -1):
            while stk and stk[-1] >= i:
                stk.pop()
            while stk and temp[stk[-1]] < temp[i]:
                max_len = max(max_len, i-stk[-1])
                stk.pop()

        return max_len
```