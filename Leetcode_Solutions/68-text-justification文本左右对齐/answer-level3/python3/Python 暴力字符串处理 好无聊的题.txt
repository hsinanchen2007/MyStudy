![image.png](https://pic.leetcode-cn.com/c5897649633817e2e9110edf741fa3b04b74234a462d68e795810883ac183b59-image.png)



```
'''
字符串处理，注意统计间隔的空格个数即可
'''

from typing import List
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        i = 0

        ans = []
        while i < len(words):
            len_cnt = len(words[i])
            cnt = len(words[i])
            j = i+1
            while j < len(words):
                if len_cnt + 1 + len(words[j]) > maxWidth:
                    break

                len_cnt += 1 + len(words[j])
                cnt += len(words[j])
                j += 1

            space_cnt = maxWidth - cnt
            word_cnt = j - i
            if word_cnt == 1:
                ans.append(words[i] + ' ' * space_cnt)
                i = j
                continue

            # 间隔的空格个数
            space_num, extra_space_num = space_cnt // (word_cnt-1), space_cnt % (word_cnt-1)

            w = words[i]
            if j != len(words):
                for idx in range(i+1, j):
                    w += ' ' * space_num
                    if extra_space_num > 0:
                        extra_space_num -= 1
                        w += ' '
                    w += words[idx]
            else:
                for idx in range(i+1, j):
                    w += ' '
                    w += words[idx]
                w += ' ' * (maxWidth - len(w))

            ans.append(w)

            i = j

        return ans
```
