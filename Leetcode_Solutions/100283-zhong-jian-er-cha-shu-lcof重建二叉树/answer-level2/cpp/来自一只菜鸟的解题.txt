### 解题思路
## **递归思想**，前序preorder第一个节点（root）肯定是根结点，在对应的inorder中，root左边的节点全是左子树，右边对应为右子树。
**思路**： 每构建出一个节点node，就在preorder中删掉该点，直到为空（也是边界条件之一）。与此同时，在inorder中，截取开始到node节点的这一段元素，作为下一次递归的新的inorder，在这个子过程中，当inorder为空时（另外一个临界条件），那么该子过程结束，也就是该节点的左子树构造完成，此时，preorder和inorder内所有该子树内的节点已全部删除。开始构造右子树。。。直到最后两个数组为空，构造完成。
###### 代码

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *p;
        if(preorder.empty())   // 空树
            return NULL;
        buildWholeTree(p, preorder, inorder);
        return p;
    }
    void buildWholeTree(TreeNode* &p, vector<int>& preorder, vector<int>& inorder) { //递归构造
        if(preorder.empty())  // 两个临界条件
            return;
        if(inorder.empty())
            return;

        p = new TreeNode(preorder[0]); //构造节点
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), preorder[0]);
        int res = iter - inorder.begin();  //找到该节点在inorder中的位置

        preorder.erase(preorder.begin());  //节点构造结束，在preorder中删除该点

        vector<int>::const_iterator first_left = inorder.begin();
        vector<int>::const_iterator end_left = inorder.begin() + res ;
        vector<int> left_inorder(first_left, end_left);  //在inorder截取一段，构成新的inorder，范围为 0 - res

        buildWholeTree(p->left, preorder, left_inorder);  // build left tree
        inorder.erase(inorder.begin(), inorder.begin() + res + 1);   //构造右子树前，在inorder中删除掉之前构造的那些节点
        buildWholeTree(p->right, preorder, inorder);  // build right tree
    }
};

```