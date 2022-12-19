方法1：

```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode *odd = head;               //奇数节点第一个
        ListNode *even = head -> next;      //偶数节点第一个
        ListNode *evenHead = head -> next;  //偶数节点头节点，奇数节点尾结点连接它
        while (even && even -> next){
            odd -> next = even -> next;
            odd = even -> next;
            even -> next = odd -> next;
            even = odd -> next;
        }
        odd -> next = evenHead;             //奇数节点尾结点连接偶数节点头节点
        return head;
    }
};
```

方法2：

```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head -> next == NULL || head -> next -> next == NULL)//空、1个、2个
            return head;
        ListNode *p = head;
        ListNode *evenHead = head -> next;
        ListNode *t;
        int cnt = 0;
        while (p -> next -> next){
            t = p -> next;
            p -> next = p -> next -> next;
            p = t;
            cnt++;
        }
        if (cnt & 1){                   //奇数个节点的情况
            p -> next -> next = evenHead;
            p -> next = NULL; 
        }
        else
            p -> next = evenHead;
        return head;
    }
};
```
