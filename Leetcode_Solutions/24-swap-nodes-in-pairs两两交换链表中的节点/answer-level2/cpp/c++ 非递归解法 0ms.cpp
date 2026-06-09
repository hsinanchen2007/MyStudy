
## 步骤说明

先上说明，可以结合后续代码具体看。

### 第一步：创建临时头节点

为什么一定要创建临时头节点？因为在前两个节点交换了之后，head 从指向头节点变成了指向第二个节点，所以需要一个临时头节点，来记录交换之后的头节点。

### 第二步：创建两个指针，进行遍历

具体大概流程：
1. 判断 last->next && last->next->next 作为循环条件，说明剩余未遍历的节点超过两个才继续进行。
2. 将 last 向后移动两位，然后交换 pre->next 以及 last 这两个节点。
3. 更新 pre、last 的指针，指向当前遍历过的最后一个节点。（注意仍需更新 last 指针的位置，因为交换后 last 不再是遍历过的最后一个节点）

### 第三步：删除临时头节点，返回结果

头节点通过 new 方法创建，如果不删除会造成内存泄漏；删除头节点需要额外的时间：
- 如果删除头节点：用时 4ms，内存消耗 8.5MB
- 不删除头节点：用时 0ms，内存消耗 8.6MB

## 代码

```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // create a temp head ListNode
        ListNode *tempHead;
        tempHead = new ListNode(0);
        tempHead->next = head;
        auto pre = tempHead;
        auto last = tempHead;
        while(last->next&&last->next->next) {
            // move two steps
            last = last->next->next;
            // swipe two nodes
            pre->next->next = last->next;
            last->next = pre->next;
            pre->next = last;
            // NOTICE: need to last again
            last = last->next;
            pre = last;
        }
        // delete temp head
        pre = tempHead->next;
        delete tempHead;
        return pre;
    }
};
```