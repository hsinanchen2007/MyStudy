---
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

---

### 方法一：外部容器

将链表转存至新的容器vector内，再利用vector本身的reverse_iterator进行反向遍历，将内容一一对应存入链表节点内。

```c++
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }

        vector<int> store;
        while (head != NULL)
        {
            store.push_back(head->val);
            head = head->next;
        }

        ListNode* resHead = new ListNode(0);
        ListNode* p = resHead;
        ListNode* q = nullptr;
        p->val = *(store.rbegin());
        for (vector<int>::reverse_iterator riter = store.rbegin() + 1; riter != store.rend(); riter++)
        {
            q = new ListNode(0);
            q->val = *riter;
            p->next = q;
            p = q;
        }
        p->next = NULL;
        return resHead;
    }
};
```

##### 复杂度分析

- 时间复杂度：*O*(*n*)，其中*n*为链表长度。
- 空间复杂度：*O*(*n*)。



### 方法二：迭代

在遍历列表时，将当前节点的 next 指针改为指向它的前一个节点。分别需要一个指针用来记录上一个节点（previous），当前节点（current）以及下一个节点（next）。

```c++
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != NULL)
        {
            ListNode* nextTemp = nullptr;
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
```

##### 复杂度分析

- 时间复杂度：*O*(*n*)，其中*n*为链表长度。
- 空间复杂度：*O*(1)。



### 方法三：递归

递归方法比较难理解，假设我们传入的链表为``1->2->3->4->5->NULL``，那么传入的``head``即节点``1``，递归令节点``curr``等于``reverseList(head->next)``，终止条件为``head或head->next为空``，并返回``head``。

在这个例子中，最后一层返回的即节点``5``，此时``head``指向节点``4``，我们令``head->next->next = head``，即``1->2->3->4->5->4``：

![image-20200212170704129.png](https://pic.leetcode-cn.com/8aa2c8ba1f96bb1e1babf20417e022dc683a7bf77647c946479b05694b53edeb-image-20200212170704129.png)

接着，令``head->next = null``，即``1->2->3->4->null``且``5->4``：

![image-20200212170719065.png](https://pic.leetcode-cn.com/e7d65316ef233d2e4d12cb241279e88c0c6c67be3d3a2abfbcf20b1900584231-image-20200212170719065.png)

```c++
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* curr = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return curr;
    }
};
```

##### 复杂度分析

- 时间复杂度：*O*(*n*)，其中*n*为链表长度。
- 空间复杂度：*O*(*n*)，递归至*n*层。