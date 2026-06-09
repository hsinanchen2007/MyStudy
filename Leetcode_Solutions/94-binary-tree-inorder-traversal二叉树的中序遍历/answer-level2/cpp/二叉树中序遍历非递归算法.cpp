# 时间复杂度O(n)
1. 执行用时 :
4 ms, 在所有 C++ 提交中击败了72.64%的用户
1. 内存消耗 :
10.8 MB, 在所有 C++ 提交中击败了9.48%的用户
```
 vector<int> ans;
        if(root==nullptr) return ans;
        stack<int> s;     //用栈空间实现中序遍历的非递归算法
        while((s.empty()==0) || root!=nullptr)
        {
            if(root)
            {
                s.push_back(root);
                root=root->left;
            }
            else
            {
                root=s.top();
                s.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        
        return ans; 
```
