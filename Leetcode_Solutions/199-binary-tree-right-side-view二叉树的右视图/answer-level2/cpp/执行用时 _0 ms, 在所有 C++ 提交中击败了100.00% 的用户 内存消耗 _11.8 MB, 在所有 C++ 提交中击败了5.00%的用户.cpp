直接中序遍历，因为从右看，总是将最右边的节点值加入到待返回的vectorvector即可，话不多说，上代码
```
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> all;
        if(root==NULL) return all;
        vector<TreeNode*> myroot;  //用来存贮一层的所有节点，从左到右
        myroot.push_back(root);
        while(myroot.size()!=0)
        {
            vector<TreeNode*> p;  //用来和myroot做交换用的，存放myroot的下一层所有节点
            all.push_back(myroot[myroot.size()-1]->val);
            for(int i=0;i<myroot.size();++i)
            {
                //当子节点不为空的时候加入进入p
                if(myroot[i]->left!=NULL)  
                    p.push_back(myroot[i]->left);
                if(myroot[i]->right!=NULL)
                    p.push_back(myroot[i]->right);
            }
            myroot=p;
        }
        return all;
    }
};
```
