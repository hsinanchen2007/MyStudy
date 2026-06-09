```
#define MAXSIZE 10000
typedef struct myQueue{
    struct TreeNode* queue[MAXSIZE];
}queue;
 bool hasSon(struct TreeNode* root, struct TreeNode* child){
     if(root==NULL)
        return 0;
     if(root->left==child||root->right==child||root==child)
        return 1;
     return hasSon(root->left,child)||hasSon(root->right,child);
 }
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    queue myTree;
    struct TreeNode *p1;
    int now=-1,index;
    int end=0;
    if(root==NULL)
        return NULL;
    myTree.queue[++now]=root;
    end++;
    index=now;
    while(index!=end){
        p1=myTree.queue[index];
        if(p1->left!=NULL)
        {
            myTree.queue[++now]=p1->left;
            end++;
        }
        if(p1->right!=NULL)
        {
            myTree.queue[++now]=p1->right;
            end++;
        }
        index++;
    }
    for(index=now;index>=0;index--){
        printf("%d,",myTree.queue[index]->val);
        if(hasSon(myTree.queue[index],p)&&hasSon(myTree.queue[index],q))
            return myTree.queue[index];
    }
    return NULL;

}
```
