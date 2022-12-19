执行用时 :16 ms, 在所有 C++ 提交中击败了76.41%的用户
内存消耗 :18.4 MB, 在所有 C++ 提交中击败了100.00%的用户
递归版比非递归版，写起来简单多了
```
class Solution {
public:
    bool isValidBST(TreeNode* root)  //中序遍历递归版
    {
        recursive(root);
        int len=vectors.size();   
        if(len<2) return true;
        for(int i=0;i<len-1;i++)
        {
            if(vectors[i]>=vectors[i+1])  return false;
        }
        return true;
    }
    void recursive(TreeNode* root) 
    {
        if(root)
        {
            recursive(root->left);
            vectors.push_back(root->val);
            recursive(root->right);
        }
    }
    void printvectors()  //提交时这个函数可以不要
    {
        for(auto i:vectors)
            cout<<i<<endl;
    }
private:
    vector<int> vectors;
};
```
