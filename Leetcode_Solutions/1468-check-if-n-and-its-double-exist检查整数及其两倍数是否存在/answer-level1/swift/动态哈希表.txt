### 解题思路
动态哈希表

### 代码

```swift
class Solution {
    func checkIfExist(_ arr: [Int]) -> Bool {
        
        //时间换空间，初始化一个字典用于存储原数组的相关信息
        var map = [Int:Int]()
        
        //遍历原数组，看当前访问的元素是否在字典里存在它的2倍或者1/2的数(这里要注意必须能整除)存在，
        //有则返回，无则将当前元素插入到字典中
        for num in arr {
            
            if map[num * 2] != nil || (num % 2 == 0 && map[num / 2] != nil) {
                return true
            } else {
                
                map.updateValue(1, forKey: num)
            }
            
        }

        
        return false
    }
}
```