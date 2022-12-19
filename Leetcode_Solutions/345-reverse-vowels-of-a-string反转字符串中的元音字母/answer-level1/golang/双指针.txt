利用双指针，每次交换前判断一下是否都是元音字母即可

```
class Solution:
    def reverseVowels(self, s: str) -> str:
        res = 'aeiouAEIOU'
        l, r = 0, len(s) - 1
        s = list(s)
        while l < r:
            if s[l] in res and s[r] in res:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
            elif s[l] in res:
                r -= 1
            elif s[r] in res:
                l += 1
            else:
                l += 1
                r -= 1
        res = ''.join(s)
        return res
```

golang:双指针+哈希表

```
func reverseVowels(s string) string {
    res := []byte(s)
    match := map[byte]int{
        'a' : 1, 'e' : 1, 'i' : 1, 'o' : 1, 'u' : 1, 
        'A' : 1, 'E' : 1, 'I' : 1, 'O' : 1, 'U' : 1,
    }
    l, r := 0, len(res) - 1
    for l < r {
        a, b := match[res[l]], match[res[r]]
        if a == 1 && b == 1 {
            res[l], res[r] = res[r], res[l]
            l++
            r--
        } else if a == 0 {
            l++
        } else if b == 0 {
            r--
        } else {
            l++
            r--
        }
    }
    return string(res)
}
```

