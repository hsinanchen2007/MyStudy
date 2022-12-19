### 解题思路

枚举

### 代码

```swift
class Solution {
    func getNoZeroIntegers(_ n: Int) -> [Int] {
        
        //定义返回数组
        var ans = [Int]()
        
        //因为题目规定输入值不小于2，所以从1开始枚举
        for num in stride(from: 1, through: n, by: 1) {
            //将当前枚举的两个数字转换为string类。利用contains方法查看他们有没有0
            let temp = String(num) + String(n - num)
            if !temp.contains("0") {
                ans.append(contentsOf: [num,n-num])
                break
            }
        }
        
        return ans
        
    }
}
```