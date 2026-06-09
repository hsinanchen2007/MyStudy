
```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode* node = head;
        ListNode* next = NULL;
        ListNode* pre = NULL;
        ListNode* start = NULL;
        
        int count = 1;
        while( count < m )  //找到位置m的节点
        {
            start = node;   //保存位置m前一个节点
            node = node -> next;
            count ++;
        }
        while( count < n + 1 ) //对m到n之间的节点进行翻转
        {
            next = node -> next;
            node -> next = pre;
            pre = node;
            node = next;
            count ++;
        }
        
        if( m == 1 )          
            head = pre;
        else
            start -> next = pre; //重新链接
        
        while( pre -> next != NULL )
        {
            pre = pre -> next;
        }
        pre -> next = node;
        
        return head;
    }
};
```