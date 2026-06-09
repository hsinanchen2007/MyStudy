```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        flag = 'bb'
        list1 = list(s)
        list2 = []
        ret = []
        n2,n3,n4,n5 = 0,0,0,0
        while True:
            try:
                n1 = list1.index(")")
            except ValueError:
                flag = 'xx'
                break
            if flag == 'bb' and n1 != 0:
                if list1[n1 - 1] == "(":
                    n2 = len(list2)
                    list2.append(n1+n2*2+n3)
                    list1.pop(n1)
                    list1.pop(n1-1)
            elif n1 == 0:
                n3 += 1
                list1.pop(n1)
        if list2:
            pass
        else:
            return(0)
        for j in range(max(list2),-1,-1):
            if j in list2:
                n5 += 1
            else:
                if n5 > 0:
                    list2.append(j)
                    n5 -= 1
                else:
                    pass
        list2.sort()
        for i in list2:
            if (i+1) in list2:
                n4 += 1
            else:
                n4 += 1
                ret.append(n4)
                n4 = 0
        if ret:
            return(max(ret))
        else:
            return(0)
```
