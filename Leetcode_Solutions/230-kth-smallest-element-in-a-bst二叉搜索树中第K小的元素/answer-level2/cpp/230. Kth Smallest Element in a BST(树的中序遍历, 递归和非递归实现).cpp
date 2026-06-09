### 递归
中序遍历, 即访问顺序是”左-中-右”, 直接上代码

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
    int res, count = 0;
    int kthSmallest(TreeNode* root, int k) {
        LNR(root, k);        
        return res;
    }
    void LNR(TreeNode* root, int k){
        if(!root)
            return;
        LNR(root -> left, k);
        count++;
        if(count == k)
            res = root -> val;
        LNR(root -> right, k);
    }
};

```

### 非递归
中序遍历的顺序是”左-中-右”; 因此, 对于每一个结点, 先访问其左孩子, 左孩子成为新的结点, 继续访问左孩子, 直到左孩子为空, 再按照同样的方法访问右孩子.
算法过程:
	对于结点P
1)	如果此结点具有左孩子, 则将P入栈, 将其左孩子作为新的P, 继续作相同的处理;
2)	如果此结点没有左孩子, 则将栈顶元素弹出, 访问栈顶结点, 然后将弹出的栈顶元素的右孩子作为新的结点P
3)	直到P为NULL, 栈为空结束

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
    int kthSmallest(TreeNode* root, int k) {
        int res, count = 0;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while(p != NULL || !st.empty()){

            while(p != NULL){
                st.push(p);
                p = p -> left;
            }
            if(!st.empty()){
                p = st.top();
                cout << p -> val;
                count++;
                if(count == k)
                    res = p -> val;
                st.pop();
                p = p -> right;
            }
        }
        return res;
    }
};
```
