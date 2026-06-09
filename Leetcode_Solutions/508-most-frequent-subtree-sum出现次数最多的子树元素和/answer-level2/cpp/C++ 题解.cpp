C++解法发如下：
```
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



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
    vector<int> sums;
    int getSum(TreeNode *root) {
        // the root must not be NULL
        int left = 0;
        int right = 0;
        int val = 0;
        if (NULL != root->left) {
            left = getSum(root->left);
        }
        if (NULL != root->right) {
            right = getSum(root->right);
        }
        val = root->val + left + right;
        sums.push_back(val);
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if (NULL == root) return ans;
        // vector<int> sums;
        getSum(root);
        // get the vector
        // counter
        map<int,int> counter;
        int maxindex = 0;
        int maxfreq = 0;
        
        // ans.push_back(sums[maxindex]);
        for (int i = 0; i < sums.size(); ++i) {
            counter[sums[i]]++;
            if (counter[sums[i]] > maxfreq) {
                maxfreq = counter[sums[i]];
                maxindex = i;
                while (!ans.empty()) ans.pop_back();
                ans.push_back(sums[maxindex]);
                continue;
            }
            if (counter[sums[i]] == maxfreq) {
                ans.push_back(sums[i]);
            }
        }
        return ans;
    }
};
```