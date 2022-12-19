题解：两个有序数组的合并是非常容易的，只不过现在给出的不是数组，而是二叉搜索树，我们通过操作树来实现在数组上同样的效果。这只是一个解题的方法，不见的是最优的，但通过题目给定的树具有搜索树的性质，我想题意本身也是这种意图吧。核心代码逻辑还是树的非递归中序遍历。
     

```
class Solution {
private:
    vector<int> re;
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        //left-->root--->right
        vector<int> re;
        if(!root2 && !root1) return re;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        TreeNode* p1 = root1;
        TreeNode* p2 = root2;

        while(p1 || !s1.empty() || p2 || !s2.empty()) {
            while(p1) {
                s1.push(p1);
                p1 = p1->left;
            }

            while(p2) {
                s2.push(p2);
                p2 = p2->left;
            }

            TreeNode* top1 = NULL;
            TreeNode* top2 = NULL;
            if(!s1.empty()) top1 = s1.top();
            if(!s2.empty()) top2 = s2.top();

            if(top1 && top2) {
                if(top1->val < top2->val) {
                    re.push_back(top1->val);
                    s1.pop();
                    p1 = top1->right;
                } else {
                    re.push_back(top2->val);
                    s2.pop();
                    p2 = top2->right;
                }
            } else if(top1) {
                re.push_back(top1->val);
                s1.pop();
                p1 = top1->right;
            } else if(top2) {
                re.push_back(top2->val);
                s2.pop();
                p2 = top2->right;
            }
        }
        return re;
    }
};
```
