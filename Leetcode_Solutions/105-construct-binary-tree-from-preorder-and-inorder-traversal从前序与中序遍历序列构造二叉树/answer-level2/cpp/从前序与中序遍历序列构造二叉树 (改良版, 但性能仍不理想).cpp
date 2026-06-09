### 解题思路
此处撰写解题思路

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
class Solution 
{
public:
    typedef vector<int> vi;

    TreeNode* buildTree(vi& pre, vi& mid) 
    {
        vi pos1={0,(int)pre.size()-1};
        vi pos2={0,(int)mid.size()-1};
        return buildTreeWithPos(pre,pos1,mid,pos2);
    }

    //pos1,pos2 分别表示 pre,mid始末元素的下标
    TreeNode* buildTreeWithPos(vi& pre, vi& pos1, vi& mid, vi& pos2) 
    {
        if(pre.empty()) return NULL;

        TreeNode* root=new TreeNode(pre[pos1[0]]);
        int root_pos;  //根结点在中序遍历中的下标

        for(int i=pos2[0];i<=pos2[1];i++)
        {
            if(mid[i]==root->val)
            {
                root_pos=i;
                break;
            }
        }
        
        vi _pos1,_pos2; //接下来的始末元素下标，根据简单的数学推理可以得到

        if(root_pos>pos2[0])
        {
            _pos1={pos1[0]+1,pos1[0]+root_pos-pos2[0]};
            _pos2={pos2[0],root_pos-1};
            root->left=buildTreeWithPos(pre,_pos1,mid,_pos2);
        }

        if(root_pos<pos2[1])
        {
            _pos1={pos1[0]+root_pos-pos2[0]+1,pos1[1]};
            _pos2={root_pos+1,pos2[1]};
            root->right=buildTreeWithPos(pre,_pos1,mid,_pos2);
        }
        
        return root;
    }
};
```