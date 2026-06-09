做这个题目前先看了一下什么事Manacher 算法，根据这个算法的思想自己进行设计
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        new_s = ""
        for each in s:
            new_s += each + "#"
        new_s = "#" + new_s
        count_list = []
        for i, new_each in enumerate(new_s):
            med = i
            left = med - 1
            right = med + 1
            hw_length = 1
            while True:
                if left < 0:
                    break
                if right >= len(new_s):
                    break
                if new_s[left] == new_s[right]:
                    left -= 1
                    right += 1
                    hw_length += 1
                else:
                    break
            count_list.append(hw_length)
        max_count = max(count_list)
        first_max_index = count_list.index(max_count)
        result = new_s[first_max_index-max_count+1:first_max_index+max_count]
        return result.replace("#", '')
```

   
结果
执行用时 :2384 ms, 在所有 python3 提交中击败了52.77% 的用户
内存消耗 :13.8 MB, 在所有 python3 提交中击败了19.09%的用户

执行用时 :2324 ms, 在所有 python3 提交中击败了53.08% 的用户
内存消耗 :13.9 MB, 在所有 python3 提交中击败了18.91%的用户

执行用时 :2108 ms, 在所有 python3 提交中击败了54.87% 的用户
内存消耗 :13.9 MB, 在所有 python3 提交中击败了18.96%的用户

就是这个有点费时，后面再优化吧，(*^▽^*)

欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)