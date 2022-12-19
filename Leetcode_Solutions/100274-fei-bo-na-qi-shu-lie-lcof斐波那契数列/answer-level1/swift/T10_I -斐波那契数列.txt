### 解题思路
直接使用递归会超时，所以需要将中间结果用数组保存下来即可。

### 代码

```swift
class Solution {
    var result: [Int] = []
    
    func fib(_ n: Int) -> Int {
        self.result.append(0)
        self.result.append(1)
        
        var index = 2
        while index <= n {
            // 记得Swift的大数可以加_表示。
            var temp = (self.result[index-1] + self.result[index-2]) % 10_0000_0007
            self.result.append(temp)
            index += 1
        }
        
        return self.result[n]
        

    }
}
```