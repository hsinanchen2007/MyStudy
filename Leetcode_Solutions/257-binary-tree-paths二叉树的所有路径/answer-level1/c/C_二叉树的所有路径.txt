### 解题思路
尝试自己写了数据结构，过程很麻烦，可以输出路径链表，但是从链表转换成二维数组需要字符处理，没有完成字符处理功能。
吵了别人的代码，作者在代码注释后写着。
我自己的代码在============下面

### 代码

```c
/**
*
*整体思路：先序遍历
*1.如果二叉树为NULL，返回NULL
*2.申请动态内存，s用于动态存储路径，buffer用于所有路径
*3.将当前node的val存入s前需要进行如下步骤
*   如果为0，则直接存入数据0
*   如果不为0，进行如下步骤
*       如果小于0，则添加‘-’,同时将负数变成正整数
*       依次存入数据，翻转当前index到index+k之间的字符
*4.添加箭头
*5.如果left不为NULL，则遍历left,同时传入当前s的偏移量
*6.如果right不为NULL，则遍历right,同时传入当前s的偏移量
*7.如果当前结点为leaf，
*   为buffer申请动态内存，删除动态路径s的最后一个箭头，
*   复制动态路径s到buffer中，更新buffer的当前指针returnSize
*
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
*Function: visiting tree and saving the route from root to leaves to buffer
*@param: struct TreeNode * root : the tree ready to be visited
*@param: char ** buffer : the memory is used to save all the route
*@param: char * s : the dynamic route
*@param: int * returnSize : pointting current buffer element
*@param: int index : the parameter of index is used to point current elemnt of s
*return: void
*/
void visitTree( struct TreeNode * root , char ** buffer , char * s , int * returnSize , int index ){

    //the parameter of k is uesd to keep the offset of current node in s
    int k = 0 , tmp = root -> val;

    //if the value of current node is 0
    if( tmp == 0 ){

        //continuing to next node
        k = 1;
        *( s + index ) = '0';

    } else {

        //if the value of current node is smaller than 0, 
        if( tmp < 0 ){

            //appending the sign, turning over tmp 
            *( s + index++ ) = '-';
            tmp *= -1;

        }

        //saving the value of current to dynamic route of s
        while( tmp > 0 ){

            *( s + ( index + k++ ) ) = tmp % 10 + 48;
            tmp /= 10; 

        }

        //reversing the character from index to index and k
        for( int i = index , j = index + k - 1 ; i < j ; i++ , j-- ){

            char ch = *( s + i );
            *( s + i ) = *( s + j );
            *( s + j ) = ch;

        }

    }

    //appending the sign of arrow
    *( s + ( index + k++ ) ) = '-';
    *( s + ( index + k++ ) ) = '>';
    *( s + ( index + k ) ) = '\0';

    //if left is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , buffer , s , returnSize , index + k );

    }

    //if right is not NULL
    if( root -> right != NULL ){

        visitTree( root -> right , buffer , s , returnSize , index + k );

    }

    //if current node is leaf, saving the dynamic route to buffer, updating the pointer in buffer
    if( root -> left == NULL && root -> right == NULL ){

        *( buffer + *returnSize ) = ( char * )malloc( sizeof( char ) * ( index + 5 ) );
        //appending the ending flag of string to s
        *( s + index + k - 2 ) = '\0';
        strcpy( *( buffer + *returnSize ) , s );
        *returnSize += 1;

    }


}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths( struct TreeNode * root , int * returnSize ){

    *returnSize = 0;

    //if the tree is NULL, return NULL
    if( root == NULL ){

        return NULL;

    }

    //alloclating the memory to save all the route
    char ** buffer = ( char ** )malloc( sizeof( char * ) * 128 );
    //alloclating the memory to save dynamic route
    char * s = ( char * )malloc( sizeof( char ) * 1024 );
    //the paramter of len is the offset of s
    int len = 0;

    visitTree( root , buffer , s , returnSize , 0 );

    //free s
    free( s );

    return buffer;

}
/*
作者：big0range
链接：https://leetcode-cn.com/problems/binary-tree-paths/solution/c-4ms-85mb-by-big0rangecat-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/



//===========================================================================================================
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
 /*
 //--------------------------------------------------队列，储存路径节点用
 typedef struct Node{
     int data;
     struct Node* next;
 }Node;
//新建队列节点
Node* newNode(int Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
//入队
void queuePush(Node** QueueRear,int Data)
{
    Node* n=newNode(Data);
    n->next=(*QueueRear)->next;
    (*QueueRear)->next=n;
    (*QueueRear)=(*QueueRear)->next;
}
//出队
void queuePop(Node* QueueHead,Node** QueueRear)
{
    Node* n=QueueHead->next;
    QueueHead->next=n->next;
    if(QueueHead->next==0)
        *QueueRear=QueueHead;
    free(n);
}
//从队尾出队
void queuePopRear(Node* QueueHead,Node** QueueRear)
{
    if(QueueHead==(*QueueRear))return;
    *QueueRear=QueueHead;
    while((*QueueRear)->next->next!=0)
        (*QueueRear)=(*QueueRear)->next;
    Node* n=(*QueueRear)->next;
    (*QueueRear)->next=n->next;
    free(n);
}
//测长度
int queueLength(Node* QueueHead)
{
    int result=0;
    for(Node* n=QueueHead->next;n!=0;n=n->next)
        ++result;
    return result;
}
//释放内存
void queueFree(Node* QueueHead)
{
    while(QueueHead!=0)
    {
        Node* n=QueueHead;
        QueueHead=QueueHead->next;
        free(n);
    }
}
//--------------------------------------------------栈，储存路径用
typedef struct NodeStack{
    char* path;
    struct NodeStack* next;
}NodeStack;
//新建节点
NodeStack* newNodeStack(char* Path)
{
    NodeStack* n=(NodeStack*)malloc(sizeof(NodeStack));
    n->path=Path;
    n->next=0;
    return n;
}
//入栈
void stackPush(NodeStack* StackHead,char* Path)
{
    NodeStack* n=newNodeStack(Path);
    n->next=StackHead->next;
    StackHead->next=n;
}
//出栈
char* stackPop(NodeStack* StackHead)
{
    NodeStack* n=StackHead->next;
    StackHead->next=n->next;
    char* result=n->path;
    free(n);
    return result;
}
//测量长度
int stackLength(NodeStack* StackHead)
{
    int result=0;
    for(NodeStack* n=StackHead->next;n!=0;n=n->next)
        ++result;
    return result;
}
//释放内存
void stackFree(NodeStack* StackHead)
{
    while(StackHead!=0)
    {
        NodeStack* n=StackHead;
        StackHead=StackHead->next;
        free(n);
    }
}
//--------------------------------------------------队列，储存路径节点用
char* outPath(Node* QueueHead,Node** QueueRear)
{
    int length=queueLength(QueueHead);
    char* result=(char*)malloc(sizeof(char)*(length*3-1));
    Node* n=QueueHead->next;
    for(int i=0;i<length*3-5;i+=3)
    {
        result[i]='0'+n->data;
        result[i+1]='-';
        result[i+2]='>';
        n=n->next;   
    }
    result[length*3-3]='0'+n->data;
    result[length*3-2]='\0';
    return result;
}
void path(struct TreeNode* Root,Node* QueueHead,Node** QueueRear,NodeStack* StackHead)
{
    if(Root==0)return;

    queuePush(QueueRear,Root->val);
    if(Root->left==0&&Root->right==0)
        stackPush(StackHead,outPath(QueueHead,QueueRear));
    path(Root->left,QueueHead,QueueRear,StackHead);
    path(Root->right,QueueHead,QueueRear,StackHead);
    queuePopRear(QueueHead,QueueRear); 
}
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    
    Node* queueHead=newNode(0);
    Node* queueRear=queueHead;
    NodeStack* stackHead=newNodeStack(0);
    path(root,queueHead,&queueRear,stackHead);


    int length=stackLength(stackHead);
    *returnSize=length;
    char** result=(char**)malloc(sizeof(char*)*length);
    for(int i=0;i<length;++i)
        result[i]=stackPop(stackHead);
    queueFree(queueHead);
    stackFree(stackHead);

    return result;
}*/
```