
```
class Solution {
public:
    vector<int>ans;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        helper(root, target, K);
        return ans;
    }
    int helper(TreeNode* root, TreeNode* target, int K)
    {
       if(root == NULL)
       {
           return -1;
       }
       if(root == target)
       {
           find_ans(root, K);//当找到目标节点后先对以目标节点为根的子树进行搜索
           return K-1;//然后返回（注意，我返回的值是距离减1，因为要回溯一格所以要减一）
       }
       int left = helper(root->left, target, K);
       if(left >= 0)//如果返回的距离大于等于0，这说明找到目标节点，需要开始搜索答案
       {
           if(left == 0)//如果等于0，说明这个节点距离target的距离刚好为K
           {
               ans.push_back(root->val);
               return -1;//从这个节点之后的节点就没必要搜索了
           }
           else
           {
               find_ans(root->right, left - 1);//如果距离不是刚好为K，则搜索其右子树（因为我们是从左子树回缩回来的，说明左子树已经都搜索过了，只需要搜索其右子树即可，注意这里传入的值是left-1，因为往右子树走需要距离加1）
               return left - 1;
           }
       }
       int right = helper(root->right, target, K);//因为目标节点也有可能是某个节点的右子树的节点，所以这里也需要进行检测
       if(right >= 0)
       {
           if(right == 0)
           {
               ans.push_back(root->val);
               return -1;
           }
           else
           {
               find_ans(root->left, right - 1);
               return right - 1;
           }
       }
       return left;//如果左右子树的返回值都是负数，说明要么没找到target，要么就是已经超出K的距离
    }

    void find_ans(TreeNode* root, int dis)//搜索以root为根节点的子树
    {
        if(root == NULL)return;
        if(dis == 0)
        {
            ans.push_back(root->val);
            return;
        }
        find_ans(root->left, dis - 1);
        find_ans(root->right, dis - 1);
    }    
};
```
![QQ截图20200330102751.png](https://pic.leetcode-cn.com/56adaa23c5fdc2baf0279337066b113861e0b330c9f46cf5a1276138c43ecdff-QQ%E6%88%AA%E5%9B%BE20200330102751.png)


