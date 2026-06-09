### 解题思路
主干二分查找法，本题有两点需要注意：
1. 当中值letters[med]=target时，需要输出后一位，等价于letters[med]<target
2. 输出后一位存在超过边界情况（out of range）,所以需要判断是否大于边界
3. 因为要找大的,最后退出循环时l是比r大的，所以输出l。

p.s 题干第二个例子（非示例）也是有序数组吗？？？

### 代码

```python3
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l = 0
        r = len(letters) -1
        while l <= r:
            med = l + ( r - l ) // 2
            if letters[med] <= target:
                l = med + 1
            elif letters[med] > target:
                r = med - 1
        if l >= len(letters):
            return letters[0]
        return letters[l]
```