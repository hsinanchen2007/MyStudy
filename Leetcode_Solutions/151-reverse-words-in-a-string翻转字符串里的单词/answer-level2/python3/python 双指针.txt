1. 对s尾部增加一个" "字符，确保s[l:r]能覆盖所有有效字符。
2. r指针碰到" "但l指针没碰到" "，则往stack里添加s[l:r]，为一个有效单词，l换到r的位置， r+1。
3. l指针碰到" "，则l换到r的位置， r+1。
4. l和r在某个单词内滑动，则只对r+1.
5. 最终的res顺序需要翻转。
```
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s + " "
        l = 0
        r = 0
        n = len(s)
        stack = []

        while (r <n):

            if s[r] is " " and s[l] is not " ":
                stack.append(s[l:r])
                l = r
                r += 1
            elif s[l] is " ":
                l = r
                r += 1
            else:
                r += 1
                continue


        res = " ".join(stack[::-1])
        return res
```