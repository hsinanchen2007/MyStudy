```php
class RecentCounter {
    /**
     */
    function __construct() {
        $this->queue = [];
    }
  
    /**
     * @param Integer $t
     * @return Integer
     */
    function ping($t) {
        $this->queue[] = $t;
        foreach ($this->queue as $key => $value) {
            if ($t - $value > 3000) {
                unset($this->queue[$key]);
            } else {
                break;
            }
        }
        return count($this->queue);
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * $obj = RecentCounter();
 * $ret_1 = $obj->ping($t);
 */
```