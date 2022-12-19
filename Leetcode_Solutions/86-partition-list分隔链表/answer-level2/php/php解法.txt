```
function partition($head, $x) {
    $before_head = new ListNode(-1);
    $before = $before_head;
    $after_head = new ListNode(-1);
    $after = $after_head;
    while($head != null){
        if($head->val < $x){
            $before->next = $head;
            $before = $before->next;
        }else{
            $after->next = $head;
            $after = $after->next;
        }
        $head = $head->next;
    }
    $after->next = null;
    $before->next = $after_head->next;
    return $before_head->next;
}
```
