### 思路
- 删除某点，只需要找到该点的上一个节点，将上一个节点的指针指向目标点的下一个节点，使目标点无法被访问，这样相当于目标点被从链表中删除
- 当我们创建一个指针`ListNode *temp = head;`时，并没有创建一个新的链表，两个指针变量共用同一个链表。
```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !(head -> next))   return nullptr;
        ListNode *temp = head;
        int i = 0;
        while(temp){ //用来计算删除的点是正数第几个
            ++ i;
            temp = temp -> next;
        }
        if(i == n){ //此时删除的是head节点
            head = head -> next;
            return head;
        }
        temp = head;
        for(int j = i - n - 1; j > 0; -- j) temp = temp -> next; //找到该点
        temp -> next = temp -> next -> next; //将它的指针指向下下个节点
        return head;
    }
};
```