前序遍历想递归，注意左子树非空不删括号

代码：
```
class Solution {
public:
    string transform(int num) {
        if (num == 0)
            return "0";
        else {
            string ans = "";
            bool neg = false;
            if (num < 0) {
                neg = true;
                num = -num;
            }
            while (num) {
                ans.insert(0, 1, (char)(num % 10 + 48));
                num = num / 10;
            }
            if (neg)
                ans.insert(0, 1, '-');
            return ans;
        }
    }
    string tree2str(TreeNode* t) {
        if (t == NULL)
            return "";
        else {
            string ans = transform(t->val);
            if (t->left) {
                ans = ans + "(" + tree2str(t->left) + ")";
                if (t->right)
                    ans = ans + "(" + tree2str(t->right) + ")";
            }
            else {
                if (t->right)
                    ans = ans + "()" + "(" + tree2str(t->right) + ")";
            }
            return ans;
        }
    }
};
```
