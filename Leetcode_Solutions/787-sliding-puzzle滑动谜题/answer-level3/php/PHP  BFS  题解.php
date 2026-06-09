```

function slidingPuzzle($board)
    {
        $moves = [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]];
        $target = "123450";
        $start  = '';
        foreach ($board as $b) {
            foreach ($b as $v) {
                $start .= $v;
            }
        }
        $visited[] = $start;
        $queue = new SplQueue();
        $queue->enqueue($start);
        $res = 0;
        while (!$queue->isEmpty()) {
            $size = $queue->count();
            for ($i = 0; $i < $size; $i++) {
                $curr = $queue->dequeue();
                if ($curr == $target)  return $res;
                $zero = strpos($curr, '0');
                foreach ($moves[$zero] as $move) {
                    $newArr = $curr;
                    $temp = $newArr[$move];
                    $newArr[$move] = $newArr[$zero];
                    $newArr[$zero] = $temp;
                    if (!in_array($newArr, $visited)) {
                        $visited[] = $newArr;
                        $queue->enqueue($newArr);
                    }
                }
            }
            $res += 1;
        }
        return -1;
    }
```