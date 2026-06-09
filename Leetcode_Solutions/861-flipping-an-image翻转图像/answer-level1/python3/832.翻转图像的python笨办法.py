因为只有0和1两个值，所以使用了简单的互换和倒序输出

```
class Soulution:
    def flipAndInvertImage(self, A:list[list(int)])->list[list(int)]:
        for list1 in A:
            for i,m in enumerate(list1):
                if m == 1:
                    list1[i] = 0
                else:
                    list1[i] = 1
            list1.reverse()
        return A
```

