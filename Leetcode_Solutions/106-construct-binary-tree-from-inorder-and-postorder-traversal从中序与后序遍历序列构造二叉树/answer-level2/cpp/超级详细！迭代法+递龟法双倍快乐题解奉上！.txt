### 解题思路
所有思路都写在代码注释里了，算是随着做题自己加入的一些理解的笔记，我觉得这种形式可能会比先讲再甩代码来的好一些！~
递龟：
时间复杂度O(n)，建立哈希表是O(n)的，postorder每个节点会在递归的时候访问一次，是O(n)的，总体是O(2n)，忽略常数值还是O(n)
空间复杂度O(n)，哈希表和递归栈空间各使用了O(n)的空间
迭代：
时间复杂度O(n)，postorder每个节点会访问一次，同时inorder每个节点也会被访问一次，2个O(n)
空间复杂度O(n)，仅用了栈空间，1个O(n)

### 代码

```cpp
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
    vector<int> inorder, postorder;
    unordered_map<int, int> indexMap;
    
    TreeNode* builder(int mostLeft, int mostRight) {
        // 递龟法是自顶向下的，每次求取当前节点然后求取子节点
        // 而子节点的求取依赖根节点传下来的最左和最右限制值，还有当前节点在中序的下标值
        // 这样才能继续构建下面的左右子树
        
        // 中序的最左和最右分别是左右的最远叶子节点
        if (mostLeft > mostRight) return nullptr;
        
        // 从后序中弹出节点值（第一次一定是根节点，然后就可以构建左右子树了）
        int curVal = postorder.back();
        postorder.pop_back();
        TreeNode* cur = new TreeNode(curVal);
        
        // 构建左右子树
        // 先构建右子树（后序遍历的尾巴是先是右节点）
        // 而中序遍历是左-中-右的结构，所以通过值索引到下标后就可以开始构建了
        // 换句话说，中序遍历找到一个节点后就能知道这个值的左边一定是它的左子树的节点
        // 而右边就是它的右子树节点
        // mostLeft和mostRight就是用来限制这一层左右子树的范围的，巧妙！
        cur->right = builder(indexMap[curVal] + 1, mostRight);
        // 再去构建左子树（这时后续遍历的尾巴就是左节点了）
        cur->left = builder(mostLeft, indexMap[curVal] - 1);
        return cur;
    }
    
    TreeNode* builderStack() {
        // 迭代法是自底向上的，每次迭代不要求从上面传下来的值
        // 反而需要先解决子问题后才可以解决父问题
        // 换句话说就是得先构建完最远的叶子，然后一步一步往上回溯，最后回到根节点
        // 所以迭代法不需要保存mostLeft和mostRight节点，也不需要知道下标的位置
        
        // 弹出最根节点值 并构建该节点
        int rootVal = postorder.back();
        postorder.pop_back();
        TreeNode* root = new TreeNode(rootVal);
        
        // 根节点入栈，迭代构建左右子树
        stack<TreeNode*> travelStack;
        travelStack.push(root);
        // 迭代终止条件是后序遍历节点全部弹出，证明遍历完成
        while (postorder.size()) {
            // 
            TreeNode* tmp = nullptr;
            while (!travelStack.empty() && travelStack.top()->val == inorder.back()) {
                // 循环条件：栈不为空，且栈顶刚好是中序的最后一个节点
                // 中序定义：一颗完整的树（左右孩子均有）最后一个节点是右节点，然后根节点，然后左节点
                // 为什么是while不是if：while可以保证连续地弹出栈顶节点
                // 如果栈顶的元素是中序的最后一个元素，那么证明已经构建到当前的位置了
                // 换句话说就是右子树已经全部构建完毕了，那么接下来的节点一定是左子树
                // 否则的话不会进入循环，tmp是空值，那么证明这个节点的右子树还没有构建完成
                inorder.pop_back();
                tmp = travelStack.top();
                travelStack.pop();
            }
            
            // 弹出后序的最后一个节点值，构建节点
            TreeNode* cur = new TreeNode(postorder.back());
            postorder.pop_back();
            
            // 后序节点弹出的值顺序是根-右-左的，tmp的取值在while循环内已经阐述过了
            if (tmp == nullptr) {
                // 如果是空值，那么证明栈顶元素的右子树还没有构建完成，继续构建右子树
                // 换句话说就是刚刚构建的cur节点一定是栈顶的右子叶
                travelStack.top()->right = cur;
            } else {
                // 否则栈顶的右子树已经完成了，而刚刚构建的cur是栈顶的左子叶
                tmp->left = cur;
            }
            // 将这个子叶压栈，循环检查
            travelStack.push(cur);
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        
        int tSize = this->inorder.size();
        if (tSize == 0) return nullptr;
        
        // recursive method
        // for (int i = 0; i < tSize; i++) {
        //     indexMap[this->inorder[i]] = i; 
        // }
        // return builder(0, tSize - 1);
        
        // iteration method
        return builderStack();
    }
};// test case [8,4,9,2,10,5,1,6,3,7] [8,9,4,10,5,2,6,7,3,1]
```