DFS求解
当左括号数==n and 右括号数==n:
    res.append()
当左括号数<右括号:
    不符合题意，返回
当左括号数小于n：
    DFS
当右括号数小于n:
    DFS

```ruby
class Solution(object):
    def __init__(self):
        self.ans=[]

    def DFS(self,s,l_brackets,r_brackets,n):
        if l_brackets==n and r_brackets==n:
            self.ans.append(s)
            return
        if l_brackets<r_brackets:
            return
        if l_brackets<n:
            self.DFS(s+'(',l_brackets+1,r_brackets,n)
        if r_brackets<n:
            self.DFS(s+')',l_brackets,r_brackets+1,n)

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        s=''
        self.DFS(s,0,0,n)
        return self.ans