利用队列`tQueue`对树进行层次遍历，使用vector`tVec`存放每一层的节点，并从后往前把这些节点连起来。
```
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        queue<Node*> tQueue;
        vector<Node*> tVec;
        tQueue.push(root);
        while(!tQueue.empty()) {
            int len = tQueue.size();
            while(len--) {
                Node* node = tQueue.front();
                tQueue.pop();
                if(node->left)
                    tQueue.push(node->left);
                if(node->right)
                    tQueue.push(node->right);
                tVec.push_back(node);
            }
            for(int i = tVec.size() - 1; i > 0; i--) {
                tVec[i - 1]->next = tVec[i];
            }
            tVec.clear();
        }
        return root;
    }
};
```
