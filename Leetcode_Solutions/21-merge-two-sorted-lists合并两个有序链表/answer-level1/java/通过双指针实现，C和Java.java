# C实现
```
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode node = {-1, NULL};
    struct ListNode* head = &node;
    struct ListNode* current = head;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val <= l2->val) {
            current->next = l1;
            current = current->next;
            l1 = l1->next;
        } else {
            current->next = l2;
            current = current->next;
            l2 = l2->next;
        }
    }
    if(l1 != NULL) {
        current->next = l1;
    }
    if(l2 != NULL) {
        current->next = l2;
    }
    return head->next;
}
```
# Java实现
```
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode node1 = l1;
        ListNode node2 = l2;
        ListNode resultNode = new ListNode(-1);
        ListNode currentNode = resultNode;
        while(node1 != null && node2 != null) {

            if(node1.val <= node2.val) {
                    currentNode.next = node1;
                    currentNode = currentNode.next;
                    node1 = node1.next;
            } else {
                    currentNode.next = node2;
                    currentNode = currentNode.next;
                    node2 = node2.next;
            }
        }
        if(node1 != null) {
            if(currentNode == null) {
                resultNode = node1;
            } else {
                currentNode.next = node1;
            }
            
        }
        if(node2 != null) {
            if(currentNode == null) {
                resultNode = node2;
            } else {
                currentNode.next = node2;
            }
            
        }
        return resultNode.next;
    }
}
```

