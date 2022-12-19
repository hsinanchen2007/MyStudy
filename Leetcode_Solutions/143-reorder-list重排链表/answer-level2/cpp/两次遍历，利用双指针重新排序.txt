### 解题思路
思路比较直观，通过两次遍历实现。第一次先把链表全部打散，把节点按顺序存入vector，第二次利用双指针遍历vector，指针i从前往后，指针j从后往前，按先i后j的顺序接入链表，i、j相遇时算法结束。只需要注意节点为奇数情况下，尾节点被插入了两次，自己指向了自己，此时只需要把尾节点的next指向NULL即可。

![1.png](https://pic.leetcode-cn.com/d6c6ef1d881dd6179054fe5f7b7502afa82d51b022610541458ce44037c7491b-1.png)


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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode *tmp = head;

        //第一次遍历，把链表拆散存进vector
        while (head) {
            tmp = head;
            head = head->next;
            tmp->next = NULL;
            v.push_back(tmp);
        }

        //第二次遍历，用双指针重排，这里tmp指向链表尾
        for (int i = 0, j = v.size()-1; i <= j; i++, j--) {
            if (!head) {
                head = v[i];
                tmp = head->next = v[j];
            } else {
                tmp->next = v[i];
                tmp = tmp->next;
                tmp->next = v[j];
                tmp = tmp->next;
            }

            if (i == j) { //如果i==j，尾节点被插入了两次，自己指向自己
                tmp->next = NULL;
            }
        }
    }
};
```