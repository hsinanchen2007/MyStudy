```swift
class Solution {
    func triangleNumber(_ nums: [Int]) -> Int {
        //三角形边长不能为0
        let notZeroNums = nums.filter {$0 > 0}
        guard notZeroNums.count > 2 else {
            return 0
        }
        
        //统计数字出现次数
        let maxEle = notZeroNums.max()!
        var counter = Array<Int>(repeating: 0, count: maxEle + 1)
        //可能边长
        var edgesLength = Set<Int>()
        for ele in notZeroNums {
            counter[ele] += 1
            if !edgesLength.contains(ele) {
                edgesLength.insert(ele)
            }
        }
        //统计小于i的数字出现次数
        var sumCounter = Array<Int>(repeating: 0, count: maxEle + 1)
        for i in 1..<sumCounter.count {
            sumCounter[i] = sumCounter[i - 1] + counter[i]
        }
        
        //排序,方便枚举最短的两条边
        let sortedEdgesLenth = edgesLength.sorted()
        var ans = 0
        //等边，排列组合,出现次数选3
        for edgeLength in sortedEdgesLenth {
            if counter[edgeLength] >= 3 {
                let c = counter[edgeLength]
                ans += c * (c - 1) * (c - 2) / 6
            }
        }
        //等腰，排列组合,出现次数选2再加上另外一条边
        for edgeLength in sortedEdgesLenth {
            if counter[edgeLength] >= 2 {
                let c = counter[edgeLength]
                ans += c * (c - 1) / 2 * (sumCounter[min(edgeLength << 1 - 1,maxEle)] - counter[edgeLength])
            }
        }
        guard sortedEdgesLenth.count >= 3 else {
            return ans
        }
        //一般三角形,枚举最小的两条边，则第三边满足：max(a,b)  < c < (a + b - 1)。
        for i in 0..<(sortedEdgesLenth.count  - 2) {
            for j in (i + 1)..<(sortedEdgesLenth.count - 1){
                let a = sortedEdgesLenth[i]
                let b = sortedEdgesLenth[j]
                ans += counter[a] * counter[b] * (sumCounter[min(a + b - 1,maxEle)] - sumCounter[b])
            }
            
        }
        return ans
    }
}
```
