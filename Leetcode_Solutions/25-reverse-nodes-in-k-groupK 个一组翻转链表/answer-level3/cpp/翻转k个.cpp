```class Solution {
public:
  ListNode* flatK(ListNode* h, int k, ListNode** n) {
 	int tk = k;
 	ListNode* a = NULL;
 	while(k-- > 0 && h) { 
 		ListNode* l = h->next;
 		h->next = a;
 		a = h;
 		h = l;
 	}
    k = k+1; //因为先--
 	if(k == 0) *n = h;
 	if(k != 0) {
 	    return flatK(a, tk - k, n); //不足时恢复
 	}

 	return a;
 }

 ListNode* reverseKGroup(ListNode* head, int k) {
 	 ListNode* h = new ListNode(-1);
 	 ListNode* l = h;
	 ListNode* t = head;
	 ListNode* n = NULL;
	 while(t) {
	 	l->next = flatK(t, k, &n); //n代表 t应该的下个位置
	 	l = t;
	 	t = n;
	 }
	 return h->next;     
 }
};
```
