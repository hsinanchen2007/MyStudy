```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        // 声明两个指针分别指向当前已经排好序的奇数节点和偶数节点
        ListNode* pre1 = head, *pre2 = head->next;
        while(pre2->next) {
            //将当前的奇数节点插入到排好序的奇数节点的尾部
            ListNode* tmp = pre2->next;
            pre2->next = tmp->next;
            tmp->next = pre1->next;
            pre1->next = tmp;
            // 更新pre1, pre2
            pre1 = pre1->next;
            pre2 = pre2->next;
            // 当节点总数为奇数个，遍历完最后一个奇数节点后，此时pre2已经为空
            if(!pre2) break;
        }
        return head;
    }
};
```
