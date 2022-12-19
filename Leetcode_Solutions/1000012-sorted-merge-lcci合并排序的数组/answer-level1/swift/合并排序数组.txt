### 解题思路
- 暴力解法

### 代码
```
class Solution {
    func merge(_ A: inout [Int], _ m: Int, _ B: [Int], _ n: Int) {
        var res = [Int]()  
        for(index, value) in A.enumerated() {
            if index > m - 1  {
                res.append(contentsOf: B)
                break
            }
            res.append(value)
        }
        A = res
        A.sort { return $0 < $1 }
    }
}
```
- 双指针解法

```swift
class Solution {
    func merge(_ A: inout [Int], _ m: Int, _ B: [Int], _ n: Int) {
        var a = m - 1
        var b = n - 1
        var cur = m + n - 1
        while a >= 0 && b >= 0 {
            if A[a] < B[b] {
                A[cur] = B[b]
                b -= 1
            } else {
                A[cur] = A[a]
                a -= 1
            }
            cur -= 1
        }   
        // 遍历B中剩余的元素，全部添加到数组A中
        if b != -1 {
            for i in 0...b {
                A[i] = B[i]
            }
        }
       
    }
}
```
