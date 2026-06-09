![image.png](https://pic.leetcode-cn.com/0dc384470c07f9448a5fd840e0c3985f4f7da970739cd7c9b712c50898db4e88-image.png)

```
class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        var resultArray: [[Int]] = [[]]
        for num in nums {
            var newArray: [[Int]] = [] // 空数组准备好了
            for subArray in resultArray { // 遍历记录的数组，准备往上面填数据
                if subArray.count == 0 {
                    newArray.append([num])
                } else {
                    for index in 0..<(subArray.count + 1) {
                        let reversedIndex = subArray.count - index
                        var mutableSubArray = subArray
                        mutableSubArray.insert(num, at: reversedIndex)
                        newArray.append(mutableSubArray)
                    }
                }
            }
            // 删除旧数据，填充新数据
            resultArray.removeAll()
            resultArray += newArray
        }
        
        return resultArray
    }
}
```
