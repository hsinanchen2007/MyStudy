### 解题思路
首先找到最后一个节点，然后再找到倒数第k个节点，最后一直返回该节点。

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
    ListNode* getKthFromEnd(ListNode* head,int& k){
	if(head==NULL) {
		return head;
	}
	ListNode* temp = getKthFromEnd(head->next,k);
	if(temp==NULL){
		k--;
	} 
	if(temp!=NULL&&k==0){
		return temp;
	}
	if(k==0){
		return head;
	}
	return temp;
}
};
```