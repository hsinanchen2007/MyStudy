## 字母计数器解法（自测比转为 Character 数组更快）
![Snip20200409_1.png](https://pic.leetcode-cn.com/d7fb2ed00b34d10d6e3bb35dd365d5b24b3876bfedaaeb8f6678bf5e72f0b7f7-Snip20200409_1.png)

## 代码如下
```swift
func isAnagram(_ s: String, _ t: String) -> Bool {
    guard s.count == t.count else { return false }
    var counter = [Int](repeating: 0, count: 26)
    let aCharUnicodeScalar = Int("a".unicodeScalars.first!.value)
    for scalar in s.unicodeScalars {
        counter[Int(scalar.value) - aCharUnicodeScalar] += 1
    }
    for scalar in t.unicodeScalars {
        counter[Int(scalar.value) - aCharUnicodeScalar] -= 1
    }
    guard counter.first(where: { $0 != 0 }) == nil else { return false }
    return true
}

```