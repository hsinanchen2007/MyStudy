### 解题思路
非递归//层序遍历(链队，循环队列)
在这里链队是比较复杂一点因为出队，入队，队空每个函数都有两个，比较繁琐，但也可以自行尝试

1，熟悉循环队列
2，熟悉二叉树层序遍历(队列实现)
3，递归判断(目的是熟悉递归，其次是知道四种情况)

1，2，3两步若不熟悉，借此题好好的复习巩固！加油
本题采用循环队列

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//非递归（层次遍历）链队，要构造两个front，出队两个函数，入队两个函数，比较繁琐
//在这里只用循环队列，减少不必要的麻烦，如果有时间有兴趣可以尝试用链队
#define maxsize 20
int funtion(struct TreeNode *p,struct TreeNode *q)
{//funtion就是递归的四种情况，一旦不符合就返回0
    if(p==NULL&&q!=NULL)
        return 0;
    else if(p!=NULL&&q==NULL)
        return 0;
    else
    {
        if(p->val==q->val)
            return 1;//如果符合就返回1
        else
            return 0;
    }
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){

    if(!p && !q)
        return true;
    if(!funtion(p,q))
        return false;
//两个if语句是判断根节点
//如果根节点都不为空且相等，则继续执行下面代码
    struct TreeNode *queue1[maxsize];
    struct TreeNode *queue2[maxsize];
    int front1=0,rear1=0,front2=0,rear2=0;
    queue1[rear1]=p;
    queue2[rear2]=q;
    rear1=(rear1+1)%maxsize;
    rear2=(rear2+1)%maxsize;//循环队列
    while(rear1!=front1||rear2!=front2)//队空判断（中间是或(||)而不是与(&&))
    {//因为层序遍历是逐层的，比如测试用例的1 2 3 ，假如q数的2有左子树，p树的2没有左子树，       //那么结果将会是返回true,与事实不符。自己画图尝试!
        p=queue1[front1];front1=(front1+1)%maxsize;
        q=queue2[front2];front2=(front2+1)%maxsize;//出队
        if(!funtion(p,q))
            return false;//一旦返回0，直接跳出while并返回false

        //  若if语句没有执行，那就正常的层序遍历那样入队，出队，知道全部都相等
        if(p->left||q->left)
        {
            queue1[rear1]=p->left;
            queue2[rear2]=q->left;
            rear1=(rear1+1)%maxsize;
            rear2=(rear2+1)%maxsize;
        }
        if(p->right||q->right)
        {
            queue1[rear1]=p->right;
            queue2[rear2]=q->right;
            rear1=(rear1+1)%maxsize;
            rear2=(rear2+1)%maxsize;
        }
    }
    return true;
}


```
个人认为介绍的还是比较通俗易懂！
希望能帮助到你！谢谢观看！
加油！