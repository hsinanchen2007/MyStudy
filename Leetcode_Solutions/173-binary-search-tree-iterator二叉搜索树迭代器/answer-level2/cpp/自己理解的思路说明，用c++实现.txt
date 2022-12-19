### 解题思路
二插搜索树、采用vector.back，循环方式实现中序遍历得到从小到大的值
1. **BSTIterator构造方法功能：保存最左边的一条路径，找最小节点**。具体：迭代循环遍历左子树，依次保存到数组中。最终存放整棵树最左边的节点，即最小值。
2. **next方法功能（中序遍历）：找出当前最小值，准备好下一个最小值**。具体：先取出最小值。然后以最小值为起点，中序遍历，对于存在右子树的情况，在右子树中迭代循环遍历左子树，依次保存到数组中，直到最左边的节点。返回最先取出的最小值
3. hasNext方法：判断数组是否为空，不为空则返回true，为空则返回false

扩展：1）还可以用stack方式实现中序遍历得到从小到大的值。好处：stack.push()/top()/pop()效率比vector.push_back()/back()/pop_back()效率高？
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
class BSTIterator {
public:
    vector <TreeNode *> Vec;
    BSTIterator(TreeNode *root) {
        while (root != nullptr) {
            Vec.push_back(root);
            root = root -> left;
        }
        return;
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = Vec.back();
        int ret = tmp -> val;
        Vec.pop_back();
        TreeNode *res = tmp -> right;
        while(res != nullptr) {
            Vec.push_back(res);
            res = res -> left;
        }
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (!Vec.empty()) {
            return true;
        }
        return false;
    }
};