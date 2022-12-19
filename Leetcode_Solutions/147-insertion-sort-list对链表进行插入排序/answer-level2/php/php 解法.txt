```
function insertionSortList($head) {
    $dummy = new ListNode(0);
    $dummy->next = $head;
    while($head != null && $head->next != null){
        if($head->val <= $head->next->val){
            $head = $head->next;
            continue;
        }
        $pre = $dummy;
        while($pre->next->val < $head->next->val) $pre = $pre->next;
        $curr = $head->next;
        $head->next = $curr->next;
        $curr->next = $pre->next;
        $pre->next = $curr;
    }
    return $dummy->next;
}
```
