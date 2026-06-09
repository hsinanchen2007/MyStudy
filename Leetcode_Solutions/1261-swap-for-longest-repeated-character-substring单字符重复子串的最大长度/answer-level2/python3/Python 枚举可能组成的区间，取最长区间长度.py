![image.png](https://pic.leetcode-cn.com/287d1ed0a9546c72fec557dba43782e350e6e6b33bcb55abddf886ae5904de80-image.png)


```

'''
枚举每一个字符对应的区间列表，
从左到右遍历区间，检查区间能否和后一个区间连在一起
取所有能够组成的区间长度最大值作为答案
'''

class Solution:
    def maxRepOpt1(self, text: str) -> int:
        m = {}  # 每个字符出现的连续区间
        ans = 0

        cur_ch = text[0]
        start = 0
        for i in range(len(text)+1):
            ch = text[i] if i != len(text) else None
            if i == len(text) or ch != cur_ch:
                if cur_ch not in m:
                    m[cur_ch] = []
                m[cur_ch].append((start, i-1))
                ans = max(ans, i-1-start+1)

                cur_ch = ch
                start = i

        n = len(text)
        for r_list in m.values():
            if len(r_list) == 1:
                continue
            if len(r_list) == 2:
                if r_list[1][0] - r_list[0][1] == 2:
                    # 两个区间相差1个空位，可以交换一次把两个接起来
                    ans = max(ans, (r_list[0][1]-r_list[0][0] + 1) + (r_list[1][1]-r_list[1][0] + 1))
                else:
                    # 接不起来，移动一次，让较长的区间长度增加1
                    ans = max(ans, 1 + max((r_list[0][1]-r_list[0][0] + 1), (r_list[1][1]-r_list[1][0] + 1)))

            else:
                # 枚举每一个区间，要么跟后面一个区间连起来了，要么就交换一次，让自己的长度增加1
                for i in range(0, len(r_list)):
                    ans = max(ans, r_list[i][1] - r_list[i][0] + 1 + 1)
                    if i < len(r_list) - 1 and r_list[i+1][0] - r_list[i][1] == 2:
                        ans = max(ans, (r_list[i][1]-r_list[i][0] + 1) + (r_list[i+1][1]-r_list[i+1][0] + 1) + 1)

        return ans
```
