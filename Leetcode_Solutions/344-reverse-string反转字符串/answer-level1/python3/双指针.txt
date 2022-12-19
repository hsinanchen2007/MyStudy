方法1:可用Python内置函数直接解决，s.reverse()

方法2：双指针(python版本)

```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        l, r = 0, len(s)-1
        while l < r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1
```

双指针（go版本，不过运行超慢的，1000ms）

```
func reverseString(s []byte)  {
    l, r := 0, len(s)-1
    for l < r {
        s[l], s[r] = s[r], s[l]
        l++
        r--
    }
}
```

