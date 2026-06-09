### 解题思路
双指针法

### 代码

```swift
class Solution {
    func canThreePartsEqualSum(_ A: [Int]) -> Bool {
        
        //先将输入数组的元素求和，如果发现元素和不能整除3则直接返回false
        let sum = A.reduce(0, +)
        
        if sum % 3 != 0 {
            return false
        }
        
        let average = sum / 3
        
        //定义两个指针分别指向数组头尾，在一次遍历的周期内，考察头尾指针所遍历过的元素的累和是否能达到sum的三等分
        var i = 0
        var j = A.count - 1
        var sumHead = 0
        var sumTail = 0
        
        while i < j {
            
            if sumHead != average {
                sumHead += A[i]
                i += 1
            }
            
            if sumTail != average {
                sumTail += A[j]
                j -= 1
            }
            
            if sumHead == average && sumTail == average {
                return true
            }
        }

        return false

    }
}
```