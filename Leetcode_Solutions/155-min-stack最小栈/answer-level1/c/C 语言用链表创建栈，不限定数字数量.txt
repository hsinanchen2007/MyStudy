```
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef struct node{
    int val;
    struct node *next;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    obj->next = NULL;
    return obj;
}

// push to the head
void minStackPush(MinStack* obj, int x) {
    MinStack *new_node = minStackCreate();
    new_node->val = x;

    MinStack *head = obj->next;
    obj->next = new_node;
    new_node->next = head;
}

void minStackPop(MinStack* obj) {
    MinStack *head = obj->next;
    if (head == NULL)
        return;
    MinStack *next = head->next;
    obj->next = next;

    free(head);
}

int minStackTop(MinStack* obj) {
    struct node *head = obj->next;
    if (head == NULL)
        return INT_MIN;
    return head->val;
}

int minStackGetMin(MinStack* obj) {
    MinStack *head = obj->next;
    if (head == NULL)
        return INT_MIN;
    int min = INT_MAX;
    while (head != NULL) {
        min = MIN(min, head->val);
        head = head->next;
    }    
    return min;
}

void minStackFree(MinStack* obj) {
    MinStack *head = obj->next;
    if (head != NULL) {
        for (MinStack **cur = &head; *cur;) {
            MinStack *entry = *cur;
            *cur = entry->next;
            free(entry);
        }
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```
