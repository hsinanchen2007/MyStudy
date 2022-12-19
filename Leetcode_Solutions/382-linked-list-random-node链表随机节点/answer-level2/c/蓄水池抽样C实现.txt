

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    struct ListNode *node;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */

Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = malloc(sizeof(Solution));
    obj->node = head;

    return obj;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    int cnt = 0, t = 0;
    struct ListNode *pNode = NULL;
    struct ListNode *pRetNode = NULL;

    if(NULL == obj || NULL == obj->node)
        return -1;

    for(pNode = obj->node; pNode != NULL; pNode = pNode->next)
    {
        if(0 == cnt++)
            pRetNode = pNode;
        else
        {
            t = rand()%cnt;
            if(t < 1)
                pRetNode = pNode;
        }
    }

    return pRetNode->val;
}

void solutionFree(Solution* obj) {
    free(obj);
    obj = NULL;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/