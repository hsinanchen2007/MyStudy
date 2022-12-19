### 解题思路
为啥要算深度呢，想象一下，只要每次的")"分给分开后的两个字符串里头[每个字符串“(”和“)”抵消后的“(”]最多的就可以了啊。

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        count1=0
        count2=0
        re=[]
        for s in seq:
            if s=='(':
                if count1<count2:
                    count1+=1
                    re.append(0)
                else:
                    count2+=1
                    re.append(1)
            else:
                if count1<count2:
                    count2-=1
                    re.append(1)
                else:
                    count1-=1
                    re.append(0)
        return re
        
            

```