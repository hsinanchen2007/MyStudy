### 解题思路

- 典型的快慢指针，for循环内有while循环
- 初始化变量，cnt=0，min_len=MAX（这里使用比s长度大1）
- 先扫描t，建立字典，存储字符和出现次数的对应关系
- 快指针扫描字符串，当遇到t的字符时，消耗掉1个字典对应字符的次数
    - 这个次数如果降到0，表示该字符被消耗完了，cnt+=1
    - 判断是否全部的t的字符都消耗掉了
    - 注意：这个次数是有可能降到负数的，但是只对降到0这一次进行处理
    - 此时子串内包含了全部t的字符，然后开始移动慢指针以缩小子串
        - 如果慢指针的字符在t内，则增加字典对应字符的次数
        - 如果这个字符次数>0，则需要cnt-=1，这也让慢指针的移动到此为止了

### 代码

```python3
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # - sanity check
        if not t:
            return ''

        # - statistic for t
        t_dict = {}
        for c in t:
            if c not in t_dict:
                t_dict[c] = 0
            t_dict[c] += 1
        
        # - use 2 pointers to solve
        cnt = 0                 # - count of t chars in sub string
        min_len = len(s) + 1    # - min len of sub string
        res = ''                # - result string
        left = 0                # - left pointer, init as 0

        for i,c in enumerate(s):
            # - handle only if c is one of t
            if c not in t_dict:
                continue

            # - note: t_dict[c] could be minor int
            t_dict[c] -= 1
            if t_dict[c] == 0:
                cnt += 1

                # - if chars in t are all in this sub string,
                # - check len of sub string
                while cnt == len(t_dict):
                    # - update res
                    if i - left + 1 < min_len:
                        res = s[left:i+1]
                        min_len = len(res)
                        
                    # - before move left pointer
                    ch = s[left]
                    if ch in t_dict:
                        # - cnt-1 only if t_dict[ch] > 0
                        t_dict[ch] += 1
                        if t_dict[ch] > 0:
                            cnt -= 1

                    # - move left pointer forward 1 step
                    left += 1
                        
        return res
```