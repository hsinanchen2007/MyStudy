# 1. 方法一：递归
    
二叉搜索树中序遍历输出应该是**递增**的，在遍历二叉树的过程中找到不满足递增的点（即错误交换的点），交换两者的值即可。
错误交换的点在中序遍历结果中**可能是相邻的，也可能是不相邻的**。
![image.png](https://pic.leetcode-cn.com/63d37b9af0d8e912bc711bdd16a7c122c7a03674c20996041840434644ac3f74-image.png)

如上图示例二的中序遍历结果1324，错误交换的点2和3就是相邻的；使用first和second表示错误交换的两个点，在第一次遇到不递增的情况时，将first置为3，second置为2，遍历结束后交换first与second。
![image.png](https://pic.leetcode-cn.com/f464ca29a037cba3db30383ebfa8a7413e36a5f1e12a7342717688b7e9c8a34f-image.png)

示例一的中序遍历结果321，错误交换的点就是不相邻的。**在第一次遇到不递增的情况时，将first设置为3，second设置为2，在第二次遇到不递增的情况时，只改变second，将second置为1**.遍历结束后交换first与second。
```
class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = NULL;
    void inorder(TreeNode* root){
        if(root == NULL)
            return;
        inorder(root->left);
        if(pre != NULL && pre->val > root->val){
            if(first == NULL){//first为空,首次找到前后大小不对的点
                first = pre;
                second = root;
            }else{//first不为空,第二次找到前后大小不对的点,只更新second
                second = root;
            }
        }
        pre = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};
```

# 2. 方法二：迭代，使用栈
将[**94题-二叉树的中序遍历**](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)的代码像方法一那样稍微修改一下即可。
```
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* pre = NULL;   
        TreeNode* cur = root; 
        stack<TreeNode*> stack;
        while(!stack.empty() || cur){
            while(cur){
                stack.push(cur);//左子树进栈
                cur = cur->left;
            }//左子树为空时退出循环
            cur = stack.top();//当前栈顶元素为要输出的元素
            if(pre != NULL && pre->val > cur->val){//判断是否存在逆序
                if(first == NULL){
                    first = pre;
                    second = cur;
                }
                else{
                    second = cur;
                }
            }
            pre = cur;
            stack.pop();
            cur = cur->right;//输出后遍历右子树(中序遍历顺序)
        }
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};
```
# 3. 莫里斯遍历，空间复杂度O(1)
莫里斯遍历在[**94题-二叉树的中序遍历**](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)的基础上修改一下即可，输出元素时判断前驱结点的大小是否大于当前结点，记录两个错误位置的方式与方法一相同。
```
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* pre = NULL;
        TreeNode* curr = root;
        TreeNode* tmp = NULL;
        while(curr != NULL){
            if(curr->left == NULL){     //左子树为空
                if((pre != NULL) && (pre->val > curr->val)){//如果有前驱且前驱的值大于当前结点的值,说明顺序反了,存在错误结点
                    if(first == NULL){  //如果是第一次发现,则将first置为前驱,second置为当前结点
                        first = pre;
                        second = curr;
                    }else{              //如果不是第一次发现,说明存在两个不相邻位置的交换,将second改为后者
                        second = curr;
                    }
                }
                pre = curr;             //如果没有前驱或者前驱的值小于当前值,属于正常情况,则继续遍历
                curr = curr->right;
            }
            else{
                tmp = curr->left;
                while((tmp->right != NULL) && (tmp->right != curr)){
                    tmp = tmp->right;
                }
                if(tmp->right == NULL){
                    tmp->right = curr;
                    curr = curr->left;
                }
                else{
                    tmp->right = NULL;//恢复树的形状
                    if((pre != NULL) && (pre->val > curr->val)){//判断逻辑与上面的相同
                        if(first == NULL){
                            first = pre;
                            second = curr;
                        }else{
                            second = curr;
                        }
                    }
                    pre = curr;
                    curr = curr->right;
                }
            }
        }
        int itmp = first->val;
        first->val = second->val;
        second->val = itmp;
    }
};
```

