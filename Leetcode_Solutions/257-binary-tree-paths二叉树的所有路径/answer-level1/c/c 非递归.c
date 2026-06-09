```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #define MAXSIZE 10000
 #define PATHSIZE 100
typedef struct myQueue{
    struct TreeNode* queue[MAXSIZE];
    int father[MAXSIZE];
    int IsLeef[MAXSIZE];
}queue;


char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    if(root==NULL)
        return NULL;
    queue myTree;
    struct TreeNode *p1;
    int now=-1,index,nowi,flag,t;
    int path[MAXSIZE];
    for(int i=0;i<PATHSIZE;i++)
        path[i]=-2;
    int end=0,num;
    if(root==NULL)
        return NULL;
    myTree.queue[++now]=root;
    myTree.father[now]=-1;
    myTree.IsLeef[now]=0;
    end++;
    index=now;
    int leafNum=0;
    while(index!=end){
        p1=myTree.queue[index];
        flag=0;
        if(p1->left!=NULL)
        {
            myTree.queue[++now]=p1->left;
            myTree.father[now]=index;
            end++;
            flag=1;
        }
        if(p1->right!=NULL)
        {
            myTree.queue[++now]=p1->right;
            myTree.father[now]=index;
            end++;
            flag=1;
        }
        if(!flag)
            leafNum++;
        myTree.IsLeef[index]=!flag;
        index++;
    }
    *returnSize=leafNum;
    char **result;
    result=(char**)malloc(sizeof(char*)*leafNum);
    
    for(index=0;index<=now;index++){
        if(myTree.IsLeef[index]){
            num=1;
            t=myTree.father[index];
            path[num]=index;
            while(t!=-1){
                path[++num]=t;
                t=myTree.father[t];
            }
            char *str=(char*)malloc(sizeof(char)*1024);
            nowi=0;
            for(int j=num;j>1;j--){
                nowi+=sprintf(str+nowi,"%d->",myTree.queue[path[j]]->val);
                
            }
            sprintf(str+nowi,"%d",myTree.queue[path[1]]->val);
            result[--leafNum]=str;
            
        }
    }
    return result;
}
```
