### 解题思路
执行时间4ms优于97.86%C++提交，内存消耗13.7MB优于5.29%C++提交。
**算法流程**
1.获取链表长度n
2.根据n，k确定k次旋转后链表的头head_node和尾tail
3.将原链表变为环链表
4.令tail->next = NULL，返回head_node
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
    int n = 0;
    int index = -1;
    int tail_index = 0;
    int head_index = 0;
    ListNode* tail = NULL;
    ListNode* head_node = NULL;

    ListNode* rotateRight(ListNode* head, int k) {
        # 链表为空或者旋转次数为0则直接返回链表
        if ((not head) || (k==0)){return head;}
        ListNode* Head = head;
        # head指向的节点不断发生变化，但输入的链表没有发生任何变化
        while (head->next){
            n ++;
            head = head->next;
        }
        n = n + 1;
        # 链表长度为1时，无论旋转多少次链表都不变
        if (n == 1){return head;}

        k = k%n;
        if (k == 0){return Head;}
        head_index = n - k;
        tail_index = n -k -1;
        # 将原链表的尾指向链表的头，形成环链表
        head->next = Head;

        while (1){
            index ++;
            if (index == tail_index){tail = Head;}
            if (index == head_index){head_node = Head;
            break;}
            Head = Head->next;
        }

        tail->next = NULL;
        return head_node;
    }
};
```