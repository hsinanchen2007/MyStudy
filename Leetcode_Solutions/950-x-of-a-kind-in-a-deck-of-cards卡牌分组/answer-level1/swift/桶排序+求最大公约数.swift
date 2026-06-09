因为题目给定了数值范围0 <= deck[i] < 10000，较小，很容易想到可以使用桶排序

```
class Solution {
    func gcd(_ a: Int, _ b: Int) -> Int {
        return b == 0 ? a : gcd(b, a % b)
    }
    
    func hasGroupsSizeX(_ deck: [Int]) -> Bool {
        var bucket = Array(repeating: 0, count: 10000)
        for n in deck {
            bucket[n] += 1
        }
        var x = 0
        for i in 1..<bucket.count {
            x = gcd(x, bucket[i - 1])
        }
        return x > 1
    }
}
```
