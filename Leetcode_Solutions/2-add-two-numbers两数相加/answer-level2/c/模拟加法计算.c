### 解题思路
模拟计算器，从低位开始两两相加，遇到10则进1
每次相加时需要考虑上一次计算的进位
在链表指向下个链时，一定要注意当前链表不能为空

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int a = 0; //第一个链表的每位代表的整数
    int b = 0; //第二个链表的每位代表的整数
    int c = 0; //每次计算的进位，默认值为0

    struct ListNode *pRes = (struct ListNode*)calloc(1, sizeof(struct ListNode)); //结果链表头
    struct ListNode *pTmpRes = 0; 
    pTmpRes = pRes;

    while(1)
    {
        a = 0; //每次计算前初始化每位数据为0
        b = 0; //每次计算前初始化每位数据为0
        
        if(0 != l1)
        {
            a = l1->val;
            l1 = l1->next; //链表不为空时才能指向下个节点
        }
        
        if(0 != l2)
        {
            b = l2->val;
            l2 = l2->next; //链表不为空时才能指向下个节点
        }
        
        if((a + b + c)>=10)
        {
            //当前两位整数加上上次的进位大于等于10，则发生进位，当前位值减去10，进位为1
            pTmpRes->val = a + b + c - 10;
            c = 1;
        }
        else
        {
            //当前位加上上次进位小于10，则直接赋值，进位为0
            pTmpRes->val = a + b + c;
            c = 0;
        }

        if(  (0 == l1)
           &&(0 == l2)
           &&(0 == c))
        {
            //进位为0且两个链表都为空，没有需要计算的位数了，跳出循环
            break;
        }
        
        //为链表下个节点分配内存，并指向下个节点
        pTmpRes->next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        pTmpRes = pTmpRes->next;
    }

    return pRes;

}
```