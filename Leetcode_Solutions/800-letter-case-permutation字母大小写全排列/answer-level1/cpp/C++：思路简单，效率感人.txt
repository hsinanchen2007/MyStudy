```
/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        res.push_back("");
        for (char s : S)
        {
            vector<string> temp = res;
            int size = res.size();
            res.clear();
            if (isdigit(s))
            {
                for (int i = 0; i < size; i++)
                    res.push_back(temp[i] + s);
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    res.push_back(temp[i] + char(tolower(s)));
                    res.push_back(temp[i] + char(toupper(s)));
                }
            }
        }
        return res;
    }
};
// @lc code=end
```
