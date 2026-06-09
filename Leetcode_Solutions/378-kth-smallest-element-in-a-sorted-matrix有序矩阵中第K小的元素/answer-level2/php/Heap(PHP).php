    function kthSmallest($matrix, $k) {
        return $this->maxheap($matrix, $k);
    }

    function maxheap($matrix, $k) {
        $m = count($matrix);
        $n = count($matrix[0]);

        $maxHeap = new SplMaxHeap();
        for ($i = 0; $i < $m; ++$i) {
            for ($j = 0; $j < $n; ++$j) {
                if ($maxHeap->count() < $k) {
                    $maxHeap->insert($matrix[$i][$j]);
                } else if ($matrix[$i][$j] < $maxHeap->top()) {
                    $maxHeap->extract();
                    $maxHeap->insert($matrix[$i][$j]);
                }
            }
        }
        return $maxHeap->top();
    }