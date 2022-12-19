int getLinkSize(struct ListNode *head) {
	int size = 0;
	struct ListNode *temp = head;
	while (temp != 0) {
		temp = temp->next;
		size++;
	}
	return size;
}

struct ListNode* rotateRight(struct ListNode *head, int k) {
	int linkSize = getLinkSize(head);

	if(linkSize==0){
		return head;
	}

	int moveTime = k % linkSize;

	struct ListNode *temp = head;
	struct ListNode *tail = 0;

	struct ListNode *newTail = 0;
	struct ListNode *newHead = 0;

	if (moveTime ==0){
		return head;
	}

	for (int i = 0; i < linkSize; i++) {
		if (i == linkSize - moveTime - 1) {
			newTail = temp;
		}
		if (i == linkSize - moveTime) {
			newHead = temp;
		}
		if (i==linkSize-1){
			tail = temp;
		}
		temp = temp->next;
	}

	tail->next = head;
	head = newHead;
	newTail->next = 0;
	return head;
}