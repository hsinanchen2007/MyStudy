### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def removeDuplicates(self, n):
        if len(n)==0:return 
        if len(n)==1:return
        i=0
        while i<=len(n)-2:
            if n[i]==n[i+1]:#如果与后一项相同则删除（后面的会自动补齐所以下标不用加1）
                del n[i]
            else:#如果与后一项不同则下标加1来往后循环
                i+=1
```