### 解题思路
利用队列保存相应的状态信息，实现了非递归版本的根据前序中序建立二叉树。
显示的耗时并没有比递归版本的少，可能是自己太菜，可能是因为只是暴力实现（应该还存在许多可以优化的地方）。

### 代码

```cpp


struct four_pair{
    int ps; // start index of preorder
    int pe; // end index of preorder
    int is; // start index of inorder
    int ie; // end index of inorder
    four_pair(int x, int y, int z, int t): ps(x), pe(y), is(z), ie(t){}
};

class Solution{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;

        queue<four_pair> record_position;
        queue<TreeNode*> record_nodePointer;

        TreeNode * head = new TreeNode(preorder[0]);
        four_pair head_pair(0, preorder.size()-1, 0, inorder.size()-1);
        record_nodePointer.push(head);
        record_position.push(head_pair);

        /*
        * record_nodePoniter 保存每一个还未被处理的节点，仅进行了赋值
        * record_position 保存以record_nodePoniter中对应节点为根节点的子树 的前序中序遍历序列 的位置信息
        * 循环不变量：
        *   record_nodePoniter中保存的所有节点都有子节点（一个或两个）,而通过record_position中对应位置保存的信息可以对齐子节点进行构造。
        *   record_nodePoniter中保存的所有节点 或是没有父节点 或是在入队列之前就已经被分配好父节点了
        */
        while(!record_nodePointer.empty()){
            TreeNode* temp = record_nodePointer.front();
            record_nodePointer.pop();
            four_pair temp_pair = record_position.front();
            record_position.pop();

            int k=temp_pair.is;
            for(; k<=temp_pair.ie; ++k){
                if(inorder[k]==temp->val) break;
            }
            
            four_pair temp_pair_left(temp_pair.ps+1, temp_pair.ps+k-temp_pair.is, temp_pair.is, k-1);
            four_pair temp_pair_right(temp_pair.ps+k-temp_pair.is+1, temp_pair.pe, k+1, temp_pair.ie);

            if(temp_pair_left.ps==temp_pair_left.pe){
                TreeNode* temp_left = new TreeNode(preorder[temp_pair_left.ps]);
                temp->left = temp_left;
            }
            else if(temp_pair_left.ps<temp_pair_left.pe){
                TreeNode* temp_left = new TreeNode(preorder[temp_pair_left.ps]);
                temp->left = temp_left;
                record_nodePointer.push(temp_left);
                record_position.push(temp_pair_left);
            }

            if(temp_pair_right.ps==temp_pair_right.pe){
                TreeNode* temp_right = new TreeNode(preorder[temp_pair_right.ps]);
                temp->right = temp_right;
            }
            else if(temp_pair_right.ps<temp_pair_right.pe){
                TreeNode* temp_right = new TreeNode(preorder[temp_pair_right.ps]);
                temp->right = temp_right;
                record_nodePointer.push(temp_right);
                record_position.push(temp_pair_right);
            }   
        }
        return head;
    }
};
```