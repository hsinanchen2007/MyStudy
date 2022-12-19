
瞎想写的,没有优化代码,python3 28ms 13.7MB 100%
步骤一:转列表删除相同元素,不同字符对数为奇数,无解
步骤二:l1中"x"对应l2中"y",反之亦然.如果在当前下标之后没有找到,则与下一个位置的一对相消,步数加2,找到则步数加1.两种操作都要删除两对.输出结果

```
```python []
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        if len(s1) != len(s2):
            return -1
        if s1 == s2:
            return 0
        l1 = list(s1)
        l2 = list(s2)
        diff = 0
        i = len(l1)-1
        while i>=0:
            if l1[i] == l2[i]:
                del l1[i]
                del l2[i]
                #i -= 1
            else:
                diff += 1
            i -= 1
        #print(l1)
        #print(l2)
        #print(diff)
        if diff%2 != 0:
            return -1
        
        i = 0
        times = 0
        while True:
            if len(l1)<=1:
                break
            if l1[i] == "x":
                try:
                    index = l2.index("y",i+1)
                    del l1[index]
                    del l2[index]
                    del l1[i]
                    del l2[i]
                    times += 1
                except:
                    times += 2
                    del l1[i+1]
                    del l2[i+1]
                    del l1[i]
                    del l2[i]
            elif l1[i] == "y":
                try:
                    index = l2.index("x",i+1)
                    del l1[index]
                    del l2[index]
                    del l1[i]
                    del l2[i]
                    times += 1
                except:
                    times += 2
                    del l1[i+1]
                    del l2[i+1]
                    del l1[i]
                    del l2[i]
                        #break
        return times
```
