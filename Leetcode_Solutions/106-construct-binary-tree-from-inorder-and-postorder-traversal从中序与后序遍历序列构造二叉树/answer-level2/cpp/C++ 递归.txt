### 解题思路
根据后序找根节点，然后在中序中根据根节点划分左右子树，根节点的左边为左子树，右边为右子树，根据左子树元素个数在后序中找到左子树元素区间，左子树区域后面就是右子树元素区域。

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
    unordered_map<int, int> umap;
    vector<int> inorder;
    vector<int> postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        int i = 0;
        for(auto item : inorder) {
            umap[item] = i++;
        }

        return help(0, inorder.size(), 0, postorder.size());
    }

    //使用数字索引，不创建vector大大加快速度
    TreeNode* help(int in_start, int in_end, int post_start, int post_end) {
        if(in_start == in_end)
            return NULL;
        int root_val = postorder[post_end-1];
        TreeNode* root = new TreeNode(root_val);

        int root_idx = umap[root_val];
        int left_nums = root_idx - in_start;
        root->left = help(in_start, root_idx, post_start, post_start+left_nums);
        root->right = help(root_idx+1, in_end, post_start+left_nums, post_end-1);

        return root;
    }


    //下面这种写法最好理解，但是效率低
    // TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    //     if(inorder.empty()) {
    //         return NULL;
    //     }


    //     int root_val = postorder.back();
    //     TreeNode* root = new TreeNode(root_val);
    //     int root_idx = 0;
    //     for(int i = 0; i < inorder.size(); i++) {
    //         if(inorder[i] == root_val) {
    //             root_idx = i;
    //         }
    //     }

    //     vector<int> left_elms_post;
    //     vector<int> left_eles_in;
    //     for(int i = 0; i < root_idx; i++) {
    //         left_elms_post.push_back(postorder[i]);
    //     }

    //     for(int i = 0; i < root_idx; i++) {
    //         left_eles_in.push_back(inorder[i]);
    //     }



    //     vector<int> right_elms_post;
    //     vector<int> right_elms_in;
    //     for(int j = root_idx; j < postorder.size()-1; j++) {
    //         right_elms_post.push_back(postorder[j]);
    //     }

    //     for(int j = root_idx+1; j < inorder.size(); j++) {
    //         right_elms_in.push_back(inorder[j]);
    //     }

    //     root->left = buildTree(left_eles_in, left_elms_post);
    //     root->right = buildTree(right_elms_in, right_elms_post);

    //     return root;
    // }

    void pirntV(vector<int>& v) {
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
};
```