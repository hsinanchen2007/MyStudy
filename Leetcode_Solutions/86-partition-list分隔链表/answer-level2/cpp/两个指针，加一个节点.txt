### 解题思路
代码其实不算简洁，不过我觉得自己的注释写的很清楚，哈哈。
跑出来的效果还不错，如果有什么问题，请大家指出，谢谢咯。
![Snipaste_2020-01-10_15-47-38.png](https://pic.leetcode-cn.com/b6cc7d34de0de026365c5f9ff5fba04268849974dbe2bef1ea4794adad91f55f-Snipaste_2020-01-10_15-47-38.png)


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
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* ref = dummy;
		ListNode* point = NULL;                     // 用于存放第一个值大于等于 x 的节点
		ListNode* cur = head;
		while (cur != NULL) {
			if (cur->val < x && point == NULL) {    // 当前节点的值小于x，在此之前未出现值大于等于 x 的节点
				ref->next = cur;
				ref = ref->next;    // 新的 ref 节点
				cur = cur->next;    // 新的 cur 节点
			}
			else if (cur->val < x && point != NULL) {   // 当前节点的值小于 x ，在此之前已经找到值大于等于 x 的节点
				ref->next = cur;
				point->next = cur->next;
				cur->next = point;
				cur = point->next;	// 新的 cur 节点
				ref = ref->next;	// 新的 ref 节点
			}
			else if (cur->val >= x && point == NULL) {  // 当前节点的值大于等于 x ，在此之前未找到大于等于 x 的节点
				point = cur;
				ref->next = point;
				point->next = cur->next;
				cur = point->next;  // 新的 cur 节点
			}
            else {  // 当前节点的值大于等于 x ，在此之前已经找到值大于等于 x 的节点
                if(cur->next != NULL && cur->next->val < x) {   // 若下一个节点不为 NULL ，且值小于 x
                    ref->next = cur->next;
				    cur->next = cur->next->next;
				    ref->next->next = point;
				    ref = ref->next;		// 新的 ref 节点
                }
                else {  // 若下一个节点不为 NULL ，且值大于等于 x ，或下一个节点为 NULL
                    cur = cur->next;        // 新的 cur 节点
                }
            }
		}
		return dummy->next;
	}
};
```