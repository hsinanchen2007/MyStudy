**思路：**
先序遍历一棵树，若不符合，则尝试交换左右子树，若还是不符合，返回-1;
注意：若树中存在相同结点值，这种方法是行不通的，不过题目说了，结点值不相同。
```cpp
class Solution {
public:
    int index = 0;      // 全局索引比较方便
    vector<int> result; // 全局变量存结果，比较方便
    // 返回是否可通过交换来满足预期
    bool dfs(TreeNode* root, vector<int>& voyage){
        if(nullptr == root || index >= voyage.size())
            return true;
        // 若当前结点不符合预期，肯定不符合
        if(root->val != voyage[index])
            return false;
        index++;

        // 若先序遍历结果与预期不符，则尝试返回交换后的遍历结果
        if(nullptr != root->left && root->left->val != voyage[index]){
            result.push_back(root->val);// 记录这次交换
            return dfs(root->right, voyage) && dfs(root->left, voyage);
        }
        else{
            return dfs(root->left, voyage) && dfs(root->right, voyage);
        }
        
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        // 若可通过交换来满足预期，返回交换的结点值
        if(dfs(root, voyage))
            return result;
        return vector<int>{-1};
    }
};
```
**结果：**
![snipaste_20200328_181138.png](https://pic.leetcode-cn.com/f33a61fbf85928401967b2829e98ceb0677185e541272cd4254eddf200fab1da-snipaste_20200328_181138.png)

