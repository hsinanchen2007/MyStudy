### 解题思路
我知道双指针更简单，但生活中哪有那么多事先帮你排序好的数组！

### 代码

```swift
class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        
        //初始化一个字典用来存储数组中的元素和其对应的下标
        var map = [Int:Int]()
        var ans = [Int]()
        
        //遍历原数组，如果能在字典中找到target与当前元素差值的存在，则说明当前元素和字典中存储的下标对应的元素满足题意
        for (index,num) in numbers.enumerated() {
            
            if let otherIndex = map[target - num]{
                ans.append(contentsOf: [otherIndex + 1, index + 1])
            } else {
                map.updateValue(index, forKey: num)
            }
        }


        
        return ans
    }
}
```