### 解题思路
此处撰写解题思路
start标定重复字母的左索引，end标定重复字母的右索引，一次遍历，时间复杂度是O(n)
### 代码

```python3
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        res=[]
        start=0
        end=1
        if len(S)<=2:
            return []

        while end<len(S):
            if S[start]==S[end]:
                end+=1
                if end==len(S):
                    if end-1-start>=2:
                        res.append([start,end-1])
                    else:
                        pass


            else:
                if end-1-start>=2:
                    res.append([start,end-1])
                    start=end
                    end+=1
                else:
                    start=end
                    end+=1
            
        return res
```