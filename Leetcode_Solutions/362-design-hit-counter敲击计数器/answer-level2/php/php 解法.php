```
class HitCounter {

    function __construct() {
        $this->queue = [];
    }

    function hit($timestamp) {
        $this->queue[] = $timestamp;
    }

    function getHits($timestamp) {
        while(!empty($this->queue) && $timestamp - $this->queue[0]>=300){
            array_shift($this->queue);
        }
        return count($this->queue);
    }
}
```
