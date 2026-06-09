这道题的做法很明显。看前几个答案就知道了，我这里主要提供下c++下memo的思路

这里实际上是有俩个思路来做memo。第一种是二维数组。即vector<vector<vector<TreeNode*>>> memo;
我觉得这样理解起来有点难受。
第二种就是用unordered_map来做。但是我们的key是标准类型，是一个类似int,int的组合。如果做key的话，就需要定义自己的hash函数，和比较运算符。
我这里想到了个取巧的办法，就是将其转为string，即"num_num"的形式。详情可以查看我的getKey。
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
    using MapType = unordered_map<string, vector<TreeNode*>> ;
    vector<TreeNode*> generateTrees(int n) {
        // 这道题利用分治的思路我认为应该是这样想的。
        // left， root， right这样的思想   
        if(!n)
            return {};
        MapType memo; 
        return generateTrees(1, n+1, memo);
    }
    string getKey(int start, int end)
    {
        return to_string(start) + "_" + to_string(end);
    }
    vector<TreeNode*> generateTrees(int start, int end, MapType &memo)
    {
        if(!memo.count(getKey(start, end)))
        {
        vector<TreeNode*> result;
        if(start >= end){
            result.push_back(nullptr);       
        }
        for(int i = start; i < end; i++){
            // 所有左子树的可能
            auto leftTrees = generateTrees(start, i, memo);
            auto rightTrees = generateTrees(i+1, end, memo);    
            for(auto leftNode : leftTrees)
            {
                for(auto rightNode : rightTrees)
                {
                    auto currNode = new TreeNode(i);
                    currNode->left = leftNode;
                    currNode->right = rightNode; 
                    result.push_back(currNode);
                }
            }
        } 
        memo[getKey(start, end)] = result;
        }
        return memo[getKey(start, end)];
    }
};
```