完全二叉树一定是平衡的，利用完全二叉树的性质，根据数组下标来进行中序遍历：假设节点序号为i，其左孩子序号为2*i+1，右孩子的序号为2*(i+1)，节点不存在即序号大于等于数组长度。
按中序遍历的顺序将数组元素依次写入二叉树。
注意需事先构建出完全二叉树的结构，而后遍历的过程中写入值，也可以边遍历边构建二叉树。
下面附上后者的代码：
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        ListNode *p = head;
        vector<int> data;
        while(p){
            data.push_back(p->val);
            p = p->next;
        }
        stack<int> S;
        stack<TreeNode**> SS;
        int v = 0, N = data.size();
        TreeNode *root, **t = &root;
        int i = 0;
        while(true){
            while(v < N){
                S.push(v);
                *t = new TreeNode(0);
                SS.push(t);
                v = 2*v + 1;
                t = &((*t)->left);
            }
            if(S.empty())break;
            (*(SS.top()))->val = data[i++];
            v = 2*(S.top()+1);S.pop();
            t = &((*(SS.top()))->right);SS.pop();
        }
        return root;
    }
};
