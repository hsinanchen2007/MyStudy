```C++
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode*> now, next;
        //now存当前层的指针，now存下一层的指针
        now.push_back(root);next.push_back(root);
        while(!next.empty()) {//若下一层仍有元素，代表未到达最底层
            now = next;
            vector<TreeNode*> tmp;
            for(int i = 0;i < now.size(); i++) {
                if(now[i]->left) tmp.push_back(now[i]->left);
                if(now[i]->right) tmp.push_back(now[i]->right);
            }
            next = tmp;
        }
        return now[0]->val;//跳出循环代表now所存的是最后一层，去第一个就是最左边元素
    }
};
```
