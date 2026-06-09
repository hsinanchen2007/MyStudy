```c++
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B || !A)return false;
        if(dfs(A,B))return true;                //如果从A的根节点就找到了该子结构就直接返回
        bool l = isSubStructure(A->left,B);     //从A的左子树中找该子结构
        bool r = isSubStructure(A->right,B);    //从A的右子树中找该子结构
        return l || r;                          //左右子树里找到一个就行
    }
    bool dfs(TreeNode* a,TreeNode* b){
        if(!a && b)return false;        //b还没判断完a已经为空了肯定不是
        else if(a && !b)return true;    //b的当前节点已经判断完了且a不空
        else if(!a && !b)return true;   //b的当前节点已经判断完了且a为空
        else {                          //a,b当前节点都有值
            if(a->val == b->val){       //如果节点值相同则递归判断左右子树 当且仅当左右子树都是子结构才返回真
                bool l = dfs(a->left,b->left);
                bool r = dfs(a->right,b->right);
                return l & r;
            }
            else return false;
        }
    }
};
```