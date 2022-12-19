### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reconstructQueue(self, people):
        people.sort(key=lambda x:(-x[0],x[1]))
        print(people)
        ans=[]
        for i in people:
            ans.insert(i[1],i)
        #print(ans)
        return ans
```