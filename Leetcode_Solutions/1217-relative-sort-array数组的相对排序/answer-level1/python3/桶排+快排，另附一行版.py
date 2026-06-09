![image.png](https://pic.leetcode-cn.com/5ddd94c8fba58a4506cd1d118334f3cd2a5f89275292bab3e5ee37b7aeb9913b-image.png)

桶排加快排，是比较正常的解法

```
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        d = {i: 0 for i in arr2}
        oths = []
        for i in arr1:
            if i in d:
                d[i] += 1
            else:
                oths += [i]
        ans = []
        for i in arr2:
            ans += [i] * d[i]
        return ans + sorted(oths)
```

一行版：依照题意做了个匿名函数，但相当于全元素做快排，所以会慢点，数据最大只有1000，所以判断条件加1000就会自动放在最后面。

```
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        return sorted(arr1, key = lambda x: arr2.index(x) if x in arr2 else x + 1000)
```
