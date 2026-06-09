4个月前的代码，一个字：不忍直视，丧心病狂
```
class Solution {
public:
    int depth;

    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        TreeNode* node;
        q.push(root);

        while( !q.empty() ){
            int width = q.size();
            if(width){
                depth ++;
            }
            for(int i = 0; i < width; i++){
                node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return depth;
    }
};
```
刷了一些教程之后，今天的代码虽然依旧菜得安详：
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root == NULL){
            return depth;
        }
        if(root->left || root->right){
            depth = 1+ max(maxDepth(root->left), maxDepth(root->right));
        }
        else{
            depth =1;
        }

        return depth;
    }
};
```

Liuyubo大神的代码，两行搞定：
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};
```

继续修炼，大家加油：）



