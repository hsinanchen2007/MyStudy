### 解题思路
**用递归构造二叉树**
- 按照前序遍历数组中的顺序依次在中序遍历数组中查找其位置
- 前序遍历第一个元素为整棵树的根节点
- 每次调用findinorder函数查找当前被搜索结点在中序遍历中的位置k
- 分为k=l,k=r-1,l<k<r-1三种情况继续递归构造


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
    //寻找num在中序遍历数组中的位置i,i的右边为num的右子树,i的左边为num的左子树
    //查找范围是[l,r)
    int findinorder(int l,int r,int num,vector<int>& inorder){
        int i=l;
        for(;i<r;i++){
            if(inorder[i]==num)
               break;
        }
        return i;
    }

    TreeNode* build(int& count,int l,int r,vector<int>& preorder, vector<int>& inorder){
        if(count>=preorder.size())   //已经构造完成
           return NULL;
        TreeNode *head=new TreeNode(preorder[count]);
        TreeNode *p=head;
        int k=findinorder(l,r,preorder[count],inorder);
        count++;
        if(k==l){          //当前结点无左子树
            if(l+1==r)     //为叶子结点
               return head;
            p->right=build(count,l+1,r,preorder,inorder);
        }else if(k==r-1){   //当前结点无右子树，只有左子树
            p->left=build(count,l,r-1,preorder,inorder);
        }else{              //当前结点既有左子树又有右子树
            p->left=build(count,l,k,preorder,inorder);
            p->right=build(count,k+1,r,preorder,inorder);
        }
        return head;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int count=0;
        TreeNode *head=build(count,0,inorder.size(),preorder,inorder);
        return head;
    }
};
```