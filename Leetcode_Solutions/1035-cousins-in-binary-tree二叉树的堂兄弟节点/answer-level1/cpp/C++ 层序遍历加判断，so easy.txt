### 解题思路

很简单题目，核心就是层序遍历。

如果一个节点的左右左孩子出现空的情况，则用`INT_MIN`来代替左右孩子节点值，并将左右孩子节点压入队列，这么做的目的只是为了方便我们判断。【类似满二叉树一样对待】

如果在某一深度的搜索结果：
+ x, y都没有找到，则进行下一深度的查找
+ x, y只找到一个，则直接`return false`
+ x, y两个都找到了，现在需要判断他们出现的位置。
    + 如果他们出现的位置之间相隔距离大于1，则可以说明他们的父节点不是同一个
    + 如果他们出现的位置刚好等于1，那么只要较大位置索引为偶数即说明他们的父节点不是同一个
    + 否则 `return false`

### 代码

```cpp
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);
            for(int i = 0; i<size; ++i){
                root = q.front(); q.pop();
                v[i] = root ? root->val : INT_MIN;
                if(root){ q.push(root->left); q.push(root->right); }
            }
            // 判断是否出现堂兄弟
            int index_x = -1, index_y = -1;
            for(int i = 0; i<size; ++i){
                if(v[i] == x) index_x = i;
                else if(v[i] == y) index_y = i;
            }
            // 没有找到
            if(index_x == -1 && index_y == -1);
            // 只找到一个
            else if(index_x == -1 || index_y == -1) return false;
            // 都找到
            else{
                // 相隔距离超过1
                if(abs(index_x - index_y) > 1 ) return true;
                // 相邻节点
                else if( (max(index_x, index_y) & 1) == 0) return true;
                else return false;
            }

        }
        return false;
    }
};
```