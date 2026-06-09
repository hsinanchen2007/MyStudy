```bash
[9,3,15,20,7]
[9,15,7,20,3]
```
1. 用L表示左子树，P代表根，R代表右子树。
2. 中序序列可表示为 LPR, 后序序列可表示为 LRP。
3. 后序序列的最后一个元素是二叉树的根，如3。
4. 根据根的值可以把中序序列分为两部分[9]和[3,15,20, 7]。
5. 中序两部分元素个数分别为1，4.
6. 根据中序元素个数把后续分为两部分[9]和[15, 7, 20, 3]。
7. 用中序和后序对应的部分分别创建树的左子树和右子树。

```c++ []
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {        
        return buildTree(rbegin(inorder), rend(inorder),
                         rbegin(postorder), rend(postorder));
    }
    
    template<typename RandomIt>
    TreeNode* buildTree(RandomIt in_rfirst, RandomIt in_rlast,
                        RandomIt post_rfirst, RandomIt post_rlast) {
        if (in_rfirst == in_rlast) return nullptr;
        if (post_rfirst == post_rlast) return nullptr;
        
        auto root = new TreeNode(*post_rfirst);
        
        auto inRootRPos = find(in_rfirst, in_rlast, *post_rfirst);
        auto RightSize = distance(in_rfirst, inRootRPos);
        
        root->right = buildTree(in_rfirst,
                                next(in_rfirst, RightSize),
                                next(post_rfirst),
                                next(post_rfirst, RightSize + 1));
        root->left = buildTree(next(inRootRPos),
                               in_rlast,
                               next(post_rfirst, RightSize + 1),
                               post_rlast);
        return root;
    }
};
```
```python []
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        
        def helper(il, ir, pl, pr):
            if (il == ir or pl == pr):
                return None
        
            root = TreeNode(postorder[pr-1])
            inRootPos = inorder.index(root.val, il, ir)
            rightSize = ir - inRootPos
            
            root.right = helper(inRootPos + 1, ir, pr - rightSize, pr - 1)
            root.left = helper(il, inRootPos, pl, pr - rightSize)
            return root
            
        return helper(0, len(inorder), 0, len(postorder))
```