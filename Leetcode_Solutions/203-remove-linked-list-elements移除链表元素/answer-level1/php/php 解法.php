```
function removeElements($head, $val) {
    $dummy = new ListNode(-1);
    $dummy->next = $head;
    $p = $dummy;
    while($p->next != null){
        if($p->next->val == $val){
            $p->next = $p->next->next;
        }else{
            $p = $p->next;
        }
    }
    return $dummy->next;
}
```
