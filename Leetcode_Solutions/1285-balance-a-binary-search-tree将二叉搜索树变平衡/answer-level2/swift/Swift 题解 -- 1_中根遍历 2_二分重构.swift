

主要思路是
1:先通过中根遍历(search),得到一个节点值递增的数组
2:通过二分法构造(build)新的平衡树


class Solution {
    



    func balanceBST(_ root: TreeNode?) -> TreeNode? {
        if (root == nil){
            return nil
        }
        var nodeList = [TreeNode]()
        search(&nodeList, root!)
        let res = buildTree(nodeList, 0, nodeList.count-1)
        return res
    }

    func search(_ nodeList: inout [TreeNode], _ root: TreeNode) -> Void {
        if (root.left == nil){
            nodeList.append(root)
        }else{
            search(&nodeList, root.left!)
            nodeList.append(root)
        }
        if (root.right != nil){
            search(&nodeList, root.right!)
        }
    }
    
    func buildTree(_ nodeList: [TreeNode], _ left: Int, _ right: Int) -> TreeNode{
        if (left == right){
            return TreeNode.init(nodeList[left].val)
        }
        let mid = (left + right)/2
        let root = TreeNode.init(nodeList[mid].val)
        if (left <= mid - 1){
            root.left = buildTree(nodeList, left, mid-1)
        }
        if (mid + 1 <= right){
            root.right = buildTree(nodeList, mid+1, right)
        }
        return root
    }
}