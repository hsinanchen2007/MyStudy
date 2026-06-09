```
function topKFrequent($nums, $k) {
    $count = array_count_values($nums);
    $pq = new SplPriorityQueue;
    foreach($count as $key=>$val) $pq->insert($key,$val);
    $ans = [];
    for($i=0;$i<$k;$i++) $ans[] = $pq->extract();
    return $ans;
}
```
