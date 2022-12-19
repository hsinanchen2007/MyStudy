### 解题思路
1. 先不考虑字符串，字符串每个字符从0开始编号，一开始每个编号的联通分量就是它自己，存储在一个一维数组p
2. 依据pair将2个编号连接，只需把这2个编号的联通分量设置成一样就行了。find方法用于找到某个编号的联通分量，union方法将其中一个编号的联通分量设置成另一个，这样就相当于把2个联通分量结合起来了
3. 把联通分量作为字典key给所有编号分组，因为分组里面的编号都是联通的，所以可以任意交换位置
4. 把编号作为索引还原成字符在组内排序，排序完成后根据原所在数组位置放回去

### 代码

```python3
class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        p=list(range(len(s)))
        def find(i):
            if i!=p[i]:
                p[i]=find(p[i])
            return p[i]
        def union(i,j):
            p[find(i)]=find(j)
        for i,j in pairs:
            union(i,j)        
        dic=collections.defaultdict(list)
        for i in range(len(p)):            
            dic[find(i)].append(i)
        res=list(s)
        for lst in dic.values():
            for i, c in zip(lst, sorted(res[i] for i in lst)):
                res[i] = c
        return ''.join(res)

```

### 错误
一开始提交结果超时了，发现原因出在find上
超时的代码：
```
def find(i):
    while i!=p[i]:
        i=p[i]
    return i
```
这段代码只考虑了查找，并没有进行路径压缩，改成递归就好了
