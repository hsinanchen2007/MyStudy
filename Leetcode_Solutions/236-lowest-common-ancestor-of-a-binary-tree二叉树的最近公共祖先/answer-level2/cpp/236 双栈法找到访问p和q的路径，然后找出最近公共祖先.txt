

```cpp

//方法二：双栈
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> currTrack, //当前路径
                    trackP, trackQ; //到节点P和Q的路径
        stack<TreeNode*> unprocessedList, //未访问节点
                         parentList; //对应未访问节点的父节点
        unprocessedList.push(root);
        parentList.push(nullptr);
        TreeNode *currNode; //当前节点
        while (unprocessedList.empty() == 0) {
            currNode = unprocessedList.top();
            unprocessedList.pop();
            parentList.pop();
            currTrack.push_back(currNode); //更新路径
            if (currNode->right) {
                unprocessedList.push(currNode->right);
                parentList.push(currNode);
            }
            if (currNode->left) {
                unprocessedList.push(currNode->left);
                parentList.push(currNode);
            }
            if (currNode == p)
                trackP = currTrack;
            if (currNode == q)
                trackQ = currTrack;
            if (!currNode->left && !currNode->right) //更新路径
                if (unprocessedList.empty() == 0)
                    while (currTrack.back() != parentList.top()) 
                        currTrack.pop_back();
        }
        int len = trackP.size()>trackQ.size()?trackQ.size():trackP.size();
        int i;
        for (i=0; i<len; i++)
            if (trackP[i] != trackQ[i])
                break;
        return trackQ[i-1];
    }
};
```