![image.png](https://pic.leetcode-cn.com/c515410b90b133aba24b28aa245977064cc9c3d4fa0d16041ce6c22c769668f4-image.png)

```py
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        d = {c: i for i, c in enumerate(S)} #记录字母最后出现的坐标
        ans, l, r = [], 0, 0
        for i, c in enumerate(S):   #遍历字母
            if d[c] > r:
                r = d[c]            #不断更新[l, r]区间里字母的最远坐标
            if i == r:              #如果区间内所有字母的最远坐标都不超过r，就输出
                ans += [r - l + 1]
                l = i + 1           #更新区间左侧坐标
        return ans
```
