![jj.png](https://pic.leetcode-cn.com/6af7cb7ae6c71bf7fff3f37811d51f549721546cf921d65fb500329e7bdfddcf-jj.png)
时间每次提交不一样，不敢自夸，我认为我方法比较好的地方是没有浪费多余的内存
看了很多C的用例，都是预定义二维数组有一个很大的size（例如2000）往里面填值，这也是刷了几十题，觉得C不太**高级**的地方，
然后看了一些大佬的写法，发现他们用了 ** realloc()函数**，这下就解决了我的问题，谢谢大佬，让我学到这个函数。

我的整体思想是用链队，结点内容是一个新的结构体，与树节点的区别在于加了一个成员：**层**.该节点的里面的树节点的子节点的层成员是该结点层成员+1
```
struct queueNode{
    struct TreeNode * x;
    int levelNum;
    struct queueNode *next;
};
```
然后就是正常的和通常一样的进队、出队操作。
函数里设置一个当前层元素总数的变量 **nowLevelSize**记录当前层的元素个数，然后换层的时候写入returnColumnSizes数组.
也没有多设置变量，就用*returnSize来记录在哪一层，当出队的元素的 **层成员**不是当前层的时候就是要换行啦！
```
struct queueNode{
    struct TreeNode * x;
    int levelNum;
    struct queueNode *next;
};
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **result;
    * returnSize=0;
    if(!root){
        return result;
    }
    
    result=(int **)malloc(sizeof(int *));//为result申请一个空间；
    *result=(int *)malloc(sizeof(int));//为result的第一个地址申请一个空间。

    int nowLevelSize=1;    
    struct queueNode * front=(struct queueNode *)malloc(sizeof(struct queueNode));
    struct queueNode * rear;
    front->x=root;front->levelNum=1;front->next=NULL;
    front->x=root;
    rear=front;
    *returnColumnSizes=(int *)malloc(sizeof(int));//
    (*returnColumnSizes)[0]=1;
    while(front){

        //入队操作
        if(front->x->left){
            struct queueNode *new=(struct queueNode *)malloc(sizeof(struct queueNode));
            new->x=front->x->left;
            new->levelNum=front->levelNum+1;
            new->next=NULL;
            rear->next=new;
            rear=rear->next;
        }
        if(front->x->right){
            struct queueNode *new=(struct queueNode *)malloc(sizeof(struct queueNode));
            new->x=front->x->right;
            new->levelNum=front->levelNum+1;
            new->next=NULL;
            rear->next=new;
            rear=rear->next;
        }
     
        //出队操作
        if(front->levelNum!=(*returnSize)){//换行操作
            *returnSize=(*returnSize)+1;
            if(nowLevelSize!=0&&(*returnSize)>1){
                result=(int **)realloc(result,sizeof(int *)*(*returnSize));//二维指针加一行
                result[*returnSize-1]=(int *)malloc(sizeof(int));               
                *returnColumnSizes=(int *)realloc(*returnColumnSizes,(*returnSize)*sizeof(int));//returnColumnSizes多一行
               *(*returnColumnSizes+(*returnSize)-2)=nowLevelSize;
                nowLevelSize=1;
            }             
        }else{//不换行
            nowLevelSize++;   //现在行的个数
        }
        if(*returnSize>=1)
            result[*returnSize-1]=(int *)realloc(result[*returnSize-1],nowLevelSize*sizeof(int));//各行末加上元素
        result[*returnSize-1][nowLevelSize-1]=front->x->val;
       
        struct queueNode *temp=front;
        front=front->next;
        free(temp);
    }
    *(*returnColumnSizes+(*returnSize)-1)=nowLevelSize;
    return result;
}
```
