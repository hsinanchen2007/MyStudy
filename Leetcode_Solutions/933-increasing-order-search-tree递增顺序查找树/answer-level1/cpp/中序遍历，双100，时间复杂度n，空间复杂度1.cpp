class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> sta;
        TreeNode* temp = root;
        TreeNode* prev = root;
        int flag = 0;
        TreeNode* newroot = root;
        while(!sta.empty() || temp){
            while(temp){
                sta.push(temp);
                temp = temp->left;
            }
            flag++;
            temp = sta.top();
            //cout<<temp->val<<endl;
            sta.pop();
            
            if(flag == 1){
                newroot = temp;
                prev = newroot;
            }
            else
            {
                prev->right = temp;
                prev = temp;
                temp->left = NULL;
            }
            temp = temp->right;
        }
        return newroot;
    }
};

思路就是用一个prev来记录之前的前置节点，不过需要注意的是，在temp用完以后，要把temp的left置为null，不然结点可能就变成双向的了，比如说题目例子里，1的右结点是2，temp是2时，它的左节点还是1，会出错。