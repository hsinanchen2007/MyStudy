### 解题思路
层次遍历

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
    bool isCousins(TreeNode* root, int x, int y) {
        // 
        vector<int> T1;
        vector<int> T2;
        // 层次遍历
        if(!root) return false;
        TreeNode *cur=root;
        queue<TreeNode *> store;
        store.push(root);
        while(!store.empty()){
            int count=store.size(); //当前层的节点数
            vector<int> T1;
            while(count){
                TreeNode *k=store.front();
                store.pop();
                if(k){
                    T1.push_back(k->val);
                    store.push(k->left);
                    store.push(k->right); //
                }
                else{
                    T1.push_back(0);
                }
                count--;
            }
            //
            vector<int> ::iterator index1;
            vector<int> ::iterator index2;
            index1=find(T1.begin(),T1.end(),x);
            index2=find(T1.begin(),T1.end(),y);
            if(index1!=T1.end()&&index2!=T1.end()){
                int a=std::distance(std::begin(T1), index1); //找到索引
                int b=std::distance(std::begin(T1), index2); //找到索引
                //cout<<a<<b;
                if(a>b){
                    swap(a,b);
                }
                //cout<<a<<b;
                if(a+1==b && a%2==0){
                    return false;
                }
                return true;
            }
        }
        return false;
    }
};
```