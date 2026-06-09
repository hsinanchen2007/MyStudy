### 解题思路
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4




第一层循环时l1 遍历
第二层循环时l1和l2next之间，遍历所有能插入的l2

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode * temp1,*temp2, *head;

    if(l1 == NULL && l2 == NULL)
        return NULL;
    if(l1 == NULL && l2 != NULL)
        return l2;
    if(l1 != NULL && l2 == NULL)
        return l1; 

    /*往l1头部插入麻烦，直接换一下*/
    if(l1->val > l2->val){
        temp1 = l1;
        l1 = l2;
        l2 = temp1;
    }


    head = l1;

    while(l1){
        if(l1->next){
            /*在l1 和l1-next之间， 插入所有能插入的l2*/
            while(l1->next && l2 && l1->next->val > l2->val ){
                temp1 = l1->next;
                l1->next = l2;
                temp2 = l2->next;
                l1->next->next = temp1;
                l2 = temp2;
            }
            /*如果刚才有插入l2, 也照样再来一遍， 软件好写些*/
            l1 = l1->next;
        }else{
            /*l1->next 为空了之后，直接l2追加末尾返回*/
            l1->next = l2;
            return head;
        }
    }
    return  head;

}
```