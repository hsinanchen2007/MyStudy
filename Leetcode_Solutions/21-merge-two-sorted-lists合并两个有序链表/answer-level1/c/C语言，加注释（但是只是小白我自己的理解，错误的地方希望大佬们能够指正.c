/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;//next的类型为： struct ListNode*
 * };
 */

//已经有两个链表，它们的定义类型为 struct ListNode;
struct  ListNode* mergeTwoLists( struct  ListNode* l1,  struct  ListNode* l2) // l1, l2 指向的是两条链表中的结构体（节点），l1->val, l2->val指的是结构体（节点）中存放的数值，l1->next, l2->next指向的是结构体（节点）存放的相邻下一个（指向结构体的）指针
{ 
     struct  ListNode* resultList = ( struct  ListNode*)malloc( sizeof ( struct  ListNode));  //动态分配类型为（ListNode)的结构体(该结构体的名称为resultList），类似于动态分配数组 int* dp = (int*)malloc(sizeof(int))，这里没有说明具体分配多少个struct ListNode类型的resultList结构体
     //该resultList结构体包含和listNode结构体相同的数据
     struct  ListNode* node = resultList; //这里是创建指向结构体（节点）数据resultList的（struct ListNode类型)的指针
     node->next = NULL;
     while (l1&&l2)
     { 
         if (l1->val <= l2->val)
         { 
            node->next=l1; 
            node=node->next; 
            l1=l1->next; 
        } 
        else
        { 
            node->next=l2; 
            node=node->next; 
            l2=l2->next; 
        } 
    } 
    if (l1!=NULL)
    { 
        node->next = l1; 
    } 
    else   if (l2!=NULL)
    { 
        node->next = l2; 
    } 
     return  resultList->next; 
}



注！！ 代码源自云海天教程