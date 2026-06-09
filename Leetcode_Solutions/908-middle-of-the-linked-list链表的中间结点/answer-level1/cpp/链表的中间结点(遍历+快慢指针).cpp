- 方法一: 遍历，保存到数组

思路: 遍历链表，逐个摘下结点保存到数组中，遍历结束后，返回数组长度/2的下标元素即可。

```cpp
    ListNode *middleNode(ListNode *head) {
        if (!head)
            return nullptr;
        vector<ListNode> res;
        ListNode* p = head;
        while (p != nullptr){
            res.push_back(p);
            p = p->next;
        }
        return res[res.size() / 2];
    }
```

- 方法二: 快慢指针

思路: 使用双指针，慢指针每次移动一个结点，快指针每次移动两个结点，同时移动快慢指针，当快指针遍历结束时，慢指针处在链表中间结点位置。

```cpp
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
```