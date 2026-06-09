前提：

1、	链表非环节点长度t；

2、	链表环节点长度c；

3、	快慢指针同时从头节点出发，慢指针恰好在入环口时，定义快指针在环中的位置为h。 

![image.png](https://pic.leetcode-cn.com/c95b4087185eb92b206867da405e60c017b53015af7721f5eb463202892da73f-image.png)

slow走了t步，fast走了t+nc+h步。因为fast是slow的2倍速，所以
2t = t + nc +h;
t = nc + h
n表示绕环圈数

此时slow领先fast的c-h个节点。所以slow走c-h节点，fast走2(c-h)个节点时，快慢指针相遇。

![image.png](https://pic.leetcode-cn.com/d32159447a67918a9c786139e25d7806fe124f5c0a70cc141904570fbd8f8baa-image.png)


反证明：slow节点重新指向头节点处，一次向前位移一个节点，fast节点一个向前位移一个节点，两个节点将在入环节点处相遇。

上面已经推导出：t = nc + h
fast节点到入环节点的距离为h，因为第一次到达时，slow可能还在路上，所以fast以入环处为起点绕环n次（n>=0），一定会和slow节点相遇在入环节点处。

    struct ListNode *detectCycle(struct ListNode *head) {
        struct ListNode *slow = head;
        struct ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
