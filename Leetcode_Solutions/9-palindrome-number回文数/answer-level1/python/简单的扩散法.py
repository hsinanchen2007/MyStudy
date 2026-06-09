分成奇数和偶数两种情况，奇数是中间的一个数向两边扩散，偶数是中间的两个数向两边扩散，然后记录下来扩散的次数。

```
class Solution(object):
    def isPalindrome(self,x):
        if not x: return True
        x = str(x)
        x = list(x)
        size = len(x)
        mid = int(size / 2)
        count = 0
        if size % 2 == 0:
            left = mid - 1
            right = mid
            while left >= 0 and right <= size - 1 and x[left] == x[right]:
                count += 1
                left -= 1
                right += 1
            if count == size / 2:
                return True
            else:
                return False
        else:
            left = mid
            right = mid
            while left >= 0 and right <= size - 1 and x[left] == x[right]:
                count += 1
                left -= 1
                right += 1
            if count == int(size / 2) + 1:
                return True
            else:
                return False
```
