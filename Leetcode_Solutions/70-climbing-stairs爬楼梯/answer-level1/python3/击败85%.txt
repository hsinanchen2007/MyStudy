```
        list1 = [0,1]
        a = 0
        for i in range(n):
            a = sum(list1)
            list1.pop(0)
            list1.append(a)
        return(a)

```
