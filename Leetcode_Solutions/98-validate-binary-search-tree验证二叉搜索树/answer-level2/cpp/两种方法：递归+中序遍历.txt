方法一 递归
注意：不仅右子结点要大于该节点，整个右子树的元素都应该大于该节点。不仅左子结点要小于该节点，整个左子树的元素都应该小于该节点。因此要关注每个节点的上下界。
```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
    bool helper(TreeNode* cur,long lt,long rt){
        if(cur==NULL) return true;
        if(cur->val<=lt||cur->val>=rt) return false;
        if(helper(cur->left,lt,cur->val)&&helper(cur->right,cur->val,rt)) return true;
        return false;
    }
};
```
方法二 中序遍历
中序遍历得到的list中每个元素都应该比下一个元素小。
```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> sk;
        long tmp=LONG_MIN;
        while(root || sk.size()){
            while(root){
                sk.push(root);
                root=root->left;
            }
            root=sk.top();sk.pop();
            if(tmp>=root->val) return false;
            tmp=root->val;
            root=root->right;
        }
        return true;
    }
};
```


