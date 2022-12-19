### 解题思路
此处撰写解题思路
#at first I also want to use DFS or DP(dynamic planning) to solve this question but the difficult is that I can not find
#the conditions to do Prunning for the DFS
#for example It is not clearly for me when I should stop and when I should to append the str It is the problem
### 代码

```python3
from typing import List
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        cur_str=''
        def generate_str_dfs(l,r,cur_str):
               if r==0 and l==0:
                    res.append(cur_str)
                    return 
               if r<l:
                    return
               if l>0:
                    generate_str_dfs(l-1,r,cur_str=cur_str+"(")
               if r>0:
                    generate_str_dfs(l,r-1,cur_str=cur_str+")")
        generate_str_dfs(n,n,cur_str)
        return res


```