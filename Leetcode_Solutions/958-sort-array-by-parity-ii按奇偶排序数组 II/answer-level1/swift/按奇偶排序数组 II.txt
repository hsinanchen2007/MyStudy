
双指针遍历

```swift []
class Solution {
   func sortArrayByParityII(_ A: [Int]) -> [Int] {
        guard A.count >= 2 else {
            return A
        }
        
        var odd: Int = 1
        var even: Int = 0
        var newArray = [Int].init(A)
        while odd < A.count, even < A.count {
            while odd < A.count, A[odd] % 2 != 0 {
                newArray[odd] = A[odd]
                odd = odd + 2
            }
            
            while even < A.count, A[even] % 2 == 0 {
                newArray[even] = A[even]
                even = even + 2
            }
            
            if odd < A.count, even < A.count {
                newArray[odd] = A[even]
                newArray[even] = A[odd]
                odd = odd + 2
                even = even + 2
            }
        }
        return newArray
    }
}
```

