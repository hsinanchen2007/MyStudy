### 解题思路
本质上是求A-B的最小值

### 代码

```swift


class Solution {
    func twoCitySchedCost(_ costs: [[Int]]) -> Int {

        //将原嵌套数组按各个子数组的元素差排序成新嵌套数组
        let temp = costs.sorted(by: {$0[0] - $0[1] < $1[0] - $1[1]})

        var ans = 0

        //遍历新数组，让前一半人去A市，后一半人去B市
        for (index,arr) in temp.enumerated() {
            if index < temp.count / 2 {
                ans += arr[0]
            } else {
                ans += arr[1]
            }
        }
        
        
        return ans
    }
}

```