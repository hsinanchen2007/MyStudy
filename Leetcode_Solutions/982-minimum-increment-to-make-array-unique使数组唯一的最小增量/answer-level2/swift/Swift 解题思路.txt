### 解题思路
此处撰写解题思路
- 计算数组里面各个 num 出现的次数，存到 dic 中，并得出最大的数 max。
- 从0开始遍历到 max，在 dic 中查询该数 num 是不是出现超过1次。
    - 如果超过，统一将这几个数都+1，即 dic[num + 1] 需要加上 dic[num] - 1
    - 当然，移动的次数也需要加上 dic[num] - 1
- 以此类推，最后多余重复的数值都在 max 上
    - 如果 dic[max] > 1，那么将多作的数进行加法运算 max + 1, max + 2...
### 代码

```swift
class Solution {
    func minIncrementForUnique(_ A: [Int]) -> Int {
        var result = 0
        var dic = [Int: Int]()
        var max = 0
        //先计算每个num出现的次数，并算出数组里最大的num
        for num in A {
            dic[num] = (dic[num] ?? 0) + 1
            max = (max > num ? max : num)
        }
        
        //如果num 有相同的，就将其拿出来，并所有的+1。
        for i in 0..<max {
            if (dic[i] ?? 0) > 1 {
                result = result + dic[i]! - 1
                dic[i+1] = (dic[i+1] ?? 0) + dic[i]! - 1
            }
        }
        //最后重复的都移到了 max 上
        if (dic[max] ?? 0) > 1 {
            //需要将其 + 1，+2，+3,...+dic[max] - 1
            let total = Double(dic[max]! - 1)
            result = Int(Double(result) + (1 + total) * (total / 2.0))
        }
        return result
    }
}
```