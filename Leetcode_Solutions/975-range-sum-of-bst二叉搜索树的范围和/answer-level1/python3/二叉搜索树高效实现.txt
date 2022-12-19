一 算法分析与设计
对树进行深度优先搜索，当当前节点值在闭区间[L, R]上时，累加该结点值，并递归处理其左右子结点；当该结点值小于L时，只需处理其右子树；当该节点值大于R时，只需处理其左子树。
为提升算法性能，仅在左右子结点非空时，对其进行递归调用。
二 算法实现
```C++ []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root)
            return 0;
        dfs(root, L, R);
        return ans;
    }
    void dfs(TreeNode* p, int L, int R){
        int val = p->val;
        if (val >= L && val <= R){
            ans += val;
            if (p->left)
                dfs(p->left, L, R);
            if (p->right)
                dfs(p->right, L, R);
        }
        else if (val < L && p->right){
            dfs(p->right, L, R);
        }    
        else if (val > R  && p->left){
            dfs(p->left, L, R);
        }else{
            
        }
    }
};
```
```python3 []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:        
        ##non recursive method
        #ans = 0
        #st = []
        #if root:
        #    st = [root]
        #while st:
        #    node = st.pop()
        #    val = node.val
        #    if val >= L and val <= R:
        #        ans += val
        #    if L < val and node.left:
        #        st.append(node.left)
        #    if R > val and node.right:
        #        st.append(node.right)
        #return ans
        
        
        def dfs(node, L, R):
            val = node.val
            if val >= L and val <= R:
                self.ans += val
            if L < val and node.left:
                dfs(node.left, L, R)
            if R > val and node.right:
                dfs(node.right, L, R)
                
        if root is None:
            return 0
        self.ans = 0
        dfs(root, L, R)
        return self.ans
```
三 时空复杂度
时间复杂度O(N)
空间复杂度O(H)
