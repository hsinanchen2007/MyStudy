### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    struct ListNode* head;
    int val;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */

Solution* solutionCreate(struct ListNode* head) {
    Solution *result = (Solution*)malloc(sizeof(Solution));
    srand(time(0));
    result->head = head;
    return result;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    int max = INT_MIN;
    int current_rand = 0;
    int current_val = 0;
    struct ListNode* head = obj->head;

    while(head){
        current_rand = rand();
        if(current_rand>max){
            max = current_rand;
            current_val = head->val;
        }
        head=head->next;
    }
    obj->val = current_val;
    return obj->val;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
```