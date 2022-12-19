### 解题思路
利用哑结点的特性，我们给链表添加哑结点，然后把链表分为两部分，即奇数节点为一部分，偶数节点为一部分，firstNode指的是交换的节点前面的节点，secondNode指的是要交换的节点后面的节点。
step1：声明哑结点dummyHead和指针ptr，分别并指向头节点head和头节点head的前驱
step2：在链表不为空的情况下，firstNode遍历链表中的偶数节点，secondNode遍历链表中的奇数节点，并交换节点。
step3：重置节点并释放空间
![1.png](https://pic.leetcode-cn.com/008953b031ec05d1fc3effbbf61fa9deb2a3af811da6c75d770527f85b408d28-1.png)


时间复杂度:O(n)
空间复杂度:O(1)

### 代码

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *ptr = dummyHead;
        while(ptr->next != nullptr && ptr->next->next != nullptr)
        {
            ListNode *firstNode = ptr->next;
            ListNode *secondNode = ptr->next->next;
            //交换节点
            ptr->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            ptr = firstNode;
        }
    /* ListNode *prevNode = dummyHead;
        while(head && head->next != nullptr)
        {
            ListNode *firstNode = head;
            ListNode *secondNode =head->next;

            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            prevNode->next = secondNode;
            prevNode = firstNode;
            head = firstNode->next;
        }
    */
        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};
```