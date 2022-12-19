### 解题思路
设置一个深度优先搜索函数DFS（Node* root,layer）;然后判断Vector<int> Max的size()与layer的关系，不小于说明已经有该层暂时的最大值，与其比较更新Max;否则就将该点的val push_back进去，注意vector下标与layer的对应关系为下标存储layer-1层的最大值

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
    vector<int> Max;
    void DFS(TreeNode* root,int layer){
    if(root==NULL){return;}
    if(Max.size()>=layer){
        if(Max[layer-1]<root->val){
            Max[layer-1]=root->val;
            //printf("layer %d changed to %d\n",layer,Max[layer-1]);
        }
    }
    else{
        Max.push_back(root->val);
        //printf("layer %d new %d\n",layer,Max[layer-1]);
    }
    DFS(root->left,layer+1);
    DFS(root->right,layer+1);
    return;

}



vector<int> largestValues(TreeNode* root) {
    DFS(root,1);
    return Max;
}

};
```