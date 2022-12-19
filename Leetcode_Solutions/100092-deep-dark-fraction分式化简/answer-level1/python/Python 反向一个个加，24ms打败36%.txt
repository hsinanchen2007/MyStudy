```
class F(object):
    def __init__(self, t, d):
        self.d = d
        self.t = t
    def flip_and_add(self, a1):
        self.d, self.t = self.t, self.d
        self.t =  a1 * self.d + self.t
    
    def out(self):
        return [self.t, self.d]

class Solution(object):
    def fraction(self, cont):
        """
        :type cont: List[int]
        :rtype: List[int]
        """
        # cont = cont[:]
        cont[-1] = F(cont[-1], 1)

        while len(cont) >= 2:
            v1 = cont.pop()
            v1.flip_and_add(cont[-1])
            cont[-1] = v1
        return cont[-1].out()

```
