```
function climbStairs($n) {
        static $cache = [1=>1,2=>2];
        if($n === 1 ) return 1;
        if($n === 2 ) return 2;

        if(!isset($cache[$n-1])) {
            $cache[$n-1] = $this->climbStairs($n-1);
        }
        if(!isset($cache[$n-2])) {
            $cache[$n-2] = $this->climbStairs($n-2);
        }
        $cache[$n] = $cache[$n-1] + $cache[$n-2];
        return $cache[$n];
}
```
