### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
func threeSum(_ nums: [Int]) -> [[Int]] {
    //小于三个时，不能成立
    guard nums.count >= 3 else { return [] }
    // 把数组转换为字典， 元素的值为Key  元素在数组里面的数量作为Value
    let array = nums.reduce(into: [Int: UInt]()) { (result, element) in
        var value = result[element, default: 0]
        value += 1
        result[element] = value
    }
        // 排序
    .sorted { $0.key < $1.key }

    //利用set 和 dic 的特性做去重
    let set = array.reduce(into: Set<[Int: Int]>()) { (result, element) in
        let currentKey = element.key
        
        //如果当前元素是0， 看其数量够不够3个
        if currentKey == 0 && element.value > 2 {
            result.insert([0: 3])
            return
        }
        
        //有序数组，双指针由两边向中间遍历
        var left = array.startIndex
        var right = array.endIndex - 1
        
        while left < right {
            let leftKey = array[left].key
            let rightKey = array[right].key
            
            //当有两个值相等，并且这个元素在数组里面的数量小于2个，是不能成立的
            if (leftKey == currentKey && element.value < 2) {
                left += 1
                continue
            }
            
            //当有两个值相等，并且这个元素在数组里面的数量小于2个，是不能成立的
            if rightKey == currentKey && element.value < 2 {
                right -= 1
                continue
            }
            
            //当前数组是有序的，如果等式成立，left和rigt要同时移动
            if currentKey + leftKey + rightKey == 0 {
                
                //包装成字典，便于set去重
                let dic = [currentKey, leftKey, rightKey].reduce(into: [Int: Int]()) { (result2, element2) in
                    var value2 = result2[element2, default: 0]
                    value2 += 1
                    result2[element2] = value2
                }
                result.insert(dic)
                
                left += 1
                right -= 1
                // < 0 left 指针右移
            } else if currentKey + leftKey + rightKey < 0 {
                left += 1
                // > 0 right指针左移
            } else if currentKey + leftKey + rightKey > 0 {
                right -= 1
            }
        }
    }
    return Array(set.map { $0.reduce([Int]()) { $0 + [Int](repeating: $1.key, count: $1.value) } })
}
}
```