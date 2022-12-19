### 解题思路
效率不是很理想..
### 代码

```swift
class Solution {
    func replaceElements(_ arr: [Int]) -> [Int] {
        
        //定义一个返回数组
        var ans = [Int]()
        
        //分别定义两个变量用来表示当前找到的最大值以及该最大值的索引
        var indexOfNextMaxNum = 0
        var NextMaxNum = 0
        
        //循环遍历原数组
        for index in 0..<arr.count {
            //如果找到的元素已经是最后一个元素，则按要求返回-1
            if index == (arr.endIndex - 1) {
                ans.append(-1)
            } else {
                
                if index >= indexOfNextMaxNum {
                //如果当前指向的元素是之前已经找到的那个最大值，则在该值的右边重新查找下一个最大值及其索引，同时把找到的新的最大值加入返回值
                    NextMaxNum = arr[index+1..<arr.endIndex].max() ?? 0
                    indexOfNextMaxNum = arr.lastIndex(of: NextMaxNum) ?? 0
                }
                
                ans.append(NextMaxNum)
            }
            
            
        }

        
        return ans
    }
}
```