### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        #首先找到每个元素出现的最后位置,字典的形式，通过元素找到下标
        last={c:i for i,c in enumerate(S)}
        #设置区间
        start=end=0
        #保存字符串的长度
        res=[]
        #开始遍历元素"ababcbacadefegdehijhklij"
        for i,c in enumerate(S):
            #设置尾部
            end=max(end,last[c])
            #当区间里所有元素都遍历过
            if i==end:          
                res.append(end-start+1)
                start=i+1
        return res


        
```