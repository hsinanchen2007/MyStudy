一个节点最多有三个分支连接，左子树分支，柚子树分支，连接父亲的分支，
思路是先前序遍历找到我们要求的节点，然后dfs求出改节点左子树一共有多少x个节点，右子数一共有多少y个节点~ 
那么连接父亲节点那个分支剩下的个数就是 n-x-y-1 (减一就是要除掉这个节点本身)

如果这三个分支任意一支的节点数量大于等于 （n+1）/2 就是返回true,因为n是奇数
```
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root==NULL)return false;
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* xnode = NULL;
        while(!s.empty()|| p!=NULL){
            while(p!=NULL){
                s.push(p);
                if(p->val==x){
                    xnode = p;
                }
                p = p->left;
            }
            TreeNode* topNode = s.top();
            p = topNode->right;
            s.pop();
        }

        if(xnode!=NULL){
            int needcount = (n+1)/2;
            int leftcount = dfs(xnode->left);
            int rightcount = dfs(xnode->right);
            int parcount = n - leftcount - rightcount - 1;
            if(leftcount>=needcount || rightcount>=needcount || parcount>= needcount) return true;
        }

        return false;
    }

    int dfs(TreeNode* node){
        if(node==NULL) return 0;
        int leftcount = dfs(node->left);
        int rightcount = dfs(node->right);
        return leftcount+rightcount+1;
    }
};
```
