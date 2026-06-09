```
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (lists == NULL || listsSize <= 0) {
       return NULL; 
    }
    if (listsSize == 1) {
        return lists[0];
    }
    
    return mergeTwoLists(lists[0],mergeKLists(&lists[1], listsSize - 1));
}

```

其中合并两个序列的参考 https://leetcode-cn.com/problems/merge-two-sorted-lists/
