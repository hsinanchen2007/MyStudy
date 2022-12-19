### 解题思路
所有思路都写在代码注释里了，算是随着做题自己加入的一些理解的笔记，我觉得这种形式可能会比先讲再甩代码来的好一些！~
递龟：
时间复杂度O(n)，建立哈希表是O(n)的，preorder每个节点会在递归的时候访问一次，是O(n)的，总体是O(2n)，忽略常数值还是O(n)
空间复杂度O(n)，哈希表和递归栈空间各使用了O(n)的空间
迭代：
时间复杂度O(n)，preorder每个节点会访问一次，同时inorder每个节点也会被访问一次，2个O(n)
空间复杂度O(n)，仅用了栈空间，1个O(n)

PS！下一题题解我也有分享双解法！大家可以重点看一下两道题解法的差异！其实整体是一样的，但是有些小细节真的很值得考究，我认为理解了差异对二叉树和三个遍历方法了解会深很多了！

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
    vector<int> inorder, preorder;
    unordered_map<int, int> indexMap;
    int preIndex = 0;
    
    TreeNode* builder(int mostLeft, int mostRight) {
        // 递龟法是自顶向下的，每次求取当前节点然后求取子节点
        // 而子节点的求取依赖根节点传下来的最左和最右限制值，还有当前节点在中序的下标值
        // 这样才能继续构建下面的左右子树
        
        // 中序的最左和最右分别是左右的最远叶子节点
        if (mostLeft > mostRight) return nullptr;
        
        // 从先序中获取节点值（第一个一定是根节点，然后就可以构建左右子树了）
        int curVal = preorder[preIndex];
        ++preIndex; // 递增，下一层递龟就是下一个节点
        TreeNode* cur = new TreeNode(curVal);
        
        // 构建左右子树
        // 先构建左子树（先序遍历的开头是先是左节点）
        // 而中序遍历是左-中-右的结构，所以通过值索引到下标后就可以开始构建了
        // 换句话说，中序遍历找到一个节点后就能知道这个值的左边一定是它的左子树的节点
        // 而右边就是它的右子树节点
        // mostLeft和mostRight就是用来限制这一层左右子树的范围的，巧妙！
        cur->left = builder(mostLeft, indexMap[curVal] - 1);
        // 再去构建右子树（这时先续遍历的下一位就是右节点了，因为左节点在上一步已经被吃干净了）
        cur->right = builder(indexMap[curVal] + 1, mostRight);
        return cur;
    }
    
    TreeNode* builderStack() {
        // 迭代法是自底向上的，每次迭代不要求从上面传下来的值
        // 反而需要先解决子问题后才可以解决父问题
        // 换句话说就是得先构建完最远的叶子，然后一步一步往上回溯，最后回到根节点
        // 所以迭代法不需要保存mostLeft和mostRight节点，也不需要知道下标的位置
        
        // 获取最根节点值 并构建该节点
        int rootVal = preorder[preIndex];
        ++preIndex;
        TreeNode* root = new TreeNode(rootVal);
        
        // 根节点入栈，迭代构建左右子树
        stack<TreeNode*> travelStack;
        travelStack.push(root);
        // 迭代终止条件是preIndex == preorder.size()，证明所有节点遍历完成
        for (int preIndex = 1, inIndex = 0; preIndex < preorder.size(); ++preIndex) {
            TreeNode* tmp = nullptr;
            while (!travelStack.empty() && travelStack.top()->val == inorder[inIndex]) {
                // 循环条件：栈不为空，且栈顶刚好是中序的第i个节点
                // 中序定义：一颗完整的树（左右孩子均有）第一个节点是左节点 然后是根节点，最后是右节点
                // 为什么是while不是if：while可以保证连续地弹出栈顶节点
                // 如果栈顶的元素是中序的第i个元素，那么证明已经构建到当前的位置了
                // 换句话说就是左子树已经全部构建完毕了，那么接下来的节点一定是右子树
                // 否则的话不会进入循环，tmp是空值，那么证明这个节点的左子树还没有构建完成
                ++inIndex;
                tmp = travelStack.top();
                travelStack.pop();
            }
            
            // 获取先序的下一个节点值，构建节点
            TreeNode* cur = new TreeNode(preorder[preIndex]);
            
            // 先序节点获取的顺序是根-左-右的，tmp的取值在while循环内已经阐述过了
            if (tmp == nullptr) {
                // 如果是空值，那么证明栈顶元素的左子树还没有构建完成，继续构建左子树
                // 换句话说就是刚刚构建的cur节点一定是栈顶的左子叶
                travelStack.top()->left = cur;
            } else {
                // 否则栈顶的左子树已经完成了，而刚刚构建的cur是栈顶的右子叶
                tmp->right = cur;
            }
            // 将这个子叶压栈，循环检查
            travelStack.push(cur);
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->inorder = inorder;
        this->preorder = preorder;
        
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
}; // test case [1,2,4,8,9,5,10,3,6,7] [8,4,9,2,10,5,1,6,3,7]
```