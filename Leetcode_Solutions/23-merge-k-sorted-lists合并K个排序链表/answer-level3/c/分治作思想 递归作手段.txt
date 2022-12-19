思路：分治是思想，递归是手段
由于待合并的链表本身已经是排好序的，显然这题可以采用分治的思想：
1）我们将待排序链表按照数量均分为两个子集，将每个子集按规则进行合并
2）然后将两个子集合并后得到的两个单一链表再进行一次合并即可
3）对于每个待合并的子集，如果链表数目小于等于1可以直接返回；数目为2则可进行两个链表的排序合并，并不复杂
4) 如果子集数目大于2，则可以进一步分治，再次划分成两个子集，递归下去，知道数目小于等于2可以直接处理
```
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int mindex;
    struct ListNode* tmp[2];
    struct ListNode* head;
    struct ListNode* point;
    head = point = NULL;
    if (listsSize == 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];
    if (listsSize == 2) {
        while(lists[0] && lists[1]) {
            if (lists[0]->val < lists[1]->val) {
                if (head) {
                    point->next = lists[0];
                    point = point->next;
                } else {
                    point = head = lists[0];
                }
                lists[0] = lists[0]->next;
            } else {
                if (head) {
                    point->next = lists[1];
                    point = point->next;
                } else {
                    point = head = lists[1];
                }
                lists[1] = lists[1]->next;
            }
        }
        if (lists[0]) {
            if (head)
                point->next = lists[0];
            else
                point = head = lists[0];
        } else if (lists[1]) {
            if (head)
                point->next = lists[1];
            else
                point = head = lists[1];
        }
        return head;
    }
    mindex = listsSize / 2;
    tmp[0] = mergeKLists(lists, mindex);
    tmp[1] = mergeKLists(lists + mindex, listsSize - mindex);
    return mergeKLists(tmp, 2);
}
```
