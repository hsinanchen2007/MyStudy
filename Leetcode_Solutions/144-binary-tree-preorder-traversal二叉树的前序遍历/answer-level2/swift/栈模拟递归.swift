1 用数组来充当栈
2 由于是用栈，虽然是DLR 遍历在 child入栈的时候是先入R child 再入L child。
var arr:[Int] = []
    
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        helper144_2(root)
        return arr
    }
    
    func helper144_2(_ root:TreeNode?) {
        if let t = root {
            var nodes:[TreeNode] = []
            nodes.append(t)
            while nodes.count > 0 {
                let node = nodes.removeLast()
                arr.append(node.val)
                if let nr = node.right {
                    nodes.append(nr)
                }
                if let nl = node.left {
                    nodes.append(nl)
                }
            }
        }
    }