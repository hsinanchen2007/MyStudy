```
function oddEvenList($head) {
    if($head == null || $head->next == null) return $head;
    $p1 = $head;
    $p2 = $head->next;
    $o1 = $p1;
    $o2 = $p2;
    while($p1 != null && $p1->next->next != null){
        $p1->next = $p1->next->next;
        $p1 = $p2->next;
        $p2->next = $p2->next->next;
        $p2 = $p1->next;
    }
    $p1->next = $o2;
    $p2->next = null;
    return $o1;
}
```
