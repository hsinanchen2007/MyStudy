参考评论区第一名的理解 
右树为空当左树为空处理
参考理解为下

[@scvthedefect](/u/scvthedefect/)
题目的意思是子节点需要用()来包裹。举例来说，二叉树[root,left,right]，则转换为root(left)(right)。如果只有left为空节点，则输出root()(right)；如果只有right为空节点则可以忽略右节点的()，输出为root(left)。

```
class Solution {
public:
    string tree2str(TreeNode* t) {
        string res;
        res = helper(t);
        //return res;
        //cout << res;
        return res;
    }
    string helper(TreeNode* t){
        string res = "";
        if(t == NULL)
            return "";
        //char a = 'a'+(t->val);
        res+=to_string(t->val);
        //cout <<res;
        string left = helper(t->left);
        string right = helper(t->right);
        if(!t->left && !t->right)
            res+="";
        else if(t->left && !t->right)
            res =  res+'('+left+')';
        else if(t->right &&!t->left)
            res = res+"()"+ '('+right+')';
        else res = res+'('+left+')'+'('+right+')';
        return res;
    }
};
```
