一开始不会，看了别人的解法又去看了[739每日温度](https://leetcode-cn.com/problems/daily-temperatures/)，了解了一下啥叫单调栈，做完这题再去做85题。
```
class Solution {
    func largestRectangleArea(_ heights: [Int]) -> Int {
        let n = heights.count
        var hei = heights
        hei.append(-1)
        var stack = [Int]()
        var res = 0
        for i in 0...n {
            let cur = hei[i]
            while stack.count > 0 && cur < hei[stack.first!] {
                let topI = stack.first!
                stack.removeFirst()
                res = max(res, hei[topI]*(stack.count == 0 ? i : i - stack.first! - 1))
            }
            stack.insert(i, at: 0)
        }
        return res
    }
}
```