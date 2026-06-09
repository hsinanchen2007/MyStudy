1、前序遍历的迭代方法是最好理解的，遍历顺序为“根->左->右”，可以借助栈来实现。
对于当前节点cur，将其值存进result数组中，再将右节点压入栈s，并把左节点赋给cur；当cur节点为空时，从栈顶取元素赋给cur。
```
class Solution {
public: 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != NULL || !s.empty())
        {
            while(cur != NULL)
            {
                s.push(cur->right);
                result.push_back(cur->val);
                cur=cur->left;
            }
            cur = s.top();
            s.pop();
        }
        return result;
    }
};
```
2、对于后序遍历来说，顺序应该是“左->右->根”，但是我看了一堆的方法感觉都不是很好记，或者很好理解。但是如果将结果倒序则遍历顺序就改为“根->右->左”，这样可以使用前序遍历的方法，只是代码中左右节点的顺序需要变换。
```
class Solution {
public: 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        /* 先求“根右左”，再逆序就是后序“左右根” */
        while(cur != NULL || !s.empty())
        {
            while(cur != NULL)
            {
                s.push(cur->left);       //左节点入栈
                result.push_back(cur->val);
                cur=cur->right;          //前往右节点
            }
            cur = s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());    //将数组逆序
        return result;
    }
};
```

3、既然写了前序和后序，那就顺手把中序遍历的方法也写了吧。中序的遍历顺序是“左->根->右”，在节点cur不为空时，将自己压如栈s，并一直将cur左节点赋给cur；当cur节点为空时，从栈顶取出元素赋给cur，将cur的值加进result数组，并cur=cur->right。
```
class Solution {
public: 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != NULL || !s.empty())
        {
            while(cur != NULL)
            {
                s.push(cur);
                cur=cur->left;
            }
            cur = s.top();
            s.pop();
            result.push_back(cur);
            cur = cur->right;
        }
        return result;
    }
};
```

