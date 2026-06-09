双指针技巧，p1指向父层的起点，p2指向子层的起点，通过父层找到子层的下一节点并连接，直到找不到下一节点，双指针垂直向下移动一层
```
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        Node* p1=root;
        Node* p2=NULL;
        /*p1,p2记录每层的起点，p2为p1的下一层*/
        if(root->left)
            p2=root->left;
        else if(root->right)
            p2=root->right;
        while(p2){
            for(Node* c1=p1, *c2=p2; c1!=NULL;){
                Node* nex=NULL;//找下一要进行连接的节点
                if(c1->left && c1->left!=c2 && c1->left->next==NULL)
                    nex=c1->left;
                else if(c1->right && c1->right!=c2 && c1->right->next==NULL){
                    nex=c1->right;
                    c1=c1->next;
                }                    
                else{
                    c1=c1->next;
                    continue;
                } 
                c2->next=nex;
                c2=nex;
            }
            /*双指针向下移动一层*/
            p1=p2;
            p2=NULL;
            Node* p=p1;
            while(p){
                if(p->left){
                    p2=p->left;
                    break;
                }else if(p->right){
                    p2=p->right;
                    break;
                }
                p=p->next;
            } 
        }
        return root;
    }
};
```
