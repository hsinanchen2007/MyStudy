# 1 递推法
本来看了浙大的数据结构的用栈遍历，然后想写一个类似的，但是实现过程中发现在弹出的时候，sum的状态会改变（尤其在面对空节点的时候）；
因此参考了别人的代码，在弹出指针的时候，将sum也进行重新更新，这样消耗了更多的内存；但是思路是比较清晰的，只是每次都要更新一下sum
```
 /*递推的解法*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        stack<pair<TreeNode*,int>> s;
        TreeNode* temp=root;
        while(!s.empty()||temp!=NULL){
            while(temp!=NULL){
                s.push(make_pair(temp,sum-temp->val));
                sum=sum-temp->val;
                if(sum==0&&temp->left==NULL&&temp->right==NULL) return true;//除了判断和，还需要判断是否是叶节点，用来针对【1 2】，1的这种情况
                temp=temp->left;
            }
            auto item=s.top();
            s.pop();
            temp=item.first;
            sum=item.second;
            temp=temp->right;
        }
    return false;
    }
};
```
# 2 递归法
和别人的方法类似，从上向下层层剥离。终结的条件有两个，一个是当前节点root是叶节点的时候需要判断，另外就是空指针的时候返回false
```
 /*递归的解法*/
 bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        if(root->left==NULL&&root->right==NULL) 
            return sum==root->val;
        else
            return (hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val));
    }        
```