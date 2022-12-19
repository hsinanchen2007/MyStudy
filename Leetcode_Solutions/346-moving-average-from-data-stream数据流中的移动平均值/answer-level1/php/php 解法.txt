```
class MovingAverage {
    function __construct($size) {
        $this->size = $size;
        $this->queue = [];
        $this->sum = 0;
    }

    function next($val) {
        $this->sum += $val;
        $this->queue[] = $val;
        if(count($this->queue) > $this->size){
            $this->sum -= array_shift($this->queue);
        }
        return $this->sum/count($this->queue);
    }
}
```
