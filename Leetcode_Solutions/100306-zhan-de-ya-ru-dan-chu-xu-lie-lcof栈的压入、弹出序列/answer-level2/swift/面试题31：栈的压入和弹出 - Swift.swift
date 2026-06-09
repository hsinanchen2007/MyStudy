```
class Solution {
    func validateStackSequences(_ pushed: [Int], _ popped: [Int]) -> Bool {
        if pushed.count == 0 || popped.count == 0 {
            return true
        }
        var helpStack = [Int]()
        var popped = popped
        var j = 0
        var i = 0
        for item in pushed {
            helpStack.append(item)
            var popIndex = popped.index(popped.startIndex, offsetBy: j)
            while !helpStack.isEmpty && j < popped.count && helpStack.last == popped[popIndex] {
                helpStack.removeLast()
                j += 1
                popIndex = popped.index(popped.startIndex, offsetBy: j)
            }
            i += 1
        }
        return helpStack.isEmpty
    }
}
```

//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass