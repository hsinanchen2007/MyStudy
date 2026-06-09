### 提交结果

执行用时 :20 ms, 在所有 C++ 提交中击败了90.39% 的用户
内存消耗 :11 MB, 在所有 C++ 提交中击败了5.10%的用户

### 解题思路
思路见题的提示。我的解法是纯粹的指针之间的赋值。并没有采取构造新节点然后插入的方法。

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
			return nullptr;
		if (!head->next)
			return head;

		ListNode* begin = head;
		// 主体循环
		for (ListNode* end = head, *move = end->next; end->next != nullptr;)
		{
			if (move->val >= end->val)
			{
				end = end->next;
				move = end->next;
				continue;
			}
			else
			{
				// 判断move是否到达尾节点
				(!move->next) ? (end->next = nullptr) : (end->next = move->next);
				// 进行前面的链表的遍历
				ListNode* vbegin = nullptr;
				ListNode* beginbackup = begin;
				// 这个遍历的范围是[begin,end]，设置两个指针，vbgein,begin
				for (vbegin, begin; begin != end->next; vbegin = begin, begin = begin->next)
				{
					// 寻找第一个大于move->val的节点
					if (begin->val > move->val)
					{
						if (!vbegin)
						{
							move->next = begin;
							break;
						}
						else
						{
							move->next = begin;
							vbegin->next = move;
							break;
						}
					}
				}
				// 循环结束，按照vbegin的值，重新设置begin/vbegin/move的值
				// vb值不为空，说明发生了中间插入
				(!vbegin) ? (begin = move) : (begin = beginbackup);
				vbegin = nullptr;
				move = end->next;
			}
		}
		return begin;
    }
};
```