### 解题思路
首先进行中序遍历，将遍历结果存到vecter中。然后根据[Two Sum II - Input array is sorted](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)的方法来做

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
    bool findTarget(TreeNode* root, int k) {

        bool result = false;
        vector<int> numbers;

        inorder(root, numbers);     // 中序遍历然后将结果存到numbers
        int len = numbers.size();
        int left = 0;
        int right = len - 1;

        while(left < right){
            if(numbers[left] + numbers[right] == k){
                result = true;
                break;
            }
            else if(numbers[left] + numbers[right] > k){
                --right;
            }
            else{
                ++left;
            }
        }

        return result;
    }

    void inorder(TreeNode* root, vector<int>& numbers){
        if(root == NULL){
            return;
        }
        inorder(root->left, numbers);
        numbers.push_back(root->val);
        inorder(root->right, numbers);
    }
};

```