### 解题思路
st1: ...->1->2->3->4->5..  							//起始状态
st2: ...->1->2->4->5..  (listnode *t=3->4->5..)   	//2->next 链接  4, 中间变量t缓存
st3:     t=3->5..
st4: ...->1->2->4->(3->5..)            				//4->next 链接  t,    

ps: 不允许使用tmp->next->next 有点奇怪
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
	ListNode* swapPairs(ListNode* head) {
		
		if (head == NULL)
		{
			return head;
		}
		if (head->next == NULL)
		{
			return head;
		}
		ListNode *R=head->next;   		//新的头
		ListNode *now = head->next;	
		ListNode *tmp = head;
		
		tmp->next = now->next;
		now->next = tmp;
		while (tmp->next != NULL)		//这里不允许tmp->next->next 有点奇怪
		{
			ListNode *tn= tmp->next;	//中止判断 
			if (tn->next == NULL)		
				break;
			ListNode *t = tmp->next;	//st2 缓存tn
			tmp->next = tmp->next->next;//st2 桥接4
			now = tmp->next;			//更新定位
			tmp = t;
			
			tmp->next = now->next;    	//st3
			now->next = tmp;			//st4
		}
		return R;

	}
    
};
```