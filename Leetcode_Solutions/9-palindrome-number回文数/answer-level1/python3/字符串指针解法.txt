### 解题思路
先将数字转成字符串
再通过首尾两个指针比较字符串首尾值
与字符串切片法效率一致
时间复杂度均为O(N)
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        string = str(x)
        left = 0
        right = len(string) - 1
        while left < right:
            if string[left] != string[right]:
                return False
            else:
                left += 1
                right -= 1
        return True

```