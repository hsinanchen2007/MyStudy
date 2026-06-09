### 解题思路
添加括号有两种方式，添加左括号，或者添加右括号，其中，满足要求的记录。思路就是遍历所有的情况，一种方式就是回溯，每次添加括号都是遍历的层数加1，在这基础上，再次进行遍历，指导遍历介绍。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def helper(res,left,right,all_res):
            if (right>left) or (left>n) or (right>n):
                return all_res
            if (left == n) and (right == n):
                all_res.append(res)
                return all_res
            if left < n:
                res1 = res + '('
                all_res = helper(res1,left+1,right,all_res)
            if right < n:
                res2 = res + ')'
                all_res = helper(res2,left,right+1,all_res)
            return all_res
        
        res = '('
        all_res = helper(res,1,0,[])
        return all_res
        

```