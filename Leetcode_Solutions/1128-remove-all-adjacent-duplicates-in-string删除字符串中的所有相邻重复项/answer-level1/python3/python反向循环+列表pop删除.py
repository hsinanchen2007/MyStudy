我们一个一个推一遍：

转化为列表，添加0：[a,b,b,a,c,a,0]

i = 7 - 2 = 5 -> a != 0

i = 4 -> c != a

i = 3 -> a != c

i = 2 -> b != a

i = 1 -> b == b -> s_li.pop(2),s_li.pop(1) -> [a,a,c,a,0]

i = 0 -> a == a -> s_li.pop(1),s_li.pop(0) -> [c,a,0]

最后在去除填上的0 -> [c,a] -> "ca"


```
class Solution:
    def removeDuplicates(self, S):
        s_li = list(S)
        s_li.append(str(0))  ###为了解决"aaaaaa" list out of range的问题
        i = len(s_li)-2
        while i >= 0:
            if s_li[i] == s_li[i+1]:
                s_li.pop(i+1)
                s_li.pop(i)
            i = i - 1
        s_li.remove(str(0))
        return "".join(s_li)
```
