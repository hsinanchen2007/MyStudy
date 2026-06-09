# 方法一
　后序遍历，当遍历到某个叶节点时，栈中所有节点都是其父节点，统计栈中所有元素的和，若等于sum，直接返回１。若遍历玩所有节点都没找到，返回０。

### 代码

```cpp

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        stack<TreeNode*> s;
        //s.push(root);
        TreeNode *p = root, *lastNode = NULL;
        int ans;
        while(p || !s.empty()){
            if(p){
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                //s.pop();
                if(p->right && p->right != lastNode){
                    p = p->right;
                    s.push(p);
                    p = p->left;
                }
                else{
                    //p = s.top();
                    if(!p->left && !p->right){
                        stack<TreeNode*> s1(s);
                        while(!s1.empty()){
                            ans += s1.top()->val;
                            s1.pop();
                        }
                        if(ans == sum)
                            return 1;
                    }
                    lastNode = p;
                    s.pop();
                    p = NULL;
                    ans = 0;
                }
            }
        }
        return 0;
    }
};
```