### 解题思路
执行用时 :20 ms, 在所有 cpp 提交中击败了91.24%的用户
内存消耗 :13.3 MB, 在所有 cpp 提交中击败了96.83%的用户

因为之前学证明的关系，比较喜欢用递归来解决树的问题。也写了dp求size的那题过来的。所以感觉上应该n和n-1的解答是有关系的。 
本来以为的n的结果是对于所有的n-1的结果， 在其根部加上n 和在整个树里面插入n。所以返回的结果的数组长度是2^n (2的n次方)， 但是很明显漏答案了。 
有其他的人在题解里面提醒，其实在树里面插入n的方式是所有右链上的每个端点都可以插入n。我之前漏了这个情况，加上就过了。（这里隐含了n是大于树里面所有的节点，不过这是可以证明的）  

#### 内存泄漏
很多答案会泄漏内存，比如永远插入一个复制出来的新树，或者用一个很大的vector。这个vector是在递归的最底层new的，一直复用到返回。每个生成的树都会保留，用asRoot来把n加到根上，重新放在数组原来的位置上。  


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
    TreeNode* copyTree(TreeNode * root){
        if(!root) return root; // !root ==> root == NULL 所以我们在这里是return null
        auto ret = new TreeNode(root->val);
        // 复制子树， 如果子树是null，这个函数会返回null
        ret->left = copyTree(root->left);
        ret->right = copyTree(root->right);
        return ret;
    }

    TreeNode* asRoot(TreeNode *root, int val) {
        // 根永远是传进来的新数字
        TreeNode* ret = new TreeNode(val);
        if (!root) return ret; 
        // 把传入的树依据大小插入在根上 （我表示我没开车）
        if (root->val > val) ret->right = root;
        else ret->left = root; 
        // 返回新的根
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        // n == 0 返回空
        if (!n) return {};
        // n == 1 返回一个种子数组，只有节点为1的树的数组。
        if (n == 1) return vector<TreeNode *>(1, new TreeNode(n));
        // 拿到n-1的答案
        auto ret = generateTrees(n-1);
        // 因为我们会一直往数组里面添加东西，所以把这个大小固定下来
        size_t size = ret.size();

        // 在右链上的每个节点插入n
        for (size_t i = 0; i < size; i ++){
            // depth是右链插入的深度
            // flag是代表对于右链深度为depth的节点，还有没有有右子节点
            // 如果没有的话，那么我们的右链插入的情况就都遍历到了
            bool flag = true;

            for (size_t depth = 0; flag; depth ++) {
                auto copied = copyTree(ret[i]);

                // 根据depth找到这次要插入的节点
                auto curr = copied;
                for (size_t j = 0; j < depth; j ++) curr = curr->right;
                // curr->right == (curr->right != NULL) 检查下个depth 还能不能插入
                flag = (curr->right);

                // 在这个节点的右链上插入n
                curr->right = asRoot(curr->right, n);
                // 记录一种全新的情况
                ret.push_back(copied);
            }

            // 对于每个树，我在他的根上插入新的n
            ret[i] = asRoot(ret[i], n);
        }
        return ret; 
    }
};
```