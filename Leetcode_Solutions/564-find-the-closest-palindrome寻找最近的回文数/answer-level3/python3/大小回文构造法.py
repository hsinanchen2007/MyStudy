![image.png](https://pic.leetcode-cn.com/160cecea0ea03dae2ac5e6f8f83ad0ca1d4f3fc19577db75f8481e8d8d662d21-image.png)

### 解题思路
首先将这个数字转换成回文数，也就是前半部分进行回文
- 如果回文与原数相等，表示需要在这个回文的基础上寻找小于和大于的回文
- 如果回文小于原数，只需要在这个回文的基础上找一个大于的回文即可
- 如果回文大于原数，只需要在这个回文的基础上找一个小于于的回文即可

- 查找小的回文
```
想要得到小的回文，就需要从回文中部开始，找到一个能够减一的位置，也就是找到第一个不为0的位置
如果开头是1，并且减一的位置就是开头，得到的应该是降低一个数量级，并且全为9的数字
```
- 查找大的回文
```
想要得到大的回文，就需要从回文中部开始，找到一个能够加一的位置，也就是第一个不为9的位置
如果找到开头都找不到到，也就是这些数字都是9，我们需要上升一个数量级，也就是组成一个开头和结尾数字是1，中间位置数字是0
```

### 代码

```python3
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        num = int(n)
        length = len(n)
        if n == 0:
            return "1"
        if num < 10:
            return str(num - 1)

        def get_small(cur_palindrome: str):
            cur_length = len(cur_palindrome)
            half_pos = cur_length // 2
            if cur_length % 2 == 0:
                half_pos -= 1

            while half_pos >= 0 and cur_palindrome[half_pos] == "0":
                half_pos -= 1
            ans = ""
            if half_pos == 0 and cur_palindrome[0] == "1":
                ans = "9" * (cur_length - 1)
            else:
                minus_num = str(int(cur_palindrome[half_pos]) - 1)
                first_part = cur_palindrome[:half_pos]
                last_part = "".join(reversed(cur_palindrome[:half_pos]))
                if cur_length % 2:
                    if half_pos == cur_length // 2:
                        ans = first_part + minus_num + last_part
                    else:
                        ans = first_part + minus_num + "9" * ((cur_length // 2 - 1 - half_pos) * 2 + 1) + minus_num + last_part
                else:
                    ans = first_part + minus_num + "9" * ((cur_length // 2 - half_pos - 1) * 2) + minus_num + last_part
            return ans

        def get_big(cur_palindrome: str):
            cur_length = len(cur_palindrome)
            half_pos = len(cur_palindrome) // 2
            if cur_length % 2 == 0:
                half_pos -= 1
            while half_pos >= 0 and cur_palindrome[half_pos] == "9":
                half_pos -= 1
            ans = ""
            if half_pos == -1:
                ans = "1" + "0" * (cur_length - 1) + "1"
            else:
                plus_num = str(int(cur_palindrome[half_pos]) + 1)
                first_part = cur_palindrome[:half_pos]
                last_part = "".join(reversed(cur_palindrome[:half_pos]))
                if cur_length % 2:
                    if half_pos == cur_length // 2:
                        ans = first_part + plus_num + last_part
                    else:
                        ans = first_part + plus_num + "0" * ((cur_length // 2 - 1 - half_pos) * 2 + 1) + plus_num + last_part
                else:
                    ans = first_part + plus_num + "0" * ((cur_length // 2 - half_pos - 1) * 2) + plus_num + last_part

            return ans

        palindrome = ""
        half = length // 2
        if length % 2:
            palindrome = n[:half + 1] + "".join(reversed(n[:half]))
        else:
            palindrome = n[:half] + "".join(reversed(n[:half]))
        palindrome_num = int(palindrome)
        small_num = palindrome_num if palindrome_num < num else int(get_small(palindrome))
        big_num = palindrome_num if palindrome_num > num else int(get_big(palindrome))

        if num - small_num <= big_num - num:
            return str(small_num)
        else:
            return str(big_num)
```