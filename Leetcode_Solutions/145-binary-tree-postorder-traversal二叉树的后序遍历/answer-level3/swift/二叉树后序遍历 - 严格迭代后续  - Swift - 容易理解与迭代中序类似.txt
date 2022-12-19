```
class Solution {
    var res = [Int]()
    func postorderTraversal(_ root: TreeNode?) -> [Int] {
        if root == nil {return []}
        var stack = [TreeNode]()
        var cur = root
        while cur != nil || !stack.isEmpty {
            while cur != nil {
                stack.append(cur!)
                cur = cur!.left
            }
            let temp = stack.last!
            if temp.right == nil { //右边的节点为nil，才赋值
                stack.removeLast()
                res.append(temp.val)
            } else { //不为nil，那么压栈右边的，记得把temp.right置为nil，记录已经处理过了，不然无穷无尽了。
                cur = temp.right
                temp.right = nil
            }
        }
        return res
    }
}
```
//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass