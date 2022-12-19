### 解题思路
其实类似于二进制加法，只不过当某一位满二后向它的前两位各进1，因此假如两个数的位数相同，且最高位都是1时，最后的答案需要在最高位前面多出两位。
为了简化运算，我们首先把两个数的位数变成相等，不足的在最高位前面补0，然后再在两个数的最高为前面加4个0方便运算，最后把前面的0删掉即可。

### 代码

```python3
class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1 = arr1[::-1]
        arr2 = arr2[::-1]
        if len(arr1) > len(arr2):
            arr2 += [0] * (len(arr1) - len(arr2))
        elif len(arr1) < len(arr2):
            arr1 += [0] * (len(arr2) - len(arr1))
        arr1 += [0] * 4
        arr2 += [0] * 4
        arr = []
        for i in range(len(arr1)):
            arr.append(arr1[i] + arr2[i])
        ans = [0] * len(arr)
        for i in range(len(arr) - 2):
            ans[i] = arr[i] % 2
            count = arr[i] // 2
            arr[i+1] = arr[i+1] + count
            arr[i+2] = arr[i+2] + count
        for i in range(len(ans) - 1, -1, -1):
            if ans[i] == 0:
                ans.pop()
            else:
                break
        return ans[::-1] if ans else [0]
```