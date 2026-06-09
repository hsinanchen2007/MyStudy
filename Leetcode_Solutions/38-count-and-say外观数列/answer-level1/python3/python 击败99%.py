写的很笨，却意外的击败了99%
思路如下：
外面的for循环控制次数，里面的for循环用来遍历上次的结果，`pre`和`res`分别存这次和上次的结果，`curr`存的是目前讨论的值，具体讨论如下：

1. 当n=1或n=0需要独立讨论
2. 当遍历pre时，我们只需要考虑现在是否和`curr`中存的值是否相等，相等加一，若不等，我们将结果链接到`res`后面，并且赋`curr`为现在的值，并将`count`置1(注意是置1不是置0，因为你下次遇到它的时候是第二个而不是第一个！)
3. 当遍历完`pre`后，会有两种情况：
    - 其一，最后几位都相等，所以并没有进入else，自然没有被加入到`res`里
    - 其二，最后一位不等，那自然也没有进入else(没有机会)，那我们也需要将它手动加入进去(注意，因为else里`count`是置1所以我们并不用做其他的处理，所以实际上这两种情况都做相同的操作)


```
    def countAndSay(self, n: int) -> str:
        pre = "1"
        if n==1 or not n: return "1"
        for _ in range(2,n+1):
            count = 0
            curr = pre[0]
            res = ""
            for j in pre:
                if curr == j:
                    count+=1
                else:
                    res+=str(count) + str(curr)
                    curr = j
                    count = 1
            res+=str(count) + str(curr)
            pre = res
        return res
```

