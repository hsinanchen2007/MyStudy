**层次遍历的思想：**
**1.每次从两个树中各取一个节点（记为node1, node2）入队;**
**2.出队时将两个节点值相加，并判断node1和node2的左子树是否为空，若两个左子树都不空，直接入队；若有一个为空，新建一个val为0的节点，然后入队；若两个的左子树都为空，pass。右子树的判断同理。**
```
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if(!t1)
            return t2;
        if(!t2)
            return t1;

        queue<TreeNode*> q;
        q.push(t1);
        q.push(t2);
        TreeNode *node1, *node2;

        while(!q.empty()){
            node1 = q.front();
            q.pop();
            node2 = q.front();
            q.pop();

            node1->val += node2->val;  //val相加

            if(node1->left || node2->left){ //左子树判断
                if(!node1->left)
                    node1->left = new TreeNode(0);
                if(!node2->left)
                    node2->left = new TreeNode(0);
                q.push(node1->left);
                q.push(node2->left);
            }
            if(node1->right || node2->right){   //右子树判断
                if(!node1->right)
                    node1->right = new TreeNode(0);
                if(!node2->right)
                    node2->right = new TreeNode(0);
                q.push(node1->right);
                q.push(node2->right);
            }
        }
        return t1;
    }
};
```
**递归**
```
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if(!t1)
            return t2;
        if(!t2)
            return t1; 
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
```