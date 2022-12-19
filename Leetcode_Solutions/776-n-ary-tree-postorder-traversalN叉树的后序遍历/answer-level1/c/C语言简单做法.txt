### 解题思路
看代码注释即可

### 代码
```
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int j;            //全局变量j，这个全局变量初始化要在函数内进行，不然会有问题。具体我也是看了力扣才知道的。
int TreeNum(struct Node*root)   //统计n叉树的节点个数
{
    if(root==NULL)
    return 0;
    int num=0;
    num=num+root->numChildren;
    for(int i=0;i<root->numChildren;i++){
        num=num+TreeNum((root->children)[i]);          //递归统计各子树的节点数
    }
    return num;
}
void PostTraverse(struct Node*root,int*arr,int*returnSize); //函数原型声明
int* postorder(struct Node* root, int* returnSize){
    *returnSize=0;
    j=0;
    int *arr,NUM;
    NUM=TreeNum(root)+1;                              //+1是要把整个n叉树的根节点加上
    arr=(int*)malloc(sizeof(int)*NUM);
    PostTraverse(root,arr,returnSize);
    return arr;
}

void PostTraverse(struct Node*root,int*arr,int*returnSize)
{
    if(!root)
    return;
    int i=0;
    while(root->numChildren--){
        PostTraverse((root->children)[i++],arr,returnSize);
    }
    arr[j++]=root->val;
    (*returnSize)+=1;
}
```
```
