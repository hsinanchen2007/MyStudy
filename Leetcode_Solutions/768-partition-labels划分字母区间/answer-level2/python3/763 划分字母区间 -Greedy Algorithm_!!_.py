### 解题思路
#### 对于遇到的每一个字母，去找这个字母最后依次出现的位置，用来更新当前的最小区间
last: val-ID键值对，保存每个字母最后出现的索引
start/end:当前区间的首/尾
若扫描到的字母最后一次出现的索引大于end，更新end；
当遍历到当前区间的末尾（i==end）时，把当前的区间加入res，同时搜索下一个区间(start=i+1)

### 代码

```python3
#字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。
#返回一个表示每个字符串片段的长度的列表。
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        #对于遇到的每一个字母，去找这个字母最后依次出现的位置，用来更新当前的最小区间
        res=[]
        last={val:ID for ID,val in enumerate(S)}#记录最后出现字母的索引
        start=end=0#当前区间的首尾
        for i,val in enumerate(S):
            end=max(end,last[val])#更新区间尾的索引!
            if i==end:#达到区间尾
                res.append(end-start+1)
                start=i+1#扫描下一个区间
        return res

```