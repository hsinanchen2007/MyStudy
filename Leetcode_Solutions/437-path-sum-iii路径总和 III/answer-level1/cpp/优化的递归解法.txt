解这道题时首先想到的就是双重递归：以每个节点为根节点，递归求解路径数。实现也比较简单：

```c++
void DFS(TreeNode* root, int sum, int& count)
{
    if (root == nullptr)
        return;
    if (sum == root->val)
        count++;
    
    DFS(root->left, sum - root->val, count);
    DFS(root->right, sum - root->val, count);
}

void DFSTraverse(TreeNode* root, int sum, int& count)
{
    if (root == nullptr)
        return;
    
    DFS(root, sum, count);
    DFSTraverse(root->left, sum, count);
    DFSTraverse(root->right, sum, count);
}

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
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        DFSTraverse(root, sum, count);
        
        return count;
    }
};
```

上述算法的缺点也很明显：存在很多重复计算。导致算法的时间复杂度比较高。

那么有没有什么办法可以优化呢？ 其实当我们看到这道题的时候应该会觉得似曾相识，是的，这道题让我想起了 [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)，当我们理解了它的O(n)时间复杂度的解法时，很自然地可以应用到本题中：

```c++
void DFS(TreeNode* root, int k, int currentSum, unordered_map<int, int>& prefixSum, int& count)
{
    if (root == nullptr)
        return;
    
    currentSum += root->val;

    auto it = prefixSum.find(currentSum - k);
    if (it != prefixSum.end())
        count += it->second;
    prefixSum[currentSum]++;
    
    DFS(root->left, k, currentSum, prefixSum, count);
    DFS(root->right, k, currentSum, prefixSum, count);
    
    
    it = prefixSum.find(currentSum);
    if (it->second == 1)
    {
        prefixSum.erase(it);
    }
    else
        it->second--;
    
    currentSum -= root->val;
}

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
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        int currentSum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        
        DFS(root, sum, currentSum, prefixSum, count);
        
        return count;
    }
};
```
上述算法比第一种算法快了一个数量级，但空间复杂度比之前要高。
