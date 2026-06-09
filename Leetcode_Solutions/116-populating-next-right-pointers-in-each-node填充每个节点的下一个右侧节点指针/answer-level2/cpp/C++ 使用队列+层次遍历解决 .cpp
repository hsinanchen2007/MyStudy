##### 迭代法求解
思路：添加一个辅助变量preNode记录同层上一个节点，每层重置preNode为NULL；
层次遍历的变种真的有好多啊...eg. #103 #109
```
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(!root) {
            return NULL;
        }
        q.push(root);
        Node* preNode = NULL;
        while(!q.empty()) {
            int len = q.size();
            preNode = NULL;
            for(int i = 0; i < len; i++) {
                Node* n = q.front();
                q.pop();
                if(preNode != NULL) {
                    preNode->next = n;
                }
                preNode = n;
                if(n->left) {
                    q.push(n->left);
                }
                if(n->right) {
                    q.push(n->right);
                }
            }
        }
        return root;
    }
};
```
运行结果：
![image.png](https://pic.leetcode-cn.com/a12e0d95ef51078083c704f0eee0617f3026e06682b8e5d53da26f2403008363-image.png)
