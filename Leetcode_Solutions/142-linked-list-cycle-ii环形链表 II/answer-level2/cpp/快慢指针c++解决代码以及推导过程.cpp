### 解题思路

设链表形式如右侧：  ——a——b——c
环节点为a处，相遇为b处。长度分别为A，B，C，L=A+B+C。
所以有以下方程组：
$$\begin{cases}
 (1) L=A+B+C\\
 (2) F=2S\\
 (3) F=L+B+n(B+C)，n>=0\\
 (4) S=A+B\\
\end{cases}
$$
将（1）式代入（3），然后将（3）（4）代入（2）两边可得：
$$C+n(B+C)=A$$
此时指针cur从头开始出发，到达环节点时，移动了A，而指针slow移动了$S+A=A+B+C+n(B+C)=A+(n+1)(B+C),(n+1)(B+C)$一直在环内循环，最后移动了A，即相当于停留在环节点，所以这两指针相遇处就是环节点处。
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
class Solution {//快慢指针，相遇时第三个指针开始移动
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				ListNode* cur = head;
				while (cur != slow) {
					cur = cur->next;
					slow = slow->next;
				}
				return cur;
			}
		}
		return NULL;
	}
};
```