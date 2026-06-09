```
function kSmallestPairs($nums1, $nums2, $k) {
    $pq = new SplPriorityQueue();
    $n1 = count($nums1); // 可优化 min(count($nums1),$k);
    $n2 = count($nums2); // 可优化 min(count($nums2),$k);
    for($i=0;$i<$n1;$i++){
        for($j=0;$j<$n2;$j++){
            $pq->insert([$nums1[$i],$nums2[$j]],$nums1[$i]+$nums2[$j]);
            if($pq->count() > $k) $pq->extract();
        }
    }
    $ans = [];
    while($pq->valid()){
        $ans[] = $pq->current();
        $pq->next();
    }
    return $ans;
}
```
