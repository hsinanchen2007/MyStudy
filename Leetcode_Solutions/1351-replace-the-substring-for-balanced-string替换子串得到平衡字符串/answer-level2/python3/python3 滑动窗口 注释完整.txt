```
def min(s) ->int:
    n = len(s)
    average = n //4
    import collections
    counter = collections.Counter(s)
    saveCounter = collections.Counter()
    #所有超过1/4的都是需要转换的 集中
    for key,val in counter.items():
        if val>average:
            saveCounter[key] = val
    if not saveCounter:
        return 0

    l = r = 0
    count = float("inf")
    for r in range(n):
    #每一个如果都要需要转化的过程中，则滑动窗口需要包含，直到滑动窗口足够大，saveCounter包含的元素对应的次数都要小于等于average
        if s[r] in saveCounter:
            saveCounter[s[r]] -= 1
        while l<=r:
            include = True
            for ch in 'QWER':
                if saveCounter[ch] > average:
                    include = False
                    break
            if include:
                #如果滑动窗口已经包含了 那么接下来我们将左边右移，需要将s[l] 次数++
                count = min(count,r-l+1)
                saveCounter[s[l]] += 1
                l += 1
            else:
                break
    return count

```


