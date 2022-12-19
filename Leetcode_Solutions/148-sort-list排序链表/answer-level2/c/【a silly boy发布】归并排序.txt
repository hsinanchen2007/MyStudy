```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

void MergeList(ListNode* head, int left, int middle, int right, int *tmp)
{
    ListNode* head1Tmp = head;
    ListNode* head1TmpCpy = head;
    ListNode* head2Tmp = head;

    int i;
    int left1 = left;
    int left1Cpy = left;
    int left2 = middle + 1;
    int tmpIndex = left1;
    //printf("left1: %u, middle: %u,left2: %u\n", left1, middle, left2);

    if (left1 > middle) {
        return;
    }
    if (left2 > right) {
        return;
    }
    
    i = 0;
    while(i < left1) {
        i++;
        head1Tmp = head1Tmp->next;
    }
    head1TmpCpy = head1Tmp;
    i = 0;
    while(i < left2) {
        i++;
        head2Tmp = head2Tmp->next;
    }

    //printf("head1Tmp->val: %u, head2Tmp->val: %u, tmpIndex: %u\n", head1Tmp->val, head2Tmp->val, tmpIndex);

    while ((left1 <= middle) && (left2 <= right)) {
        if ((head1Tmp->val) < (head2Tmp->val)) {
            tmp[tmpIndex] = head1Tmp->val;
            //printf("tmp[%u]: %u\n", tmpIndex, tmp[tmpIndex]);
            left1++;
            if (left1 <= middle) {
                head1Tmp = head1Tmp->next;
            }
        } else {
            tmp[tmpIndex] = head2Tmp->val;
            //printf("tmp[%u]: %u\n", tmpIndex, tmp[tmpIndex]);
            left2++;
            if (left2 <= right) {
                head2Tmp = head2Tmp->next;
            }
        }
        tmpIndex++;
    }

    while (left1 <= middle) {
        tmp[tmpIndex] = head1Tmp->val;
        tmpIndex++;
        left1++;
        if (left1 <= middle) {
            head1Tmp = head1Tmp->next;
        }
    }
    while (left2 <= right) {
        tmp[tmpIndex] = head2Tmp->val;
        tmpIndex++;
        left2++;
        if (left2 <= right) {
            head2Tmp = head2Tmp->next;
        }
    }

    for (i = left; i <= right; i++) {
        //printf("i: %u: i - left: %u, tmp[left]: %u\n", i, i - left, tmp[i - left]);
        head1TmpCpy->val = tmp[i];
        head1TmpCpy = head1TmpCpy->next;
    }

    //printf("end\n");
}

void MergeSort(ListNode* head, int left, int right, int *tmp)
{
    int middle;
    if (left >= right) {
        return;
    }
    middle = left + (right - left) / 2;
    //printf("left: %u, middle: %u\n", left, middle);
    MergeSort(head, left, middle, tmp);
    //printf("middle + 1: %u, right: %u\n", middle + 1, right);
    MergeSort(head, middle + 1, right, tmp);
    MergeList(head, left, middle, right, tmp);
}

struct ListNode* sortList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    int left = 0;
    int right = 0;
    int *tmp;
    ListNode *headCpy = head;

    while (headCpy != NULL) {
        headCpy = headCpy->next;
        right++;
    }
    tmp = (int *)malloc(right * sizeof(int));
    memset(tmp, 0, right * sizeof(int));
    //printf("left: %u, right - 1: %u\n", left, right - 1);
    MergeSort(head, left, right - 1, tmp);
    
    free(tmp);
    return head;
}
```
