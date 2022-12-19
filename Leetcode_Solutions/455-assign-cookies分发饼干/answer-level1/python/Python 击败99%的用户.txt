![微信截图_20200118111332.png](https://pic.leetcode-cn.com/07c4d6b3bd33fde83467c835cb7a61d15484ffded8d31933bd0ad8dd8d06a630-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200118111332.png)

思路：将孩子胃口和饼干大小做升序排序，遍历饼干，优先把饼干满足胃口小的孩子

```

class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        #将孩子胃口从小到大排序
        g.sort()
        #将饼干从小到大排序
        s.sort()
        ret = 0
        g_index = 0
        s_index = 0
        while g_index < len(g):
            while s_index < len(s):
                if s[s_index] >= g[g_index]:
                    ret += 1
                    s_index += 1
                    break
                else:
                    s_index += 1
            g_index += 1
        return ret

```
