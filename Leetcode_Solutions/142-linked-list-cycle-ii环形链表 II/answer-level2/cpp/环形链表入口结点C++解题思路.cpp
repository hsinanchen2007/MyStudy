分享wall0p的代码和JobQ的思路分析
To understand this solution, you just need to ask yourself these question.
Assume the distance from head to the start of the loop is x1
the distance from the start of the loop to the point fast and slow meet is x2
the distance from the point fast and slow meet to the start of the loop is x3
What is the distance fast moved? What is the distance slow moved? And their relationship?

x1 + x2 + x3 + x2
x1 + x2
x1 + x2 + x3 + x2 = 2 (x1 + x2)
Thus x1 = x3

Finally got the idea.
```
ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) 
            return NULL;

        ListNode* firstp = head;
        ListNode* secondp = head;
        bool isCycle = false;

        while(firstp != NULL && secondp != NULL) {
            firstp = firstp->next;
            if (secondp->next == NULL) 
                return NULL;
            secondp = secondp->next->next;
            if (firstp == secondp) { 
                isCycle = true; 
                break; 
            }
        }

        if(!isCycle) 
            return NULL;

        firstp = head;
        while( firstp != secondp) {
            firstp = firstp->next;
            secondp = secondp->next;
        }

        return firstp;
    }
```
