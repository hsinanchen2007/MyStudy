广度优先搜索，将每个节点依次入队，每次判断这个节点的左右子树是否存在，若在，判断其左右子树与x、y是否相等。利用四个变量记录深度和父节点。
```c++
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        // dx：x的深度 dy： y的深度
        int dx = 0, dy = 0;
        // px：x的父节点 py：y的父节点
        TreeNode* px, *py;
        while(!q.empty()){
            int size = q.size();
            ++depth;
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                // 当左子树不为空时，判断其值是否与x或y相等，并加入队列
                if(cur->left != NULL){
                    if(cur->left->val == x){
                        dx = depth;
                        px = cur;
                    }
                    if(cur->left->val == y){
                        dy = depth;
                        py = cur;
                    }
                    q.push(cur->left);
                }
                // 当右子树不为空时，判断其值是否与x或y相等，并加入队列
                if(cur->right != NULL){
                    if(cur->right->val == y){
                        dy = depth;
                        py = cur;
                    }
                    if(cur->right->val == x){
                        dx = depth;
                        px = cur;
                    }
                    q.push(cur->right);
                }
                // 如果x和y的深度相等且不是同一个父节点，则他们俩是堂兄弟节点
                if(dx == dy && px->val != py->val)
                    return true;
            }
        }
        return false;
    }
};
```