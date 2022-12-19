### 解题思路
非常感谢@labuladong在[46题全排列中对于回溯方法的详解](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/)，这道题就是就是在回溯方法的基础之上加入了重复条件的判断，所以加入了一个visted数组，同时为了方便找到重复的字符，在进行寻找之前将数组进行排序，这样利用s[i]与s[i-1]就可以很好的判断重复条件。其他过程与常规回溯算法模型一致。

### 代码

```swift
class Solution {
    // 1. 创建两个用来保存结果和中间选择过程的值。创建一个viseted数组来进行判断是否已经访问过
    var paths: [String] = []
    var path: String = ""

    func permutation(_ s: String) -> [String] {
        // visited变量无法定义在外部，因为如果要定义在外部就需要对S进行一次遍历，浪费效率。
        var visited = Array.init(repeating: false, count: s.count)

        // 因为需要进行重复查询，所以将字符串进行排序
        // 同时也需要将字符串转为数组
        // 因为在Swift里面String.sorted方法的返回值正好为[Character]类型，所以不需要重新再进转变
        var sArray = s.sorted()
       
        // 2. 实现回溯算法  
        backtrack(sArray, &visited)
        return paths
    }

    func backtrack(_ s: [Character], _ visited: inout [Bool]) {
        // 3. 判断结束条件
        if path.count == s.count {
            paths.append(String(path))
        }

        for i in 0..<s.count {
            // 4. 排除不合法选择
            if visited[i] == true {
                continue
            }

            if i > 0 && s[i] == s[i-1] && visited[i-1] == true {
                continue
            }

            // 5. 做出选择
            visited[i] = true
            path.append("\(s[i])")

            // 6. 进行深层次选择
            backtrack(s, &visited)
            
            // 7. 撤销选择
            path.removeLast()
            visited[i] = false
        }
    }
}
```