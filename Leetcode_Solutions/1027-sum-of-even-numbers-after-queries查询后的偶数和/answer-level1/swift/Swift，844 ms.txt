```swift
class Solution {
    func sumEvenAfterQueries(_ A: [Int], _ queries: [[Int]]) -> [Int] {
        var ans = [Int](), a = [Int](A)
        var evenSum: Int = a.filter({ ($0 % 2) == 0 }).reduce(0, +)
        for queriy in queries {
            let val = queriy[0]
            let index = queriy[1]
            let oldValue = a[index]
            let newValue = a[index] + val
            a[index] = newValue
            let oldIsEven = (oldValue % 2) == 0
            let newIsEven = (newValue % 2) == 0
            if oldIsEven == newIsEven {
                if oldIsEven {
                    evenSum += val
                }
            } else {
                if newIsEven {
                    evenSum += newValue
                } else {
                    evenSum -= oldValue
                }
            }
            ans.append(evenSum)
        }
        return ans
    }
}
```