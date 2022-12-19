移动元素k位，相对于移动head(N - k % N)位，且新链表的尾结点在该新head的前一位(N - k % N - 1)。

首先，记录结点个数，并且做成环链表；
然后，计算N - k % N，这个head移动该步数后，新head所在的位置；
最后，移动head(N - k % N - 1)位，得到新链表的尾指针，该指针的下一位即新表的头结点。

```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int N = 1;
        ListNode* tail = head;
        while(tail -> next) {
            tail = tail -> next;
            N++;
        }
        tail -> next = head; // 做环
        
        k = N - k % N; // head的相对移动数
        // 对head少移动1位，得到新表尾指针的位置
        while(k - 1) {
            head = head -> next;
            k--;
        }
        tail = head; 
        head = head -> next;
        tail -> next = NULL;
        
        return head;
    }
};
```
![捕获.JPG](https://pic.leetcode-cn.com/c383b95c6628dac2381b7a44ddcec3b4067bc236a26baf913b57b74da09c7898-%E6%8D%95%E8%8E%B7.JPG)

