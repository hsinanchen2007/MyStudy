![捕获.PNG](https://pic.leetcode-cn.com/e4887c08969c48e71fab95f3dd821c61b43b66c2b82e2e9f754c3e3d71455f3b-%E6%8D%95%E8%8E%B7.PNG)

考虑到m=1的情况，要创建一个preHead头节点，保证操作一致性。
将preNode指针指向m前的节点，记m节点为dummyTail = preNode->next。
curNext = curNode->next用来保存下一节点的指针。
然后用curNode = preNode->next->next指向m节点后的节点，用头插法将该节点插到preNode节点后，
移动curNode指向curNext，循环用头插法执行和上一步同样的操作n-m次。
循环结束后dummyTail->next = curNext,即：把原来的m节点的next指针指向原来的n节点的后继节点



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
        //将简单情况单独列出，加快简单情况的运行速度，而且减少边界情况出错的可能性。
        if(head == nullptr || m == n || head->next == nullptr) return head;
        int times = n-m;
        ListNode* preHead = new ListNode(-1);
        preHead->next = head;

        ListNode* preNode = preHead;
        while(m-1 != 0){
            preNode = preNode->next;
            m--;
        }
        ListNode* dummyTail = preNode->next;
        ListNode* curNode = preNode->next->next;
        ListNode* curNext = nullptr;
        while(times>0){
            curNext = curNode->next;
            curNode->next = preNode->next;
            preNode->next = curNode;
            curNode = curNext;
            times--;
        }
        dummyTail->next = curNext;
        return preHead->next;
    }
};