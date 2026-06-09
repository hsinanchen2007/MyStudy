### 解题思路
滑窗遍历，可以用字典或者集合来保存

### 代码

``class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        #用字典好像比集合慢
        # if len(s) < 10:
        #     return []
        # d = {}
        # for i in range(0,len(s)-):
        #     if s[i:i+10] not in d:
        #         d[s[i:i+10]] = 1
        #     else:
        #         d[s[i:i+10]] += 1
        # ans =[]
        # for item in d.keys():
        #     if d[item] >= 2:
        #         ans.append(item)
        # return ans


        visited = set()
        res = set()
        for i in range(0, len(s) - 9):
            tmp = s[i:i+10]
            if tmp in visited:
                res.add(tmp)
            else:
                visited.add(tmp)
        return list(res) 


```