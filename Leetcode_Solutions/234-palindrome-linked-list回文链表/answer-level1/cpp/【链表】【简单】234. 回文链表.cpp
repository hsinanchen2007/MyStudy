### 解题思路
首先，一个序列（不管是链表还是数组，抑或字符串）是否是回文，判断逻辑都是从该序列的中间开始向两边同时进行查找，两边的数据是否对称，如果对称，那么该序列就是回文的，否则就不是回文。

根据上面的描述，需要找到如下几个点：
1. 中间点在哪儿？
2. 中间点前后的对称数据是什么？

因为当前的序列是有明确定义的单链表，而单链表的特点是如果要进行查找只能从链表头开始遍历才能查找到对应的数据，那么如果要找到上面的两个点，比较明确的思路是这样：
1. 通过双指针找到中间点。方法可以通过不同迭代跨度的两个指针进行遍历，找到中间的链表节点；
2. 通过增加缓存数据结构来查找对称数据。因为单链表只能单项遍历，所以找到中间节点后无法进行前向遍历，所以我们在前面找中间点的过程中，将前半部分的数据存储在数组或是堆栈中，这样，只需要用中间节点向后遍历，然后再和缓存中的保存数据进行比较即可。

上面描述思路的代码详见代码章节的前半部分。

但是题目中还有一个要求，就是如何用O(1)的空间复杂度来进行判断。

O(1)的空间复杂度，就需要将上面描述思路中的第2部分的缓存数据结构通过其他的方法进行替换，因为链表只能从头开始进行遍历，那么从中间点如何遍历才能和前半部分进行对比成了一个关键的算法点。

如果不能往回进行遍历，那么我们将后半部分的链表进行倒序，这样就可以通过后向遍历即可找到对称数据了，代码详见代码章节的后半部分。

### 代码

1. 正常思路

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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        int num = 0;
        ListNode *cur = head;
        while (cur != NULL) {
            num++;
            cur = cur->next;
        }
        // find the mid val of the list
        ListNode *pre = head;
        ListNode *p = head->next;
        ListNode *pMid = head->next->next;
        stack<int> s;
        s.push(pre->val);

        while (pMid != NULL) {
            pre = p;
            p = p->next;
            s.push(pre->val);
            pMid = pMid->next;
            if (pMid == NULL) {
                break;
            } else {
                pMid = pMid->next;
            }
        }

        // cout << "The size is " << s.size() << endl;
        // check the size of the stack
        // if the size is even，pop, else go on
        if (s.size() > (num / 2)) {
            s.pop();
        }

        // move the mid to the end and 
        // compare the mid to the val in the stack
        while (p != NULL) {
            // cout << "s.top is " << s.top() << " and the p->val is " << p->val << endl;
            if (s.top() != p->val) {
                    return false;
                }
                s.pop();
                p = p->next;
            }

        return true;
    }
};
```

2. 倒序思路

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
    ListNode* reverseList(ListNode *head) {
        // if only one, return the list
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // three points 
        // one for previous
        // one for current
        // and one for the next
        ListNode *pre = head;
        ListNode *cur = head->next;
        ListNode *nex = cur->next;

        while (cur != NULL) {
            cur->next = pre;
            pre = cur;
            ListNode *tmpNex = nex;
            cur = tmpNex;
            if (tmpNex != NULL) {
                nex = tmpNex->next;
            }
        }

        head->next = NULL;
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

       // find the mid val of the list
        ListNode *pre = head;
        ListNode *p = head->next;
        ListNode *pMid = head->next->next;

        while (pMid != NULL) {
            pre = p;
            p = p->next;
            pMid = pMid->next;
            if (pMid == NULL) {
                break;
            } else {
                pMid = pMid->next;
            }
        }

        pMid = reverseList(p);
        ListNode *cur = head;

        while (pMid != NULL) {
            if (cur->val != pMid->val) {
                    return false;
                }
                pMid = pMid->next;
                cur = cur->next;
            }

        return true;
    }
};
```