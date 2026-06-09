```php
class Solution {

    /**
     * @param Integer $m
     * @param Integer $n
     * @param Integer $k
     * @return Integer
     */
    function movingCount($m, $n, $k) {
        //bfs
        if (!$k) return 1;
        $queue = [[0, 0]];
        $visited = [];
        $visited[0][0] = true;
        $dx = [0, 1];
        $dy = [1, 0];
        $ans = 1;
        while ($queue) {
            [$x, $y] = array_shift($queue);
            for ($i = 0; $i < 2; $i++) {
                $nx = $x + $dx[$i];
                $ny = $y + $dy[$i];
                if ($nx < 0 || $nx >= $m || $ny < 0 || $ny >= $n || 
                $visited[$nx][$ny] || $this->getSum($nx) + $this->getSum($ny) > $k) continue;
                $queue[] = [$nx, $ny];
                $visited[$nx][$ny] = true;
                $ans++;
            }
        }
        return $ans;
    }
    function getSum($x) {
        $sum = 0;
        for(; $x; $x = floor($x/ 10)) {
            $sum += $x % 10;
        }
        return $sum;
    }
}
```
