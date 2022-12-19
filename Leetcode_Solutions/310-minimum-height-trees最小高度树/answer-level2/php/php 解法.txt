```
function findMinHeightTrees($n, $edges) {
    if(count($edges)==0) return [0];
    $inDegree = array_fill(0,$n,0);
    $adj = [];
    foreach($edges as $edge){
        $adj[$edge[0]][] = $edge[1];
        $adj[$edge[1]][] = $edge[0];
        $inDegree[$edge[0]]++;
        $inDegree[$edge[1]]++;
    }
    $queue = [];
    for($i=0;$i<$n;$i++){
        if($inDegree[$i] == 1) $queue[] = $i;
    }
    while($n>2){
        $qlen = count($queue);
        $n -= $qlen;
        for($i=0;$i<$qlen;$i++){
            $top = array_shift($queue);
            $inDegree[$top]--;
            foreach($adj[$top] as $nb){
                $inDegree[$nb]--;
                if($inDegree[$nb] == 1)$queue[] = $nb;
            }
        }
    }
    return $queue;
}
```
