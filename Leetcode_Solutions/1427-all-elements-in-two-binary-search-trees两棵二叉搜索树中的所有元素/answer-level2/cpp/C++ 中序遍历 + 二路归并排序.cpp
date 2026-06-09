### 解题思路
中序遍历 + 二路归并排序

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        return mergeTwoSortArray(onOrderTraverse(root1), onOrderTraverse(root2));
    }

    vector<int> onOrderTraverse(TreeNode* root) {
        vector<int> traverseList;
        stack<TreeNode*> stackNodes;
        TreeNode* p = root;
        while(p || !stackNodes.empty()) {
            if(p) {
                stackNodes.push(p);
                p = p->left;
            }
            else {
                p = stackNodes.top();
                stackNodes.pop();
                traverseList.push_back(p->val);
                p = p->right;
            }
        }
        return traverseList;
    }

    vector<int> mergeTwoSortArray(vector<int> A, vector<int> B) {
        int i = 0, j = 0, k = 0;
        vector<int> mergeRes(A.size() + B.size());
        while(i < A.size() && j < B.size()) {
            mergeRes[k++] = (A[i] <= B[j]) ? A[i++] : B[j++];
        }
        while(i < A.size()) {
            mergeRes[k++] = A[i++];
        }
        while(j < B.size()) {
            mergeRes[k++] = B[j++];
        }
        return mergeRes;
    }
};
```