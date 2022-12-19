### 解题思路

桶思想，放入后，取出指定个非零项即可

### 代码

```swift
class Solution {
    func getLeastNumbers(_ arr: [Int], _ k: Int) -> [Int] {
        let len = arr.count
        if (len == k) {
            return arr;
        }
        if (k == 0) {
            return [];
        }
        
        var res:[Int] = Array(repeating: 0, count: k)
        var bucket:[Int] = Array(repeating: 0, count: 10001)
        for i in arr {
            bucket[i] += 1
        }
        
        // 循环遍历，输出指定的 k个数 即可
        var count = 0
        for i in 0..<len {
            while bucket[i] != 0 {
                res[count] = i
                count += 1
                bucket[i] -= 1
                if count == k {
                    return res
                }
            }
        }

        return res;
    }
}
```