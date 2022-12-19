### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func merge(_ A: inout [Int], _ m: Int, _ B: [Int], _ n: Int) {
        guard n > 0 else { return }
        guard m > 0 else {
            A = B
            return
        }
        var aPoint = 0
        var bPoint = 0
        var aTop = m
        if B[bPoint] < A[aPoint] {
            A.removeLast()
            A.insert(B[bPoint], at: 0)
            bPoint += 1
        }
        while aPoint < aTop, bPoint < n {
            if A[aPoint] <= B[bPoint], B[bPoint] < A[aPoint + 1] {
                A.removeLast()
                A.insert(B[bPoint], at: aPoint + 1)
                bPoint += 1
                aPoint += 1
                aTop += 1
            } else {
                aPoint += 1
            }
        }
        if bPoint < n {
            for i in bPoint..<n {
                A[m + i] = B[i]
            }
        }
    }
}
```