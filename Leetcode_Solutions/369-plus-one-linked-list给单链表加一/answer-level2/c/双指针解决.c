分析情况，可能出现1.不进位；2.进位，无需增链；3.进位，需要增链。
情况1简单，不解释；
情况2，如12390999，如果加1发生进位，结果为12391000，观察发现，进位会产生如下结果：1.数字最后一位非9数字A加一；2.A之后的数字全部置0。所以首次遍历链表时，先确定A的位置，随后若产生进位，则将A加一，A后面的链表全部置零；
情况3，如99999，处理思想同情况2，只是A需要我们自己添加到链表头部，返回新链表即可。
代码如下：
```
struct ListNode* plusOne(struct ListNode* head){
    struct ListNode *Pointer = head,*CarryPointer = NULL;
    if(head == NULL)
        return NULL;
    while(Pointer->next != NULL){
        if(Pointer->next->val == 9 && Pointer->val != 9)
            CarryPointer = Pointer;
        Pointer = Pointer->next;
    }
    if((Pointer->val += 1) >= 10){
        if(CarryPointer == NULL){
            struct ListNode *AddPointer = (struct ListNode*)malloc(sizeof(struct ListNode));
            if(AddPointer == NULL)
                return NULL;
            AddPointer->val = Pointer->val / 10;
            AddPointer->next = head;
            CarryPointer = AddPointer;
            while(CarryPointer->next != NULL){
                CarryPointer = CarryPointer->next;
                CarryPointer->val = 0;
            }
            return AddPointer;
        }else{
            CarryPointer->val += 1;
            while(CarryPointer->next != NULL){
                CarryPointer = CarryPointer->next;
                CarryPointer->val = 0;
            }
        }
    }
    return head;
}
```
