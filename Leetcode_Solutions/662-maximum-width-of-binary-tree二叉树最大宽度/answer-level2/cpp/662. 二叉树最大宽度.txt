### 解题思路
转自评论区大佬
层序遍历
记录每个节点的索引
当每层遍历完成后计算下一层的最大宽度(链表最后一个元素索引-链表的最前面元素索引+1)
不过c++不像java，c++数据有长度限制，long long会爆掉
用字符串二进制代替整数，左子树加0，右子树加1，最后算差即可
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode *>q;
        queue<string> v;

        int res=1,size=1; 
        TreeNode *tmp;string x;
        q.push(root);v.push("0");

        while(!q.empty()){
            tmp=q.front();q.pop();
            x=v.front();v.pop();
            size--;
            if(tmp->left!=NULL){
                q.push(tmp->left);
                v.push(x+'0');
            }
            if(tmp->right!=NULL){
                q.push(tmp->right);
                v.push(x+'1');
            }
            if(size==0){
                if(v.size()>1){
                    string s1=v.front();
                    string s2=v.back();
                    int sum=0;
                    for(int i=0;i<s1.size();i++){
                         sum=sum*2+(s2[i]-s1[i]);
                    }
                    res=max(res,sum+1);
                }
                size=q.size();
            }
        }
        return res;
    }
};
```