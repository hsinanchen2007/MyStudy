
pre head nextnode
1 →  2 →  3 → 4 → 5

↑→--→↓
1...2 ← 3...4 → 5
.....↓______↑

pre    head  nextnode
1 → 3 → 2 →  4 → 5
。。。。。。

```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1); // 哑节点
        dummy->next = head; // head的前驱节点
        ListNode* pre = dummy; // 指向m-1
        for(int p = 1; p<m; p++){ pre = pre->next; }// 将pre就位
        head = pre->next; // head指向当前反转节点，从m开始
        
        for(int r = m; r<n; r++){
            ListNode *nextnode = head->next;
            head->next = nextnode->next;
            nextnode->next = pre->next;
            pre->next = nextnode;                            
        }
        return dummy->next;
    }
};
```
啊啊啊ε＝ε＝ε＝(#>д<)ﾉ是这题好麻烦，还是我太弱。。加油呀！！欢迎指正，谢谢。