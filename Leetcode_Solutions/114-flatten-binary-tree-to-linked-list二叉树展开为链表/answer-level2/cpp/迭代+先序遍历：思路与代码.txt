思路：
1. 首先观察题目给的链表形式，链表是按照二叉树先序遍历来展开的，为了得到答案，一个自然的想法便是我们也采用同样的先序遍历来模拟这个过程
2. 在遍历中需要做什么？ 观察题目的样例，先序遍历中的前一个节点需要在右节点中连接先序遍历中的下一个节点，而左节点需要置空

基于以上两点，我们便可以很轻松完成代码的书写了，整体来说需要做的条件判断并不多，这里因为我比较熟悉迭代加之比较高效，选择用迭代加以完成：


```python []
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        #先序遍历
        dummy = TreeNode(0)
        prev = dummy
        stack = [root]
        while stack:
            rt = stack.pop()
            if not rt:
                continue
            prev.right = rt
            prev.left = None

            stack.append(rt.right)
            stack.append(rt.left)
            prev = rt
        prev.left = None
```
```C++ []
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode *> state(1,root);
        TreeNode * dummy = new TreeNode(0);
        TreeNode * prev = dummy;

        while(state.size()>0){
            TreeNode * rt;
            rt = state.back(); state.pop_back();
            if(!rt) continue;
            prev->right = rt;
            prev->left = NULL;
            prev = rt;
            state.push_back(rt->right); 
            state.push_back(rt->left);           
        }
        prev->left = NULL;
    }
};
```
