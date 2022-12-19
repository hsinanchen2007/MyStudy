### 解题思路
利用hash表排序后映射

### 代码

```swift
class Solution {
    func findRelativeRanks(_ nums: [Int]) -> [String] {
        
        //初始化一个字典用来记录每个运动员的成绩和相对名次
        var map = [Int:String]()
        
        //遍历经过排序后的原数组，将每个运动员的成绩和相对名次插入到字典中
        for (index, value) in nums.sorted(by: >).enumerated() {
            
            switch index {
            case 0:
                map.updateValue("Gold Medal", forKey: value)
            case 1:
                map.updateValue("Silver Medal", forKey: value)
            case 2:
                map.updateValue("Bronze Medal", forKey: value)
            default:
                map.updateValue(String(index + 1), forKey: value)
            }
        }
        
        //初始化返回值
        var result = [String]()
        
        //遍历未经排序的原数组，根据字典中的信息依次输出每个运动员的相对名次
        for num in nums {
            if let rank = map[num] {
                result.append(rank)
            }
        }
        
        return result
    }
}
```