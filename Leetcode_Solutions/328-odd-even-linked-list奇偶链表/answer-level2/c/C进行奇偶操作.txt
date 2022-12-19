### 解题思路
定义两个移动的工作指针，分别更新奇数节点和偶数节点。发现奇偶的更新总是交替进行。
需要注意：最右边的奇数节点最后总指向第一个偶数节点；并注意如何恢复断链操作后应有的顺序。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head)
{
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    int counter = 1; // temp_odd后面首先是一个奇数节点
    struct ListNode* temp_odd = head;  //暂存奇数节点
    struct ListNode* temp_even = temp_odd->next; //暂存偶数节点
    struct ListNode* even = temp_even; //保存第一个偶节点，保证最后一个奇节点始终指向第一个偶节点
    struct ListNode* odd_rear; //保存更新奇数节点时，后面的节点，使暂时断开的偶数节点还原
    
    while (temp_even->next != NULL) // 结果是先奇数，后偶数，所以temp_even一直在后
    {
        if (counter%2 == 1)
        {
            temp_odd->next = temp_even->next;
            temp_odd = temp_odd->next; 
            odd_rear = temp_odd->next; 
            temp_odd->next = even; // 使最后一个奇数节点，始终指向第一个偶数节点 
            temp_even->next = odd_rear; // 还原temp_even原来的指向
            counter++; //改变下一次操作的奇偶性
        }
        else if (counter%2 == 0)
        {
            temp_even = temp_even->next; 
            counter++;
        }
    }
    
    return head;
}
```
