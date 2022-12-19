### 解题思路
思路就是利用迭代的思想，不断的交换，注意，在交换节点的同时应该让被交换的前者指向被交换的后者，否则将丢失后面的数据
eg ： 1  2  3  4  5
      2  1  4 （记得让3指向4后面的节点，否则5将丢失）3   5

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)  //空链表或者只有一个节点
        return head;
    if(head->next->next == NULL)   //只有2个节点
    {
        struct ListNode* tmp = head->next;
        tmp->next = head;
        head->next = NULL;
        return tmp;        
    }
    //3个及其3个以上
    struct ListNode* cur = head->next; 
    head->next = cur->next;     //头指向第三节点
    cur->next = head;           //第二个指向头，此时头为第二节点
    int flag = 1;  //利用flag 来解决 出现字符串为偶数时，排除出现next next 不存在的情节
    while(1 == flag && head->next->next)  //因为是两两交换，所以要保证next next 有值，即存在2个数
    {
        struct ListNode* ret = head->next; //第三节点
        head->next = ret->next;   //头指向第四节点
        if(head->next->next)      //当存在第五节点
            ret->next = head->next->next;   //第三节点指向第五节点
        else
        {
            ret->next = NULL;   //ret 已经是末尾元素，所以置空  ***
            flag = 0; //不再进行循环
        }
        head->next->next = ret; //第四节点指向第三节点，完成三四节点的交换，此时ret 为第四节点
        head = ret;  //赋值，进行迭代
    }
    if(head->next) //只剩下最后一个数
        head->next->next = NULL;
     //不用else 是因为在***处已经把末尾置空了，所以不用else
    return cur;
        
}
```