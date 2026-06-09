- BST的重要性质：中序遍历为有序序列。
- 问题转化为：在升序数组中寻找众数

有序数组中的众数一定是连续出现的
使用counts记录当前遍历的数出现的次数，maxCounts记录截至目前“众数”的出现次数。
每次遍历到一个数作如下判断：
- 如果当前结点值与前一个结点的值相同，即`root->val == prev->val` 则`counts++;`
- 比较counts与maxCounts大小：
- 如若相同，则将当前值加入到结果`res`中。
- 如果`counts > maxCounts`,说明当前这个数出现次数更多，显然res中的那些弟弟们都不可能成为最终的众数。因此清空`res`,并将当前`root->val`加入结果集。并更新`maxCounts = counts`


```cpp

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        counts = 0, maxCounts = 1;
        inorder(root);
        return res;
    }
private:
    vector<int> res;
    int counts;
    int maxCounts;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev){
            //处理counts
            if(root->val == prev->val) counts += 1;
            else counts = 1;
            //由更新过的counts决定是否有新的“局部众数”产生
            if(counts == maxCounts) res.push_back(root->val);
            else if(counts > maxCounts) {res.clear(); res.push_back(root->val); maxCounts = counts;}
        }else{
            res.push_back(root->val);
            counts += 1;
        }
        prev = root;
        inorder(root->right);
    }
};

``` 