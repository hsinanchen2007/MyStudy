### 解题思路
去重排序哈希表

### 代码

```swift
class Solution {
    func arrayRankTransform(_ arr: [Int]) -> [Int] {
        
        //初始化一个字典用来存储排序后原数组的元素和序号
        var map = [Int:Int]()
        //初始化返回值
        var result = [Int]()
        
        //将去重且排序后的数组元素和其对应的序号插入字典
        for (index, num) in Set<Int>(arr).sorted(by: < ).enumerated() {
            
            map.updateValue(index + 1, forKey: num)
   
        }
        
        //将每个元素的序号按原数组的顺序添加到返回值
        for num in arr {
            result.append(map[num]!)
        }
        
        return result
    }
}
```