```
function isReflected($points) {
    $max = PHP_INT_MIN;
    $min = PHP_INT_MAX;
    $map = [];
    foreach($points as $point){
        $max = max($max,$point[0]);
        $min = min($min,$point[0]);
        $map[$point[0]][$point[1]] = 1;
    }
    $mid = $max + $min; // 镜像线是$mid/2
    foreach($points as $point){
        $x = $point[0];
        $y = $point[1];
        $mirror_x = $mid - $x;
        if(!isset($map[$mirror_x][$y])) return false;
    }
    return true;
}
```
