### 解题思路
此题如果不使用临时缓冲，最直观的解法就是对链表中的每个元素遍历其后的所有元素，然后删除重复元素，剩下的就是最开始出现的点。但是这种算法的时间复杂度是O(N^2)，空间复杂度是O(1)。

如果使用临时缓冲，那么直观的解法就是使用一个数据结构（这个数据结构可以是map，也可以是vector）来存储首次发现的元素，在链表遍历的过程中，判断元素在该结构中是否存在，如果存在则删除链表中的该元素，否则将该元素存入临时创建的数据结构中。此种算法的遍历的时间复杂度是O(N)，但是注意，我们在判断元素是否在数据结构中是否存在的时候，也会去遍历临时数据结构，所以整体的时间复杂度可能仍然是O(N^2)。

数组在查找给定下标元素的时候的时间复杂度是O(1)，我们可以利用这个特性来使整体的算法复杂度变为O(N)。题目中给出了链表长度为[0, 20000]，而元素的范围也是[0, 20000]，我们创建一个20001大小的数组，使用下标来对应链表元素，数组中的值记录该元素是否存在，这样可以保证时间复杂度满足要求。


### 代码

1. 使用map作为数据结构
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        // if null or one node return head
        if (!head || head->next == NULL) {
            return head;
        }

        // prepare the map
        map<int, int> m;
        m.insert({head->val, 1});

        ListNode *pre = head;
        ListNode *p = head->next;

        // traverse the list remove the duplicate nodes
        while (p != NULL) {
            if (m.find(p->val) != m.end()) {
                // remove the node and continue
                pre->next = p->next;
                delete p;
                p = pre->next;
                continue;
            } else {
                // add the node into the map
                m.insert({p->val, 1});
            }

            pre = p;
            p = p->next;
        }

        return head;
    }
};
```

2. 使用20001大小的数组作为数据结构
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        // if null or one node return head
        if (!head || head->next == NULL) {
            return head;
        }

        // prepare the map
        int m[20001] = {0};
        m[head->val] = 1;

        ListNode *pre = head;
        ListNode *p = head->next;

        // traverse the list remove the duplicate nodes
        while (p != NULL) {
            if (m[p->val] == 1) {
                // remove the node and continue
                pre->next = p->next;
                delete p;
                p = pre->next;
                continue;
            } else {
                // add the node into the map
                m[p->val] = 1;
            }

            pre = p;
            p = p->next;
        }

        return head;
    }
};
```