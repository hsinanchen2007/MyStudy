- break是跳出整体循环; pass是跳出本次循环
```
class Solution(object):
    def onNew(self, L):
        new_L = []
        for val in L:
            if val != '#':
                new_L.append(val)
            else:
                if len(new_L) != 0:
                    new_L.pop()

        return new_L
                
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        new_S = self.onNew(S)
        new_T = self.onNew(T)
        print new_S, new_T

        return new_S == new_T
```
