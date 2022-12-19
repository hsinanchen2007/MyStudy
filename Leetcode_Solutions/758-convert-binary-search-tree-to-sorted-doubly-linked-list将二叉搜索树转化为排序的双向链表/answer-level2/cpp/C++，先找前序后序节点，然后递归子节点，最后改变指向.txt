```
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        change(root);
        auto cur_l=root,cur_r=root;
        //首尾节点连接
        while(cur_l->left)
            cur_l=cur_l->left;
        while(cur_r->right)
            cur_r=cur_r->right;
        cur_r->right=cur_l;
        cur_l->left=cur_r;
        return cur_l;
    }
    //改变指针指向，顺序一定是先找到前序后序节点，但不忙着改变指向，然后递归，最后再改指向
    void change(Node* node){
        if(!node)
            return;
        auto pre=search(node,0);
        auto aft=search(node,1);
        change(node->left);
        change(node->right);
        node->left=pre;
        if(pre)
            pre->right=node;
        node->right=aft;
        if(aft)
            aft->left=node;
    }
    //找给定节点的前序节点(mode=0)，或后序节点(mode=1)
    Node* search(Node* node,int mode){
        if(mode==0){
            auto pre=node->left;
            if(!pre)
                return NULL;
            while(pre->right)
                pre=pre->right;
            return pre;
        }else{
            auto aft=node->right;
            if(!aft)
                return NULL;
            while(aft->left)
                aft=aft->left;
            return aft;
        }      
    }
};
```