```
function sortList($head) {
    if($head == null || $head->next == null) return $head;
    $fast = $head->next;
    $slow = $head;
    while($fast != null && $fast->next != null){
        $slow = $slow->next;
        $fast = $fast->next->next;
    }
    $tmp = $slow->next;
    $slow->next = null;
    $left = $this->sortList($head);
    $right = $this->sortList($tmp);
    $dummy = new ListNode(0);
    $h = $dummy;
    while($left != null && $right != null){
        if($left->val < $right->val){
            $h->next = $left;
            $left = $left->next;
        }else{
            $h->next = $right;
            $right = $right->next;
        }
        $h = $h->next;
    }
    $h->next = ($left != null)?$left:$right;
    return $dummy->next;
}
```
