m从后开始统计元素个数,如果如果等于n,即到达倒数第n个,将当前下一节点指向返回个当前上一节点连接,否则返回当前节点连接
递归回溯,来回一次

递归
```
class Solution {
private:
    int m=0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        head->next=removeNthFromEnd(head->next,n);
        return ++m==n?head->next:head;
    }
};
```
