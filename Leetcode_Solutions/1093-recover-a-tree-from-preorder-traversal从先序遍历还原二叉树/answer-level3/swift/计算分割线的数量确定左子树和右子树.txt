一开始看到这题的时候我认为要用栈去做，但是我发现直接递归就可以完成。每个val前的分割线数量可以确定左子树和右子树，接着把字符串分割为左半部分和右半部分，即左子树的部分和右子树的部分。

例如 "1-2--3--4-5--6--7"

那么可以确认的是当前的跟节点时**1**，而它的左子树是"2--3--4"，右子树是"5--6--7"，那么问题很简单了，我们只需要分割出这两个子字符串在进行递归调用即可。

值得注意的是题目要求**如果节点只有一个子节点，那么保证该子节点为左子节点。**，所有左子树的字符串为空时直接用右子树的字符串即可。

```
func recoverFromPreorder(_ S: String) -> TreeNode? {
    guard S.count > 0 else {
        return nil
    }
    var S = S
    var val = ""
    //获取根节点的val
    while !S.isEmpty && S.first! != "-" {
        val += String(S.removeFirst())
    }
    let head = TreeNode.init(Int(val)!)
    var lineCount = 0
    //计算分割线的数量
    while !S.isEmpty && !("0" <= S.first! && S.first! <= "9") {
        S.removeFirst()
        lineCount += 1
    }
    //以下为找到右子树，通过上面的分割线数量确定，左右子树前面的分割线数量是相等的
    var tmp = 0
    var leftEnd = 0
    var rightStart = 0
    let tmpS = Array(S)
    for i in 0..<tmpS.count {
        let c = tmpS[i]
        if c >= "0" && c <= "9" {
            if tmp == lineCount {
                leftEnd = i - tmp
                rightStart = i
                break
            }
            tmp = 0
        } else {
            tmp += 1
        }
    }
    //分割成两半递归就完事了
    let leftS = String(S[S.startIndex..<S.index(S.startIndex, offsetBy: leftEnd)])
    let rightS = String(S[S.index(S.startIndex, offsetBy: rightStart)..<S.endIndex])
    if leftS.isEmpty {
        head.left = recoverFromPreorder(rightS)
    } else {
        head.left = recoverFromPreorder(leftS)
        head.right = recoverFromPreorder(rightS)
    }
    return head
}
```