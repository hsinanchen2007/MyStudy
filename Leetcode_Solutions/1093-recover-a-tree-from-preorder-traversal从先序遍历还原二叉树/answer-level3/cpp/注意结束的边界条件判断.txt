### 解题思路
保存-这数量，若当前-的数量要大于之前则插入，否责不插入，注意结尾插好之后记得清空字符串！！！
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
    TreeNode* creatTree(string& s,int pre)
    {
        if(s.size())
        {
            if(s[0]!='-')
            {
                TreeNode* root;
                if(s.find('-')!=s.npos)
                {
                    int lt1=s.find('-');
                    root=new TreeNode(stoi(s.substr(0,lt1)));
                    s=s.substr(lt1);
                    root->left=creatTree(s,0);
                    root->right=creatTree(s,0);
                }
                else
                    root=new TreeNode(stoi(s));
                return root;
            }
            else
            {
                int tp,lt1,lt2,i;
                for(i=0;i<s.size();++i)
                    if(s[i]!='-')
                        break;
                lt1=i;
                if(lt1>pre)
                {
                    s=s.substr(lt1);
                    if(s.find('-')!=s.npos)
                    {
                        lt2=s.find('-');
                        TreeNode* temp=new TreeNode(stoi(s.substr(0,lt2)));
                        s=s.substr(lt2);
                        temp->left=creatTree(s,lt1);
                        temp->right=creatTree(s,lt1);
                        return temp;
                    }
                    else
                    {
                        TreeNode* temp=new TreeNode(stoi(s));
                        s="";
                        return temp;
                    }
                }
                else
                    return NULL;
            }
        }
        return NULL;
    }
    TreeNode* recoverFromPreorder(string S) {
        //1、递归建树的方法可以制作建
        TreeNode* root;
        root=creatTree(S,-1);
        return root;
    }
};

```