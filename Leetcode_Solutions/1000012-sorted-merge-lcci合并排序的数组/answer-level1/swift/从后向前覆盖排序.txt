### 解题思路
合并两个已排序的数组A,B, 其中A末端有足够的空间容纳B.
因为是已经排好序的, 所以如果在A原地排序, 从前向后必然需要移动其余元素腾出来位置
如果是从后向前排序, 则可以把A看成空容器,直接覆盖

### 代码

```swift
class Solution {
    func merge(_ A: inout [Int], _ m: Int, _ B: [Int], _ n: Int) {
        var ai = m - 1
    var bi = n - 1
    
    var i = m + n - 1
    
    while ai>=0 && bi>=0 {
        
        if A[ai] >= B[bi] {
            A[i] = A[ai]
            
            ai -= 1
        }else {
            A[i] = B[bi]
            
            bi -= 1
        }
        
        i -= 1
    }
    
    if ai < 0 {
        while !(bi<0) {
            A[i] = B[bi]
            
            bi -= 1
            i -= 1
        }
        return
    }
    
    if bi < 0 {
        while !(ai<0) {
            A[i] = A[ai]
            
            ai -= 1
            i -= 1
        }
        return
    }
    }
}
```