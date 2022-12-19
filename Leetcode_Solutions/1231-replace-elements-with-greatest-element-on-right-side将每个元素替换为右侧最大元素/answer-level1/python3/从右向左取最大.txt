### 解题思路
从右向左取最大
重点：在比较最大的地方 → ans[i+1]就是上一轮计算中的最大值，因此只需要拿这个值与arr[i+1]再比较即可

### 代码

```python3
class Solution:

    def replaceElements(self, arr: List[int]) -> List[int]:
        n = len(arr)
        ans = [0] * (n-1) + [-1]
        for i in range(n-2, -1, -1):
            print(arr[i+1])
            ans[i] = max(ans[i+1], arr[i+1]) # 因为ans[i+1]已经是刚刚计算出来最大的数，因此，只要比arr[i+1]和ans[i+1]哪一个大，就作为ans[i]的值

        return ans
```