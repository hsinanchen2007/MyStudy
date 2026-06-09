
### 代码

```swift
class Solution {
    func sumNums(_ n: Int) -> Int {
        var sum = n
        (n > 0) && { sum += sumNums(n - 1); return true }()
        return sum;
    }
}

```