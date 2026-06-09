```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode( struct ListNode * node ) {

    struct ListNode * form = node;
    struct ListNode * next = node -> next;

    while( next != NULL ){

        node ->  val = next -> val;
        form = node;
        node = next;
        next = next -> next;
    }

    form -> next = NULL;
    
}
```
