
## 思路分析
如题假设 链表节点为 1->2->3->4->5, 翻转 [2,4] 区间的节点，那么链表就会被分割为：
* A：1
* B：2->3->4
* C：5

B部分翻转用三指针法，最后将A, B'(翻转后)，C连接起来即可；对于连接A,B',C，需要在遍历链表的过程中记录，截断处节点1，翻转后的最后一个节点2，翻转后的第一个节点4，以及剩余的链表的第一个节点5,即可完成连接。

## 代码实现
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *start = new ListNode(0);
        start->next = head;
        // 定义： cut截断的位置，p当前位置，tail截断翻转后的最后一个节点，pre做指针指向切换用并且亦是截断处翻转后的第一个节点
        ListNode *cut = start, *p = start->next, *tail=nullptr, * pre = nullptr;
        int currentIndex=1;
        while(p!=nullptr){
            if(currentIndex>n) break;
            if(currentIndex>=m){
                if(tail==nullptr){
                    tail = p;
                    pre = p;
                    p=p->next;
                }else{
                    ListNode *after = p->next;
                    p->next = pre;
                    pre = p;
                    p = after;
                }
            }else{
                cut = p;
                p=p->next;
            }
            currentIndex++;
        }
        // 连接被截断的三个子链表
        cut->next = pre;
        if(tail) tail->next = p;

        return start->next;
    }
};
```
执行效率如下:
- 执行用时 :4 ms
- 内存消耗 :8.5 MB
