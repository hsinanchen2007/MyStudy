###方法：中序遍历

> 这个方法不需要额外内存空间 (除了递归栈)

根据BST的特性，对其中序遍历得到的值是递增的这个原则，我们看一颗BST其实就是在看一个递增数组。那么现在问题转化成如何在递增数组中找众树。
例如有递增数组a[5] = {1, 2, 2, 3, 3};我们可以设置一个 `preVal` 和 `curVal` 值刚开始分别是1和2，然后向后移动，直到数组边界；在移动的过程中用 `curN` 记录 `preVal` 出现的次数, 用 `maxN` 记录某个众数出现的次数。当 `preVal == curVal`  时 `curN++` ；当 `preVal != curVal`  时比较 `curN` 和 `maxN`的值，考虑是否出现了众数；
但是我们现在是BST而不是数组怎么办呢？我之前有说其实BST通过中序遍历就可以看出一个递增数组，代码如下：
```c++

class Solution {
private:
    int maxn = 0;//用于记录众数出现的次数
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root)   return ans;
        int curn = 0, preVal;
        maxn = 0;
        TreeNode *p = root;
        while(p->left){//先找到preVal，也就时递增数组中最小的那个元素
            p = p->left;
        }
        preVal = p->val;
        traversal(root, ans, curn, preVal);
        if(curn == maxn)   ans.push_back(preVal);//以防递增数组中最后一个元素与preVal相等
        else if(curn > maxn){
            maxn = curn;
            ans.clear();
            ans.push_back(preVal);
        }
        return ans;
    }
    void traversal(TreeNode *root, vector<int> &ans, int &curn, int &preVal){
        if(!root)   return;
        traversal(root->left, ans, curn, preVal);
        if(preVal == root->val) curn++;
        else{
            if(curn == maxn)   ans.push_back(preVal);
            else if(curn > maxn){
                maxn = curn;
                ans.clear();
                ans.push_back(preVal);
            }
            curn = 1;
        }
        preVal = root->val;
        traversal(root->right, ans, curn, preVal);
    }
};
```