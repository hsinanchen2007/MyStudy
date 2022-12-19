注释在代码中→→→


class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:


        #验证目前的s中左右括号数目是否匹配
        def isValid(s):
            count = 0
            for char in s:
                if char == '(':
                    count += 1
                if char == ')':
                    count -= 1
                if count < 0:
                    return False  # ())))
            return count == 0

        def dfs(s, start, l, r):
            #如果左右括号匹配，添加进结果集
            if l == 0 and r == 0:
                if isValid(s):
                    self.ans.append(s)
                return
            #如果左右不匹配
            for i in range(start, len(s)):
                #如果i和前一个相同，那么删哪个结果都一样，故跳过
                if i -1 >= start and s[i] == s[i - 1]:
                    continue
                #如果右括号有不匹配的，删去右括号，判断是否匹配
                if r > 0 and s[i] == ')':
                    dfs(s[:i] + s[i + 1:], i, l, r - 1)
                #如果左括号有不匹配的，删去左括号，判断是否匹配
                if l > 0 and s[i] == '(':
                    dfs(s[:i] + s[i + 1:], i, l - 1, r)
        
        
        #统计右括号不匹配的数量放入r，左括号没有被匹配的数量放入l
        l = 0
        r = 0
        
        for char in s:
            if char == '(':
                l += 1
            elif char == ')':
                if l == 0:
                    r += 1
                else:
                    l -= 1
        self.ans = []
        dfs(s, 0, l, r)
        return self.ans