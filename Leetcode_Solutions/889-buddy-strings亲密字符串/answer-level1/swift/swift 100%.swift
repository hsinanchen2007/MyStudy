根据题意可知，A 必须交换任意两个字母可以得到 B的话为 true.注意是**任意两个且必须交换一次**，不是连续两个，也不是三个，也不能不交换。
先处理异常数据，A.count != B.count， A.isEmpty， 直接返回 false 
考虑下列几种的情况：
    1.有大于两个的不同字母，直接返回 false
    2.有两个不同的字母，其位置分别记为 i，j, 则必有 A[i] == B[j] && A[j] == B[i]，否则返回 false
    3.假设记录 i,j 经过循环后，其值没有变化，说明 A==B，则只要 A中有任意两个字符相同，A都可以通过交换一次该相同字符       变成 B

```
func buddyStrings(_ A: String, _ B: String) -> Bool {

    guard A.count == B.count, !A.isEmpty else {
        return false
    }

    let A = A.compactMap({$0})
    let B = B.compactMap({$0})

    var l = -1, r = -1

    var hasMoreDiff = false

    for i in 0..<A.count {
        if A[i] != B[i] {
            if l == -1 {
                l = i
            } else if r == -1 {
                r = i
            } else {
                hasMoreDiff = true
            }
        }
    }

    if l == -1, r == -1 {
        // 可能是回文,
        var map: [Character: Int] = [:]

        for i in 0..<A.count {
            map[A[i]] = (map[A[i]] ?? 0) + 1

            if map[A[i]]! >= 2 {
                return true
            }
        }

        return false
    }

    return hasMoreDiff ? false : (A[l] == B[r] && A[r] == B[l])
}
```
