```
class MedianFinder {
    /**
     * initialize your data structure here.
     */
    function __construct() {
        $this->count = 0;
        $this->minHeap = new SplMinHeap;
        $this->maxHeap = new SplMaxHeap;
    }

    private $count;
    private $minHeap;
    private $maxHeap;

    /**
     * @param Integer $num
     * @return NULL
     */
    function addNum($num) {
        $this->count += 1;
        
        $this->maxHeap->insert($num);
        $this->minHeap->insert($this->maxHeap->extract());
        if (($this->count & 1) != 0) {
            $this->maxHeap->insert($this->minHeap->extract());
        }    
    }
  
    /**
     * @return Float
     */
    function findMedian() {
        if (($this->count & 1) == 0) {
            return (double) ($this->maxHeap->top() + $this->minHeap->top()) / 2;
        } else {
            return (double) $this->maxHeap->top();
        }
    }
}
```
