# 445. 两数相加 II
利用栈保存两个列表的值，再分别出栈计算。
```
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode rstHead(0);
		rstHead.next = NULL;
		
        stack<int> first_num;
		stack<int> second_num;
		
		while( l1 || l2 ){
			if( l1 ){
				first_num.push(l1->val);
				l1=l1->next;
			}
			if( l2 ){
				second_num.push(l2->val);
				l2=l2->next;
			}
		}
		
		int extre_add = 0;
		while( !first_num.empty() || !second_num.empty() || extre_add ){
			int num1 = 0;
			int num2 = 0;
			if( !first_num.empty() ){
				num1 = first_num.top();
				first_num.pop();
			}
			if( !second_num.empty() ){
				num2 = second_num.top();
				second_num.pop();
			}
			int rst = num1 + num2 + extre_add;
			
			ListNode *temp = new ListNode(rst%10);
			
			if( rst >= 10 ){
				extre_add = 1;
			}else{
				extre_add = 0;
			}
			
			temp->next = rstHead.next;
			rstHead.next = temp;
		}
		return rstHead.next;
    }
};
```
