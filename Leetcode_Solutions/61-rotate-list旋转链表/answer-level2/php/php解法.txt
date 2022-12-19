参考官方思路：先连成环，在旋转后断开
```
function rotateRight($head, $k) {
    if($head==null) return null;
    if($head->next == null) return $head;
    $tmp = $head;
    for($n=1;$tmp->next != null;$n++){
        $tmp = $tmp->next;
    }
    $tmp->next = $head;
    
    $tmp2 = $head;
    for($i=0;$i<$n-fmod($k,$n)-1;$i++){
        $tmp2 = $tmp2->next;
    }
    $new_node = $tmp2->next;
    $tmp2->next = null;
    return $new_node;
}
```
