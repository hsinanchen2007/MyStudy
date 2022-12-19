解题思路：主要就是逆序遍历，通过从右到左遍历最大的值，一直更新右边最大的值就可以了。
代码如下：
```
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n = len(arr)
        ans = [0] * (n-1) + [-1]
        for i in range(n-2, -1, -1):
            ans[i] = max(ans[i+1], arr[i+1])
        return ans

```

