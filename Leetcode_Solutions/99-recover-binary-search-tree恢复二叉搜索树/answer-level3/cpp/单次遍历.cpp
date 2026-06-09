大家不用懂什么morris，只需要知道BST inorder 时是升序即可。我们只需找出降序的两个地方即可。如果是升序相邻的两个节点被交换了，那么只有一处违反升序。否则，有两处。例如 `1 2 3 4 5`， 交换后变为 `1 5 3 4 2`，则 `5 3 和 4 2` 违反了升序，只需交换 `5和2`即可

```
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* n1 = NULL, *n2 = NULL, *pre = NULL;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->next;
            }
            root = st.top();
            st.pop();
            if(pre && pre->val>root->val) {
                if(!n1) n1 = pre;
                n2 = root;
            }
            pre = root;
            root = root->right;
        }
        swap(n1->val, n2->val);
    }
};
```
