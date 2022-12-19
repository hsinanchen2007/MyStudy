```python
def findPairs(nums, k):
    # 这里有一个细节需要注意的是: (1,3)等同于(3,1)
    # 所以我们无需将1,3都存储起来, 只要存储3即可. 因为k是确定的, 导致1也是确定的
    if k < 0:
        return 0
    # s存储遍历的元素, r存储上面注释的3
    s, r = set(), set()
    for n in nums:
        if n + k in s:
            r.add(n + k)
        if n - k in s:
            r.add(n)
        s.add(n)
        
    return len(r)

print(findPairs([3,1,4,1,5], 2))
print(findPairs([1,2,3,4,5], 1))
print(findPairs([1,3,1,5,4], 0))
```