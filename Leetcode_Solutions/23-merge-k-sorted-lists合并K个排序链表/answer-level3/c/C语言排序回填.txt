### 解题思路
先把链表串起来，把数值放到数组中，排序后返填回去。注意中间会有空值

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int compare(int* a, int*b){
    return *a-*b;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* head;
    int *num;
    int count = 0;
    int i = 0;
    int first = 0;
    if(listsSize == 0 || lists == NULL){
        return NULL;
    }
    if(listsSize == 1){
        return lists[0];
    }
    for(i = 0; i < listsSize; i++){
        if(lists[i] != NULL){
            head = lists[i];
            first = i;
            break;
        }
        if(i == listsSize -1){
            return NULL;
        }
    }
   // printf("first %d \r\n",first);

    for (i = first; i < listsSize; i++){     
        while(head->next != NULL){
            head = head->next;
            count++;
        }
        if(i < listsSize-1){
            head->next = lists[i+1];
        }
        count++;
    }
    num = (int*)malloc(sizeof(int)*count);
    memset(num, 0, sizeof(int)*count);
    
    head = lists[first];
    count = 0;
    while(head){
        num[count] = head->val;
        count++;
        head = head->next;
        //printf("num %d\r\n",num[count]);
    }
    qsort(num, count, sizeof(int), compare); 

    head = lists[first];
    count = 0;
    while(head){
        head->val = num[count];
        count++;
        head = head->next;
    }
    return lists[first];
}
```