/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *temp = head;
	
	if ((l1 == NULL) || (l2 == NULL)){
		if (l1 == NULL){
			return l2;
		}
		if (l2 == NULL){
			return l1;
		}
		
		return NULL;
	}
	
	while (l1 != NULL || l2 != NULL){
		if (l1 == NULL){
			temp->next = l2;
			return (head->next);;
		}
		
		if (l2 == NULL){
			temp->next = l1;
			return (head->next);;
		}
		
		if ((l1->val) > (l2->val)){
			temp->next = l2;
			l2 = l2->next;
		}
		else {
			temp->next = l1;
			l1 = l1->next;
		}
		
		temp = temp->next;
		
	}

	return (head->next);
}