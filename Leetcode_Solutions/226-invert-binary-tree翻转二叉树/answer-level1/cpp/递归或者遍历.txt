## 递归
递归就很简单了。对于一个Node，为nullptr则不做处理；不为nullptr则交换左右子节点，然后对左右子节点执行递归。

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);

            //swap left and right
            TreeNode* t = root->right;
            root->right = root->left;
            root->left = t;
        }
        return root;
    }
};
```

## BFS（广度优先搜索）
用一个queue来存储。逐层遍历节点。内存消耗略小于递归。
代码如下：
```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //BFS
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){ // 这里不严格按每层也是可以的，反正每个地方都遍历到就行了。
                TreeNode* p = q.front();
                q.pop();
                if(p!=nullptr){
                    swap(p->left,p->right);
                    q.push(p->left); q.push(p->right);
                }
            }
        }
    }
};
```