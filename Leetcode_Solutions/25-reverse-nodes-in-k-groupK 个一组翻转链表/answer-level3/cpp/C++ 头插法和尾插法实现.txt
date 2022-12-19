### 解题思路
按照思路思考顺序来讲解的话,由于调试了很多次才成功,所以就简单记录一下,这里采用了两个方式,根据反转时使用的方法不同分为头插法和尾插法
1. 头插法实现思路和<92题反转链表2中反转m~n的>思路是一致的,只不过多了一些步骤,用来控制需要反转多少个分段,每个分段反转都需要记录头结点,尾节点然后从新定位指向的方式和92题反转完全一致,所以不过多讲解, 控制反转多少个分段就是计算长度然后整除取整, 然后再在每个分段循环内反转分段
2. 尾插法是参考头插法实现的,思路同样是分段处理,每k个元素分为一段,然后计算出当前分段的尾节点kNode,从分段首节点依次遍历,每个节点都插入到尾结点后,即1->2->3依次变为2->3->1; 3->2->1, 当前分段反转完成后,移动分段的尾节点指向下一分段的第k个节点,同时移动current指向下一分段首节点即可
3. 无论是头插法还是尾插法都是完全按照题干要求,采用最直接的方式实现的,题干要求每k个元素反转,就以k个元素分段处理,再处理单段内的节点反转,除了会在写代码时思路混乱,不存在逻辑上的难点,所以这次题解就简单写 

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;

        // 需要使用虚拟头结点来处理head
        ListNode *virtualNode = new ListNode(-1);
        virtualNode->next = head;

        // 反转链表后头结点的前一节点, 用来更新链表指向反转部分的链表头部
        ListNode *prev = virtualNode;

        // 记录当前节点, 用于记录遍历结点位置
        ListNode *current = head;
        ListNode *carNode = virtualNode;

        // 记录相对当前节点的第k个节点
        ListNode *kNode = head;

        bool  isEnd = false;
        while (current != NULL) {
            if (current == kNode) {
                // 重置相对位置
                kNode = carNode;
                // 先遍历k找到相对当前节点的第k个节点
                int  cycle = k;
                while(cycle > 0) {
                    // 记录当前节点
                    kNode = kNode->next;
                    cycle--;

                    if (kNode == NULL) {
                        isEnd = true;
                        break;
                    }
                }

                prev = carNode;
                current = carNode->next;
                carNode = carNode->next;
            }

            if (isEnd) break;

            // 采用尾插法
            prev->next = current->next;
            current->next = kNode->next;
            kNode->next = current;

            current = prev->next;
        }

        return virtualNode->next;
    }
};
```

### 头插法
```c++
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;

        // 需要使用虚拟头结点来处理head
        ListNode *virtualNode = new ListNode(-1);
        virtualNode->next = head;

        // 反转链表后头结点的前一节点, 用来更新链表指向反转部分的链表头部
        ListNode *prev = virtualNode;

        // 记录当前节点, 用于记录遍历结点位置
        ListNode *current = head;

        // 首先遍历节点并获取长度, 用于计算需要反转次数
        int cycle = k;
        int length = 0;
        while (current != NULL)  {
            current = current->next;
            length++;
        }

        // 重置节点
        prev = virtualNode;
        current = head;

        // 记录可翻转次数
        int reverseNumber = length / k;
        cycle = k;

        // 头插法的虚拟头结点,用来实现头插法
        ListNode *tepNode = NULL;

        // 用来记录当前节点的下一结点,下一次反转需要操作的值
        ListNode *tail = NULL;

        // 反转链表
        while (reverseNumber > 0) {

            while ((cycle > 0) && (current != NULL)) {
                // 记录下一次遍历的节点
                tail = current->next;

                // 头插法
                current->next = tepNode;
                tepNode = current;

                current = tail;
                cycle--;
            }

            // 处理头结点, 尾结点新的指向

            // 未反转之前的部分链表得头结点,也就是反转之后的尾节点 node = 1
            ListNode *node = prev->next;

            // 尾结点指向下一次遍历的头结点 1->4->5->6
            node->next = tail;

            // 指向新的反转链表的头结点,temNode = 3->2->1->4->5->6
            prev->next = tepNode;

            // 移位 prev = 1
            prev = node;

            reverseNumber--;
            cycle = k;
        }

        return virtualNode->next;
    }
```