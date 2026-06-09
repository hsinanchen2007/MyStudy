### 解题思路
竞赛的时候首先考虑到的是递归解法，但无奈的是由于对各种情况考虑不周全+测试样例过于特殊，导致连续交了好几次全是wa，比赛时倒是知道自己哪里没有考虑周全了，但是以为时间不够用了直接上暴力解法，即解法一。后来看到别人的递归代码，发现其实在自己原来的版本上修改其实也就是几行代码的事情。

**解法一**：暴力解法。直接用dfs生成每一条可能的路径，用kmp算法检查链表中代表的串是不是路径代表的串的子串。
**解法二**：其实也算是暴力的递归吧（雾）。比赛的时候发现自己错了两个地方：第一个版本以为递归部分直接``func(head, root->left) || func(head, root->right)``或者``func(head->next, root->left) || func(head->next, root->right)``即可，没有考虑到路径肯定是连续的。第二个版本改正了以上问题，但是由于直接把下一次的``start``移动到``head``处，又导致可能漏解。（实际上解决起来很简单Orz）

自己还是基础不够扎实、考虑问题不够周全吧，需要多加练习。一点点进步吧！

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Solution1: 320ms, 204.3MB
class Solution {
     string ss;
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)   return true;
        if(!root)   return false;
       
        while(head != nullptr) {
            ss += to_string(head->val) + ',';
            head = head->next;
        }
        return helper(root, "");
    } 
    bool helper(TreeNode* root, string path) {
        if(!root) {
            cout << path << endl;
            return match(path, ss);
        }
        return helper(root->left, path + to_string(root->val) + ",") || 
        helper(root->right, path + to_string(root->val) + ",");
    }
    // 直接复用的第28题的kmp代码，稍作修改
    bool match(string haystack, string needle) {
        int n = needle.length();
        if(n == 0)  return 0;
        int m = haystack.length();
        vector<int> next(n);
        next[0] = -1;
        int t = next[0], j = 0;
        while (j < n - 1) {
            (0 > t || needle[j] == needle[t]) ? next[++j] = ++t : t = next[t];
        }
        int p = 0, q = 0;
        while (p < m && q < n) {
            if (0 > q || haystack[p] == needle[q]) {
                p++, q++;
            }
            else {
                q = next[q];
            }
        }
        if (q == n)
            return true;
        else return false;
    }
};

// Solution2: 104ms, 34.8MB
class Solution {
     string ss;
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)   return true;
        if(!root)   return false;
        if(func(head, head, root))
            return true;
        else return isSubPath(head, root->left) || isSubPath(head, root->right);   // 此句保证不会漏解，因为是逐层往下找的
    }
    bool func(ListNode* head, ListNode* start, TreeNode* root) {
        if(!start) return true;
        if(!root) return false;
        
        if(start->val == root->val)
            return func(head, start->next, root->left) || func(head, start->next, root->right);
        else return func(head, head, root->left) || func(head, head, root->right);  // 类似字符串匹配，直接移到链表头部进行比对
    }
};
```
