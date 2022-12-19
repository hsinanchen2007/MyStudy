前序遍历什么的不说了，算法是简单的。
关键思想：用string流代替string，用lambda代替函数，觉得有启发点个赞或者评论谢谢。
![image.png](https://pic.leetcode-cn.com/4336fca6611ad0f76aa76a317dd704f6c7b503b36659c1b3d7a758a4ec3c0e74-image.png)

```c++
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(t==nullptr)
            return "";
        stringstream ss;
        function<void(TreeNode*)> helper = [&ss, &helper](TreeNode* t){
            ss<<t->val;
            if(t->left==nullptr){
                if(t->right!=nullptr){
                    ss<<"()(";
                    helper(t->right);
                    ss<<')';
                }
            }
            else if(t->right==nullptr){
                ss<<'(';
                helper(t->left);
                ss<<')';
            }
            else{
                ss<<'(';
                helper(t->left);
                ss<<")(";
                helper(t->right);
                ss<<')';
            }
        };
        helper(t);
        string s;
        ss>>s;
        return s;
    }
};
```