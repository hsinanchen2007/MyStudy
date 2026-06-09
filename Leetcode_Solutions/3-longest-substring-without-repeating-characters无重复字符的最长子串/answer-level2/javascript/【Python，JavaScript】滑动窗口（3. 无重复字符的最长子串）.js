

## 思路

用一个 hashmap 来建立字符和其出现位置之间的映射。

维护一个滑动窗口，窗口内的都是没有重复的字符，去尽可能的扩大窗口的大小，窗口不停的向右滑动。

（1）如果当前遍历到的字符从未出现过，那么直接扩大右边界；

（2）如果当前遍历到的字符出现过，则缩小窗口（左边索引向右移动），然后继续观察当前遍历到的字符；

（3）重复（1）（2），直到左边索引无法再移动；

（4）维护一个结果 res，每次用出现过的窗口大小来更新结果 res，最后返回 res 获取结果。



## 关键点

1. 用一个 mapper 记录出现过并且没有被删除的字符
2. 用一个滑动窗口记录当前 index 开始的最大的不重复的字符序列
3. 用 res 去记录目前位置最大的长度，每次滑动窗口更新就去决定是否需要更新 res

## 代码

代码支持：JavaScript，Python3

JavaScript Code:

```js
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  const mapper = {}; // 记录已经出现过的charactor
  let res = 0;
  let slidingWindow = [];

  for (let c of s) {
    if (mapper[c]) {
      // 已经出现过了
      // 则删除
      const delIndex = slidingWindow.findIndex(_c => _c === c);

      for (let i = 0; i < delIndex; i++) {
        mapper[slidingWindow[i]] = false;
      }

      slidingWindow = slidingWindow.slice(delIndex + 1).concat(c);
    } else {
      // 新字符
      if (slidingWindow.push(c) > res) {
        res = slidingWindow.length;
      }
    }
    mapper[c] = true;
  }
  return res;
};
```

Python3 Code:

```python
from collections import defaultdict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        ans = 0
        counter = defaultdict(lambda: 0)

        for r in range(len(s)):
            while counter.get(s[r], 0) != 0:
                counter[s[l]] = counter.get(s[l], 0) - 1
                l += 1
            counter[s[r]] += 1
            ans = max(ans, r - l + 1)

        return ans
```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)