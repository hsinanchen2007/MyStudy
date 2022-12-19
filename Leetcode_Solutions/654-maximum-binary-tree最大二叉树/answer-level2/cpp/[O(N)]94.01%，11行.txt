### 解题思路
![max_btree.png](https://pic.leetcode-cn.com/9af5a790a71ede6aafa355414bd31778f0fd9957c99d2ca184bae990628029ae-max_btree.png)

国际版里看到能用binary search来优化的，自己实现了一下果然香
窃以为LeetCode testcase还是太小了，够大差距就出来了
大致的思想是维护一个类stack（归根结底都是deque嘛，所以方便binary srch用了vector）的中间容器
保证值最大节点始终在底部（v.rend()/v.begin()/v.front()）
新节点不够去底部的的（ret == v.crend()）但足够进组的，左右逢源
太小进不去的，去右子树
原题传送：
https://leetcode.com/problems/maximum-binary-tree/discuss/106147/c-8-lines-on-log-n-map-plus-stack-with-binary-search

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
    TreeNode* constructMaximumBinaryTree(vector<int> &nums) {
        // BASED ON LEECODE INTERNATIONAL SITE, @votrubac
        // construct cardisian tree in O(N)
        // since maintained portion in stack sorted
        // binary srch used to find nearest big element
        vector<TreeNode*> v;
        for (auto &each : nums){
            TreeNode* node = new TreeNode(each);
            // maintain right subtree in descending order
            auto it = upper_bound(v.crbegin(), v.crend(), node, [](const TreeNode* a, const TreeNode* b) {return a->val < b->val;});
            //small enough to insert in descending order
            if (it != v.crend())
                (*it)->right = node;
            //big enough to push in, link left subtree
            if (it != v.crbegin())
                node->left = *next(it, -1);
            //brilliant idea to remove left substree
            v.resize(distance(it, v.crend()));            
            v.push_back(node);
        }
        return v.front();
    }
//     TreeNode* constructMaximumBinaryTree(vector<int> &nums) {
//         // complete srch && N == 10^3
//         // O(N) <= T:O <= O(N^2)                
//         //  bgn >> max << end
//         if (nums.empty())
//             return NULL;
//         auto itL = nums.cbegin();
//         auto itR = nums.cend();
//         return build(itL, --itR);
//     }
// private:
//     TreeNode* bgn {NULL};
//     TreeNode* end {NULL};
//     TreeNode* pre {NULL};
//     TreeNode* post {NULL};
//     TreeNode* build(vector<int>::const_iterator &l, vector<int>::const_iterator &r){
//         if (*l == *r){
//             TreeNode* ret = new TreeNode(*l);    
//             ret->left = bgn;
//             ret->right = end;
//             return ret;
//         }            
//         TreeNode* leftSideNode = new TreeNode(*l);
//         if (pre)
//             pre->right = leftSideNode;
//         else
//             bgn = leftSideNode;
//         pre = leftSideNode;
//         TreeNode* rightSideNode = new TreeNode(*r);
//         if (post)
//             post->left = rightSideNode;
//         else
//             end = rightSideNode;
//         post = rightSideNode;
//         return build(++l, --r);
//     }
};
```