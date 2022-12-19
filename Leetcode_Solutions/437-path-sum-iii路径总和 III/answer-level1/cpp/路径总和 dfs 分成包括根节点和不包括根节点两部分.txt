分成两部分:
1 包含自己
2 不包含自己，分别在左右子树中寻找


#include <iostream>
#include <vector>
#include <string>
using namespace std;



 /* Definition for a binary tree node. */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if (!root) { 
            return res;
        }
        if (root->val == sum) {
            res++;
        }

        // 不包括root节点，在左右子树中找
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);

        // 包括 root节点，这里不能直接调用pathSum,否则递归以后造成“断开的路径”
        res += pathSum_nroot(root->left, sum - root->val);
        res += pathSum_nroot(root->right, sum - root->val);

        return res;
    }
     
     // 这个函数只找包含root的路径,比较单纯只需要自递归
    int pathSum_nroot(TreeNode* root, int sum) 
    {  
        if(!root) 
            return 0;
        int res = 0;
        if(root->val == sum) {
            res++;
        }
        res += pathSum_nroot(root->left, sum - root->val); //自递归
        res += pathSum_nroot(root->right, sum - root->val);
        return res;
    }

};

int main()
{
    vector<TreeNode* > tree;
    tree.push_back(new TreeNode(10));
    tree.push_back(new TreeNode(5));
    tree.push_back(new TreeNode(-3));
    tree.push_back(new TreeNode(3));
    tree.push_back(new TreeNode(2));
    tree.push_back(new TreeNode(11));
    tree.push_back(new TreeNode(3));
    tree.push_back(new TreeNode(-2));
    tree.push_back(new TreeNode(1));

    tree[0]->left =  tree[1];
    tree[0]->right = tree[2];
    tree[1]->left = tree[3];
    tree[1]->right = tree[4];
    tree[2]->right = tree[5];
    tree[3]->left = tree[6];
    tree[3]->right = tree[7];
    tree[4]->right = tree[8];

    Solution s;
    int result = s.pathSum(tree[0], 8);
    cout << "Result is" << result <<endl;
    system("pause");
    return 0;
    
}
