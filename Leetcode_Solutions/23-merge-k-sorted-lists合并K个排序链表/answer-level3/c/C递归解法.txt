遍历所有头结点，找出最小的那个，把当前结点作为递归函数的返回值，当前结点的NEXT结点作为当前链表头。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeKListsSub(struct ListNode** lists, int listsSize){
    struct ListNode* temp = NULL;
    int val = INT_MAX;
    int pos = -1;
    int i;
    
    for(i = 0; i < listsSize;i++){
        if(lists[i]){
            if(val > lists[i]->val){
                val = lists[i]->val;
                pos = i;
            }
        }
    }
    
    if(pos != -1){
        temp = lists[pos];
        //printf("found min %d @ %d\n",lists[pos]->val,pos);
        lists[pos] = lists[pos]->next;
        temp->next = mergeKListsSub(lists,listsSize);
    }
    
    return temp;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    return mergeKListsSub(lists,listsSize);
}

```
