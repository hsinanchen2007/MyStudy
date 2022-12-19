```
function swapPairs($head) {
    if($head==null || $head->next==null){
        return $head;
    }
    $next = $head->next;
    $head->next = $this->swapPairs($next->next);
    $next->next = $head;
    return $next;
}
```
