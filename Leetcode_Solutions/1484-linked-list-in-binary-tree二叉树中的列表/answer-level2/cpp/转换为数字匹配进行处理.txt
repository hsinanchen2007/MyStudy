### 解题思路
用vector存储树和链表的值，链表简单，树用回溯保存为二维数组，转化为数字匹配，比较容易理解，但效率有点堪忧，还是我太菜了！

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
class Solution {
public:
    vector<vector<int>> res;
    vector<int> t;
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> tmp;
        while(head!=NULL)
        {
            tmp.push_back(head->val);
            head=head->next;
        }

        search(root);
        // for(int i=0;i<res.size();i++)
        // {
        //     for(int j=0;j<res[i].size();j++)
        //     cout<<res[i][j]<<" ";
        //     cout<<endl;
        // }
        
            
        for(int i=0;i<res.size();i++)
        {
            if(res[i].size()<tmp.size())
                continue;
            for(int j=0;j<=res[i].size()-tmp.size();j++)
            {
                int p=0,q=0;
                if(res[i][j]==tmp[0])
                {
                    q=j,p=0;
                    //cout<<i<<" "<<j<<endl;
                    while(q<res[i].size()&&p<tmp.size()&&res[i][q]==tmp[p])
                    {
                        p++;q++;
                        // cout<<p<<" "<<q<<endl;
                        // cout<<res[i].size()<<" "<<tmp.size()<<endl;
                        if(p==tmp.size())
                            return true;
                    }
                    //cout<<1;
                }
            }
        }    
        return false;
    }
    void search(TreeNode* root)
    {
        if(root==NULL)
            return;
        t.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            res.push_back(t);
        }
        search(root->left);
        search(root->right);
        t.pop_back();
    }
};
```