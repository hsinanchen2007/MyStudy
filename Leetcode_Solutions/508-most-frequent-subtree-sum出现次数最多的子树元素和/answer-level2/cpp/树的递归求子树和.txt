### 解题思路
执行用时击败62.01%，感觉效率还行；
思路：
1、用递归的思想求得所有子树的和（子树的和=左子树和+右子树和+当前节点值）；
2、将递归求得的子树和放入map映射中；
3、遍历map映射，找到出现次数最多的那些子树和，放入结果re中；
4、返回re。

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
map<int, int> mp;//建立子树和和次数的映射
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> re;
        if (root==NULL) return re;
        int r=getSum(root);//递归求出所有子树的和，并放到mp里
        int m=0;
        for (map<int, int>::iterator it=mp.begin(); it!=mp.end();it++){//遍历mp，找出现最多次数的那些和
            if (it->second>m){//找到新的最大和，清空re，新的进入re
                m=it->second;
                re.clear();//清空re
                re.push_back(it->first);
            }
            else if (it->second==m) re.push_back(it->first);
            else if (it->second<m) continue;
        }
        return re;
    }
    int getSum(TreeNode* root){//求得所有子树和，并放入map映射中
        if (root==NULL) return 0;
        int Sum=getSum(root->left)+getSum(root->right)+root->val;
        mp[Sum]++;
        return Sum;
    }
};
```