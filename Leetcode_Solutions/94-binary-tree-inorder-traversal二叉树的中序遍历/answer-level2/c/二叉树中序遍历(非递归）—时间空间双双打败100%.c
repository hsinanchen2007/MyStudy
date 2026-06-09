### 解题思路
首先我做这个题花了一下午的时间，编写代码只用一个小时左右!因为我是刚自学完数据结构，很多前面学的后面忘，故借做题来复习

1，二叉树的创建，二叉树的前序，中序，后序，层次遍历
2，二叉树的前序，中序，后序遍历(非递归)
前面两个步骤如果不熟悉，抓紧时间巩固
3，中序遍历(非递归)是采用顺序栈的，要熟悉
完成前面3步骤后可以看题目要求以及函数的返回值，函数返回是 int *，即需要malloc
4,现在需要巩固二叉树结点个数的算法
5，题目没有说明这个二叉树是多大的二叉树，采取顺序栈肯定是不可取的，故需要复习链栈的相关操作
6，链栈的出栈，进栈，栈空判断都要复习

前6步都很熟悉的话就可以开始构思写代码，参考二叉树的中序遍历(非递归)（顺序栈的代码）

##代码函数部分
```
/*
typedef struct Node
{
	char data;
	struct Node *lchild,*rchild;
}BNode,*BiTree;//结点
*/
![二叉树中序遍历参考图.png](https://pic.leetcode-cn.com/27a54951b934d0028f62ea99095d4340b11e3cb0db4b07b0abd063a863c5c0b4-%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E5%8F%82%E8%80%83%E5%9B%BE.png)

void InorderTraverse(BNode *TB)//中序遍历//传入根节点的地址(左 根 右)
{
	BNode *p=TB;
	BNode *Stack[maxsize];//定义一个栈
	int top=-1;//top游标
	Stack[++top]=p;//将根节点入栈
	while(top!=-1)//判断栈空
	{
		if(p&&p->lchild)
		{
			Stack[++top]=p->lchild;先将根节点左子树全部入栈
			p=p->lchild;
		}
		else
		{
			p=Stack[top--];//出栈
			printf("%c->",p->data);
			if(p->rchild!=NULL)//判断该出栈结点的右子树
				Stack[++top]=p->rchild;
			p=p->rchild;//这里一定要放在if语句外面，不然会出错，自己画图多多尝试，我就是                        这么过来的，哈哈！
		}
//p=p->rchild;需要配合图进行讲解
	}	假如p=p->rchild放在if语句里面那就意味着有的时候右子树为空就不执行，那完蛋啦！
//如果根节点延左边都是左子树，那么在出栈的时候都要经过while，if(判断)，那么就会继续往if里面走啦！不符合我们的要求。自己画图尝试，可能我说的不是很清楚！重在画图理解
}
```

准备部分已经充足啦！好了我们就开始写代码，下面我对代码进行简单讲解
讲解前一定要对顺序栈的中序遍历理解清楚

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
typedef struct StackNode
{
    struct TreeNode *data;
    struct StackNode *next;
}StackNode,*LinkStack;//结点的构造，链栈说白啦就是链表，把链表的树立起来，像一个柱子就ok，这里不需要头结点

LinkStack top=NULL;//全局变量

void Push(struct TreeNode *e);//入栈
struct TreeNode *Pop();//出栈
int Stackempty(LinkStack *S);//判断栈是否为空
int TreeNumNode(struct TreeNode *T);//结点个数

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int k=TreeNumNode(root);//结点个数赋值给k
    int *numhead=(int *)malloc(sizeof(int)*k);
    int n=-1;
    if(root)
        Push(root);
    while(Stackempty(top)!=-1)//top是游标指针
    {
        if(root&&root->left)
        {
            Push(root->left);
            root=root->left;
        }
        else
        {
            n++;
            root=Pop();
            numhead[n]=root->val;
            if(root->right)
                Push(root->right);
            root=root->right;
        }
    }
    *returnSize=n+1;
    return numhead;
}

void Push(struct TreeNode *e)
{
    LinkStack p=(LinkStack)malloc(sizeof(struct StackNode));
    p->data=e;
    p->next=top;
    top=p;//相当于链表的头插法
}
struct TreeNode *Pop()//这里返回的类型要注意一下
{
    LinkStack e=top;
    top=top->next;//就是链表的结点删除
    return e->data;
}
int Stackempty(LinkStack *S)//相当于看有没有到NULL指针，即链表的尾巴
{
    if(S==NULL)
        return -1;
    else
        return 1;
}

int TreeNumNode(struct TreeNode *T)//递归数个数
{
    int leftnum=1,rightnum=1;
    if(T==NULL)
        return 0;
    else
    {
        leftnum+=TreeNumNode(T->left);
        rightnum+=TreeNumNode(T->right);
    }
    return leftnum+rightnum-1;
}
```

好啦！我也是新手，废了那么多话！我主要想说我们可以好好借助leetcode题来复习巩固加深数据结构！

我相信被我这么讲解你一定豁然开朗。大家一起相互讨论！一起加油！YEAH!