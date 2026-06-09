swift 版本

```
class Solution {
    var dict = [Int: Int]()
    var post = [Int]()
    
    func buildTree(_ inorder: [Int], _ postorder: [Int]) -> TreeNode? {
        
        for i in (0 ..< inorder.count) {
            dict[inorder[i]] = i
        }
        
        post = postorder
        
        return buildTreeHelper(0, inorder.count-1, 0, postorder.count-1);
    }
    
    func buildTreeHelper(_ i_start: Int, _ i_end:Int, _ po_start: Int, _ po_end:Int) -> TreeNode? {
        
        if i_end < i_start  || po_end < po_start {
            return nil
        }
        
        let root_val = post[po_end]
        var root = TreeNode(root_val)
        //在中序遍历中找到根节点的位置
        let in_root_index = dict[root_val]!
        
        let leftNum = in_root_index - i_start
        //递归的构造左子树
        root.left = buildTreeHelper(i_start, in_root_index - 1, po_start, po_start + leftNum - 1)
            //递归的构造右子树
        root.right = buildTreeHelper(in_root_index + 1, i_end,  po_start + leftNum, po_end - 1)
        
        return root;
    }
}
```
