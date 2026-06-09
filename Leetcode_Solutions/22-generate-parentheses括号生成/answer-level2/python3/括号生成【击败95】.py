```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        lists = []
        if n >0 and not lists :lists.append("(")
        while lists:
            zuo = lists[0].count("(")
            you = lists[0].count(")")
            if zuo > you:
                if zuo == n:
                    lists.append(lists[0]+")")
                    lists.pop(0)
                else:
                    lists.append(lists[0] + ")")
                    lists.append(lists[0] + "(")
                    lists.pop(0)
            else:
                if zuo == n:
                    return(lists)
                else:
                    lists.append(lists[0] + "(")
                    lists.pop(0)
```
