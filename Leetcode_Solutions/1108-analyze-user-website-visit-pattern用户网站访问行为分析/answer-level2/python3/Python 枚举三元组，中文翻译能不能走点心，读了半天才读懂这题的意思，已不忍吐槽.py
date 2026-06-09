

```
'''
枚举可能出现的三元组，求取三元组最多同时在多少个用户的访问序列中出现
'''

from typing import List
class Solution:


    def isMatch(self, l1, l2):
        if len(l1) > len(l2):
            return False

        l1 = [x[1] for x in l1]
        l2 = [x[1] for x in l2]

        i, j = 0, 0
        while i < len(l1) and j < len(l2):
            target = l1[i]
            while j < len(l2) and l2[j] != target:
                j += 1

            if j < len(l2) and l2[j] == target:
                i += 1
                j += 1
            else:
                return False
        return i == len(l1)

    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        m = {}
        for user, time, web in zip(username, timestamp, website):
            if user not in m:
                m[user] = []
            m[user].append((time, web))

        for web_list in m.values():
            web_list.sort(key=lambda x : x[0])

        user_list = list(m.keys())
        max_match_cnt = 0
        ans = None
        for i in range(len(user_list)):
            web_list = m[user_list[i]]

            # 枚举三元组
            for ii in range(0, len(web_list)):
                for jj in range(ii+1, len(web_list)):
                    for kk in range(jj+1, len(web_list)):
                        target = [web_list[ii], web_list[jj], web_list[kk]]

                        match_cnt = 1
                        for j in range(i+1, len(user_list)):
                            if self.isMatch(target, m[user_list[j]]):
                                match_cnt += 1

                        if match_cnt > max_match_cnt:
                            ans = (web_list[ii][1], web_list[jj][1], web_list[kk][1])
                            max_match_cnt = match_cnt
                        elif match_cnt == max_match_cnt:
                            ans = min(ans, (web_list[ii][1], web_list[jj][1], web_list[kk][1]))

        return ans
```
