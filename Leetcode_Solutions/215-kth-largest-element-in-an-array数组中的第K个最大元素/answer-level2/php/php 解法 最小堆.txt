```
function findKthLargest($nums, $k) {
    $heap = new SplMinHeap();
    foreach($nums as $num){
        $heap->insert($num);
        if($heap->count() > $k) $heap->extract();
    }
    return $heap->top();
}
```
