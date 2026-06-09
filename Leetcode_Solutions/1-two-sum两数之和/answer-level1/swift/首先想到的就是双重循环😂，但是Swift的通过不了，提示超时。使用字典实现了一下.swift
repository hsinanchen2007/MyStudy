```
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic = [Int:Int]()
        for (idx, val) in nums.enumerated() {
            let temp = target-val
            if dic.keys.contains(temp) {
                return [dic[temp]!,idx]
            }
            dic[val] = idx
        }
        return []
    }
}
```
