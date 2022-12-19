### 解题思路
![image.png](https://pic.leetcode-cn.com/3fb8b8d725acfe1008c8ee3370180e51a79fb6ad0c3c607e808daf6c3bd42cc2-image.png)

本题使用前序遍历。
代码中利用三个栈，unprocessedList、parentList和currList分别存储未访问节点、未访问节点的父节点和当前路径经过的节点，还有一个vector<int>的变量currTrack来记录当前路径经过的节点的值。在遍历过程中，每经过一个节点，便将sum值做一次更新，即更新为sum减去当前节点的值。
到达叶子节点的时候，如果sum值为0.则currTrack是一条正确的路径，记录到返回值中。
到达叶子节点之后，要将当前节点重置为最近一个未访问节点，还需要更新sum值和currTrack。因为currList中记录这当前路径每个的节点，所以通过currList进行回溯，若回溯到一个节点是最近的未处理节点的父节点（存储于parentList中），停止回溯，将当前节点重置为最近一个节点（存储于unprocessedList中）并继续遍历。在上述回溯的过程中，每经历一个节点，要更新sum、currTrack和currStack。
前序遍历完成之后，所有的正确路径都会被记录到返回值。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root==nullptr)
            return res;
        vector<int> currTrack; //当前路径上的节点的值
        stack<TreeNode*> unprocessedList, //未访问节点
                         parentList, //记录对应的未访问节点的父节点
                         currList; //记录当前路径上的节点
        unprocessedList.push(root);
        parentList.push(nullptr);
        TreeNode *currNode; //当前的节点
        while (!unprocessedList.empty()) {
            currNode = unprocessedList.top();
            currList.push(currNode);
            unprocessedList.pop();
            parentList.pop();
            sum -= currNode->val;
            if (currNode->right) {
                unprocessedList.push(currNode->right);
                parentList.push(currNode);
            }
            if (currNode->left) {
                unprocessedList.push(currNode->left);
                parentList.push(currNode);
            }
            currTrack.push_back(currNode->val);
            if ( !currNode->left && !currNode->right ) {
                if (sum==0)
                    res.push_back(currTrack);
                if (!unprocessedList.empty()) 
                    while (currList.top() != parentList.top()) {
                        sum += currList.top()->val;
                        currList.pop();
                        currTrack.pop_back();
                    }
            }
        }

        return res;
    }
};
```