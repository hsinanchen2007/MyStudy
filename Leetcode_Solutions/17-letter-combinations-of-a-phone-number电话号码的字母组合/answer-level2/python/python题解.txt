### 解题思路
深度优先搜索

### 代码

```python
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        dict = {'2':"abc", '3':"def", '4':"ghi", '5':"jkl", '6':"mno", '7':"pqrs",'8':"tuv", '9':"wxyz"}
        result = []
        if len(digits) > 0:
            result = self.dfs(digits, dict)
        return result
    
    def dfs(self, str, dict):
        result = []
        can = dict[str[0]]
        if len(str) == 1:
            for each in can:
                result.append(each)
        else:
            last = self.dfs(str[1:], dict)
            for each in can:
                for list in last:
                    result.append(each+list)
        return result

```