先序，需要额外维持升序排列
```
class Solution {
private:vector<int>list; // 从小到最大保存k个值
public:
    int kthLargest(TreeNode* root, int k) {
        if( list.size() < k ){ list.push_back(root->val); }
        else if ( list[0] < root->val ){ list[0]=root->val; }        
        sort(list.begin(),list.end()); // 升序        
        if(root->left){ kthLargest(root->left, k); }
        if(root->right){ kthLargest(root->right, k); }
        return list[0];
    }
};
```
中序当然更适合啦，遍历完就是升序的，
```
class Solution {
private:vector<int>list; 
public:
    int kthLargest(TreeNode* root, int k) {
        lnr(root);
        int n = list.size();
        return list[n-k]; 
    }
    void lnr(TreeNode* root){
        if(!root){ return; }
        if(root->left){ lnr(root->left); }
        list.push_back(root->val);
        if(root->right){ lnr(root->right); }
    }
};
```
练练不用递归的写法
```
class Solution {
private:vector<int> res; 
public:
    int kthLargest(TreeNode* root, int k) {
        lnr(root);
        return res[(int)res.size()-k];
    }
    void lnr(TreeNode* root){
        stack<TreeNode*>list; 
        TreeNode* temp = root;
        if(!root){return;}
        while(!list.empty() || temp){
            if(temp){
                list.push(temp);
                temp = temp->left;
            }
            else{
                temp = list.top();
                list.pop();
                res.push_back(temp->val);
                temp = temp->right;
            }
        }
    }
};
```
