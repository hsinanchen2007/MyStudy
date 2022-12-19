如果一个字母重复了 就从这个重复的字母下一个重新开始

```
    func lengthOfLongestSubstring(_ s: String) -> Int {
        let str = Array(s)
        let len = str.count
        if len <= 1 {
            return len
        }
        var dic = [Character: Int]()
        var res = 1
        var j = 0
        for i in 0 ..< len {
            let char = str[i]
            if let loc = dic[char] {
                j = max(j, loc + 1)
            }
            dic[char] = i
            res = max(res, i - j + 1)
        }
        return res
    }
```