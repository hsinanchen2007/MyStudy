```
class Solution(object):
    def addNegabinary(self, arr1=[], arr2=[]):
        l1, l2 = len(arr1), len(arr2)
        ret, carry = [], 0
        for i in range(-1, -max(l1, l2) - 1, -1):
            v1, v2 = 0, 0
            if i >= -l1: v1 = arr1[i]
            if i >= -l2: v2 = arr2[i]
            v = v1 + v2 - carry
            carry = v >> 1
            ret.append(v & 1)
        if carry == -1: ret.append(1)
        if carry == 1: ret.extend([1, 1])
        while ret[-1] == 0 and len(ret) > 1: ret.pop()
        return ret[::-1]
```