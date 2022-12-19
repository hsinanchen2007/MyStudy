
时间很慢，因为我一直在创建Array...赶时间下次再优化
```
class Solution {
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        if preorder.count == 0 {
            return nil
        }
        
        let midVal = preorder[0]
        let res = TreeNode(midVal);
        let midIndex = inorder.firstIndex(of: midVal)
        if midIndex == nil {
            return nil
        }
        
        let lpl = preorder.startIndex + 1
        let lpr = preorder.index(preorder.startIndex, offsetBy: midIndex!)
        let lil = inorder.startIndex
        let lir = inorder.index(inorder.startIndex, offsetBy: midIndex! - 1)
        if lpl <= lpr && lil <= lir {
            let npreorder = preorder[lpl...lpr]
            let ninorder = inorder[lil...lir]
            res.left = buildTree(Array(npreorder), Array(ninorder))
        }
        
        let rpl = preorder.index(preorder.startIndex, offsetBy: midIndex! + 1)
        let rpr = preorder.endIndex
        let ril = midIndex! + 1
        let rir = inorder.endIndex
        if rpl < rpr && ril < rir {
            let nrpreorder = preorder[rpl..<rpr]
            let nrinorder = inorder[ril..<rir]
            res.right = buildTree(Array(nrpreorder), Array(nrinorder))
        }
        return res;
    }
}
```