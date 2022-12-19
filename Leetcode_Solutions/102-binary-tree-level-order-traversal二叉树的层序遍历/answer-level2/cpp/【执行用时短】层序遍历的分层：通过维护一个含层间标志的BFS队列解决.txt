### 解题思路

首先，通过构建和维护一个bfs队列来执行层序遍历；在此基础上，在bfs队列中每一层的末尾加入NULL来指示这一层的结束。

首先在bfs队列中入队root和null，即第一层的内容.在之后的循环中，不断移出队首的元素并将其子节点加入队列。使用一个额外的vector记录每一层的节点值(val)，如果判断某一个节点是这一层的最后一个节点（即bfs队列中其下一位是null），则把这个vector的内容作为这一层的内容，并把vector清空，准备承接下一层的内容。同时，如果判断某一个节点是这一层的最后一个节点，需要在子节点入队后额外入队一个null标志下一层的结束。通过维护bfs队列中的null标志，可以

在实现时注意到，最后的空层会连续地引入两个null为最终的终结。所以我们这里在`result.push_back`的时候不允许参数为空层。也可以通过检测到两个null时提前`break`掉循环的方式实现。

### 结果

执行用时 : 0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :14.1 MB, 在所有 C++ 提交中击败了24.42%的用户

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> curr_level;
        queue<TreeNode*> bfs_queue;
        bfs_queue.push(root);
        bfs_queue.push(NULL); // 标志本层的末尾
        while(!bfs_queue.empty()){
            TreeNode* curr_ptr = bfs_queue.front();
            bfs_queue.pop();
            if(curr_ptr == NULL){ // 如果某一层已经到末尾，则进行整理工作
                if(!curr_level.empty())
                    result.push_back(curr_level);
                curr_level.clear();
            }
            else{
                curr_level.push_back(curr_ptr -> val);
                if(curr_ptr -> left != NULL) bfs_queue.push(curr_ptr -> left);
                if(curr_ptr -> right != NULL) bfs_queue.push(curr_ptr -> right);
                if(bfs_queue.front() == NULL) bfs_queue.push(NULL); // 标志下一层的终结
            }
        }
        return result;
    }
};
```