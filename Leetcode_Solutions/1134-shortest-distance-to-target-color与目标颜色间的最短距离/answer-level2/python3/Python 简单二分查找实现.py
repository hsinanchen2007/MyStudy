![image.png](https://pic.leetcode-cn.com/e4de3d14a1abea62ee9a67b92dc2ca7e6af7e1bd48fe1b6af61c630945ec8bf3-image.png)


```
'''
保存每种颜色出现的位置列表，然后进行二分搜索
'''

from typing import List
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        n = len(colors)
        pos1 = [i for i in range(n) if colors[i] == 1]
        pos2 = [i for i in range(n) if colors[i] == 2]
        pos3 = [i for i in range(n) if colors[i] == 3]
        pos_list = [None, pos1, pos2, pos3]

        ret = []
        for target, color in queries:
            arr = pos_list[color]

            l, r = 0, len(arr)-1
            ans = -1
            ans_idx = -1
            while l <= r:
                mid = l + (r - l) // 2
                if arr[mid] >= target:
                    ans = arr[mid]
                    ans_idx = mid
                    r = mid - 1
                else:
                    l = mid + 1

            if ans == -1:
                if len(arr) > 0:
                    ret.append(abs(arr[-1] - target))
                else:
                    ret.append(-1)
            elif ans == target:
                ret.append(0)
            else:
                val = abs(target - ans)
                if ans_idx-1 >= 0:
                    val = min(val, target - arr[ans_idx-1])
                ret.append(val)

        return ret
```
