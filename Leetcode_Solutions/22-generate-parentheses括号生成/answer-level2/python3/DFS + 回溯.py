左括号和右括号各是n个，每次向S中增加一个字符，

如果左括号剩余次数大于0，可以将左括号加在S尾部，左括号次数要-1

如果右括号次数大于左括号次数，可以将右括号加在S尾部，右括号次数要-1

然后深度搜索，切记，在搜索结束后，需要回溯，也就是要把之前添加在尾部的那个字符去掉，同时相应的左括号或者又括号的次数要加1，恢复到之前状态

递归结束条件是，左括号次数和右括号次数同时为0
```py3
class Solution:
    def generateParenthesis(self, n: int):
        ans = []
        def dfs(S, left, right):
            if left == 0 and right == 0:
                ans.append(S)
                return 
            if left > 0:
                S += "("
                left -= 1
                dfs(S, left, right)
                S = S[:-1]
                left += 1
                
            if right > 0 and right > left:
                S += ")"
                right -= 1
                dfs(S, left ,right)
                S = S[:-1]
                right -= 1
        dfs("", n, n)
        return ans
```