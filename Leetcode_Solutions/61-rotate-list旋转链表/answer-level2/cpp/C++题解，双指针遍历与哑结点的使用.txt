1. 首先遍历一次得到列表长度
2. k对长度取余
3. 先指针先走k步，后指针再前进，直到先指针的下一个结点为NULL
4. 将结点提到最前方
5. 预设一个哑结点，方便在最前方插入。
```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(-1); //哑结点
        if (head == NULL) return dummyHead->next;
        dummyHead->next = head; //把头结点放在哑结点之后
        ListNode* p = head;
        ListNode* s = head;
        ListNode* q = head;
        int length = 0;
        while (p != NULL) { //遍历长度
            length++;
            p = p->next;
        }
        k = k % length;     //取余
        for (int i = 0; i < k; i++) //先指针先前进 K 步
            s = s->next;

        while (s->next != NULL) {   //同时前进
            s = s->next;
            q = q->next;
        }
        //链表重新链接
        s->next = dummyHead->next;
        dummyHead->next = q->next;
        q->next = NULL;
        //重新定位头结点
        head = dummyHead->next;
        return head;
    }
};
```
