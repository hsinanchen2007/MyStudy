### 解题思路
反方向进行考虑，可讲题目解释为，从右往左，判断当前值跟已知最小值进行比较，若当前值小于最小值，则从实际上讲，此刻的最小值
便是当前值右端的最大值，应用最小值代替最大值。若当前值大于最小值，将当前值赋予最小值。此时需要比较的为数组arr[1:]，首位
应被替换掉所以无需考虑。

### 代码

```python3
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        index = 0
        result = [-1]
        max_num = -9999999
        for i in reversed(arr[1:]):
            if max_num < i:
                max_num = i
            result = [max_num] + result
        return result

```