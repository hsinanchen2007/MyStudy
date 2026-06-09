struct ListNode *Merge2List(struct ListNode *a, struct ListNode *b)
{
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}
	if (a->val <= b->val) {
		a->next = Merge2List(a->next, b);
		return a;
	}
	b->next = Merge2List(a, b->next);
	return b;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
	if (listsSize <= 0) { 
		return NULL;
	}
	if (listsSize == 1) {
		return lists[0];
	}
	if (listsSize == 2) {
		return Merge2List(lists[0], lists[1]);
	}
	struct ListNode *left = mergeKLists(lists, listsSize / 2);
	// Print(left);
	struct ListNode *right = mergeKLists(&lists[listsSize / 2], listsSize - listsSize / 2);
	// Print(right);
	return Merge2List(left, right);
}