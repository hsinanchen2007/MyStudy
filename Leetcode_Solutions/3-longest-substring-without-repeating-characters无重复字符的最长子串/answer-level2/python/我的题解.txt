这个思路多亏某大神，用到了移动窗口的思路，之前想用队列的来出入队的，但是感觉有点麻烦，加上对队列的用法不是很熟悉，所以就采用了这种列表来模拟队列的思路，我是在pycharm中写的代码，转移到力扣当中，所以都把它们变成了函数，哈哈。习惯就好。
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def solve(a):
            b=[]
            length=[]
            for a1 in a:
                if a1 in b:
                    length1=len(b)
                    length.append(length1)
                    c=out(b,a1)
                    c.append(a1)
                    b=c
                else:
                    b.append(a1)
            length.append(len(b))
            maxs=max(length)
            return maxs

        def out(b,a1):
            for i in range(len(b)):
                if a1 == b[i]:
                    j = i
            # j=posi(b,a1)
            lenb=len(b)
            c=b[j+1:lenb]
            return c

        # def posi(b,a1):
        #     for i in range(len(b)):
        #         if a1==b[i]:
        #             j=i
        #     return j
        
        k=solve(s)
        return k


```

![QQ截图20200207183958.png](https://pic.leetcode-cn.com/fa45bb1f5b0ffd9627505fff9a24ae35ce6948d11ad52ebeb9c2854230c650b1-QQ%E6%88%AA%E5%9B%BE20200207183958.png)

