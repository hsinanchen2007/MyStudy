### 解题思路
此处撰写解题思路

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
    int countNum = 0;
    void traverse(TreeNode* root, int sum, int current, unordered_map<int, int>& myMap){
    if(root == nullptr){
        return;
    }
    int rootNum = root->val;
    current += rootNum;
    countNum += myMap.find(current - sum) == myMap.end() ? 0 : myMap[current - sum];
    myMap[current]++;
    traverse(root->left, sum, current, myMap);
    traverse(root->right, sum, current, myMap);
    //递归之后将当前根结点的值给去掉
    if(myMap[current] > 1){
        myMap[current]--;
    }
    else{
        myMap.erase(current);
    }
}

int pathSum(TreeNode* root, int sum) {
    if(root == nullptr){
        return 0;
    }
    unordered_map<int, int> myMap;
    myMap[0] = 1;
    int current = 0;
    traverse(root, sum, current, myMap);
    return countNum;
}
};
```