```
function removeNthFromEnd($head, $n) {
    $dummy = new ListNode(0);
    $dummy->next = $head;
    $ptr1 = $dummy;
    $ptr2 = $dummy;
    for($i=0;$i<$n+1;$i++){
        $ptr1 = $ptr1->next;
    }
    while($ptr1!=null){
        $ptr1 = $ptr1->next;
        $ptr2 = $ptr2->next;
    }
    $ptr2->next = $ptr2->next->next;
    return $dummy->next;
}
```
