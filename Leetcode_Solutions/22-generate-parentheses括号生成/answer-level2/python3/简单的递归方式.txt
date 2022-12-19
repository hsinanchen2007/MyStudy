### 解题思路
速度不行，内存占用不行，但是方法比较简单。
在n-1括号的组合中，每检测到（），就在左面和中间各插入一个新括号，检查是否在之前出现过，没出现过则记录。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        par={1:["()"]}
        def recursion(n:int):
            if n==1:
                return par[1]
            recursion(n-1)
            par[n]=[]
            lt=par[n-1]
            for it in lt:
                for j in range(len(it)-1):
                    if it[j]=='(' and it[j+1]==')':
                        new_it=list(it)
                        new_it.insert(j,'()')
                        new_it="".join(new_it)
                        if new_it not in par[n]:
                            par[n].append(new_it)
                        new_it=list(it)
                        new_it.insert(j+1,'()')
                        new_it="".join(new_it)
                        if new_it not in par[n]:
                            par[n].append(new_it)
            return par[n]
        
        return recursion(n)




```