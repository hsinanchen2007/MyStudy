```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
```

- step1: 如果两个链表有一个为空（必定无交点），返回NULL即可
- step2: 定义两个指针currentNodeA和currentNodeB分别指向A、B两链表的头结点
- step3: 遍历两链表，当currentNodeA到A链表的末尾时，令其指向B的头结点；B同理（消除两链表的长度差）
- step4: 当currentNodeA与currentB相同时退出循环
- step5: 返回结果

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        
        ListNode *currentNodeA = headA, *currentNodeB = headB;
        while (currentNodeA != currentNodeB) {
            currentNodeA = currentNodeA != NULL ? currentNodeA->next : headB;
            currentNodeB = currentNodeB != NULL ? currentNodeB->next : headA;
        }
            
        return currentNodeA;
    }
};
```

### （与上法相同，更直观而已）
- step1: 计算链表A和链表B的长度
- step2: 计算A与B长度的差值
- step3: 调整较长链表的头指针（若两链表相交，链表尾部必定重合，所以需从距链表尾结点相同的距离开始找，这个距离的最大值为短链表的长度，所以需调整指向长链表的指针）
- step4: 同时开始遍历A、B两链表，直到两指针指向相同对象
- step5: 返回结果

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getListLength(headA), lengthB = getListLength(headB);
        
        int discrepancy = lengthA - lengthB;
        
        if (discrepancy > 0)
            for (int i=0; i < discrepancy; i++) 
                headA = headA->next;
        else 
            for (int i=0; i < abs(discrepancy); i++)
                headB = headB->next;
        
        while (headA != headB) {
            headA = headA == NULL ? NULL : headA->next;
            headB = headB == NULL ? NULL : headB->next;
        }
        
        return headA;
    }
private:
    int getListLength(ListNode *head) {
        int length = 0;
        
        while (head) {
            length++;
            head = head->next;
        }
        
        return length;
    }
};
```