### 解题思路
题目没有说明链表的长度，那么就要讨论链表的情况，我分为空链表、长度为1的链表、长度为2的链表、长度大于等于3的链表。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* temp_prev,*temp,*temp_next;
    if(head!=NULL) //是否为空链表
    {
        temp_prev=head; //赋初值
        temp=temp_prev->next;
        if(temp!=NULL) //链表长度是否为1
        {
            temp_next=temp->next;
            temp_prev->next=NULL;
            if(temp->next!=NULL) //链表长度是否为2
            {
                for(;temp_next->next!=NULL;)
                {      
                    temp->next=temp_prev;
                    temp_prev       = temp;
                    temp            = temp_next;
                    temp_next=temp->next;
                }
                temp->next=temp_prev;
                temp_prev       = temp;
                temp            = temp_next;
                temp->next=temp_prev;
                return temp;
            }
            else //链表长度为2的情况
            {
                temp->next=temp_prev;
                return temp;
            }           
        }
        else //链表长度为1的情况
        {
            return head;
        }           
    }
    else //长度为0的情况，即空链表
    {
        return head;
    }  
}


//改进代码：
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* temp_pre = NULL, * temp = head, *temp_next = head;
	while (temp) {            //temp代表本次循环要处理的节点，此时head已提取至temp中
		temp_next = temp_next->next;  //head推进至下一个待处理节点
		temp->next = temp_pre;    //将新链表接在temp的后面，此时temp成为新链表的头
		temp_pre = temp;          //temp_pre也成为了新链表的头
		temp = temp_next;         //cur提取链表中的temp_next，进入下一轮处理
	}
	return temp_pre;
}
```