### 解题思路

height - argmax(rowsum_factor.cnt)

### 代码

```python3
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        sum_list = []
        for row in wall:
            sum = 0
            for _ in row:
                sum = sum + _
                sum_list.append(sum)
        result = collections.Counter(sum_list)
        cnt = result.most_common(2)
        if len(cnt) == 1 :
            return len(wall)
        else:
            pass_row = cnt[0][1] if cnt[0][0] < cnt[1][0] else cnt[1][1]
            return len(wall) - pass_row

```

执行用时 :
216 ms
, 在所有 Python3 提交中击败了
76.28%
的用户
内存消耗 :
18 MB
, 在所有 Python3 提交中击败了
78.57%
的用户