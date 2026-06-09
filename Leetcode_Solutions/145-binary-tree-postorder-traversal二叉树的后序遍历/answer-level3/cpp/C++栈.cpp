![image.png](https://pic.leetcode-cn.com/3ec329984f84c1661428ace313745cd9dbf077205fa4766fd4e2af478f273cb2-image.png)


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

    int pathNum(TreeNode* node){
        if(node->left!=NULL && node->right!=NULL)
            return 2;
        else if(node->left!=NULL || node->right!=NULL)
            return 1;
        else
            return 0;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root==NULL)
            return ans;

        stack<pair<TreeNode*,int>> stk;
        pair<TreeNode*,int> cur;

        stk.push(make_pair(root,0));//入栈，访问次数初始化为0
        
        while(!stk.empty()){
            stk.top().second++; //取栈顶元素，每次访问访问次数加1，只有从栈顶取元素才算一次访问
            cur = stk.top();
            int num = pathNum(cur.first);

            if(num==0){        //0、没有孩子结点，直接打印，弹出
                ans.push_back(cur.first->val);
                stk.pop();
            }else if(num==1){  //1、当前结点只有一个孩子
                if(cur.second==2){   //1.1、第二次来当前结点时到打印，弹出
                    ans.push_back(cur.first->val);
                    stk.pop();
                } else {            //1.2、cur.second==1 第一次来到，左孩子或者右孩子入栈
                    if(cur.first->left!=NULL)  
                        stk.push( make_pair(cur.first->left,0) );
                    else  
                        stk.push( make_pair(cur.first->right,0) );
                }
            } else {     //2、有两个孩子结点
                if(cur.second==1)       //2.1、第一次来到，左孩子入栈
                    stk.push( make_pair(cur.first->left,0) );
                else if(cur.second==2)  //2.2、第二次来到，右孩子入栈
                    stk.push( make_pair(cur.first->right,0) );
                else{                  //2.3、第三次来到，打印，弹出
                    ans.push_back(cur.first->val);
                    stk.pop();
                }
            }
        }
        return ans;
    }
};
```