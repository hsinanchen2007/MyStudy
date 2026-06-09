### 解题思路
思路一：用数组保存前K个最大，然后排序。时间负责度为 N*K*logK。
思路二：采用最小堆，minHeap

### 代码

```php
class KthLargest {

    public $k;
    public $heap;
    /**
     * @param Integer $k
     * @param Integer[] $nums
     */
    function __construct($k, $nums) {
        $this->k = $k;
        $this->heap = new SplMinHeap();
        foreach($nums as $n){
            $this->add($n);
        }
    }
  
    /**
     * @param Integer $val
     * @return Integer
     */
    function add($val) {
        if($this->heap->count() < $this->k){
            $this->heap->insert($val);
        } else if($this->heap->top() < $val) {
            $this->heap->insert($val);
            $this->heap->extract();
        }
        return $this->heap->top();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * $obj = KthLargest($k, $nums);
 * $ret_1 = $obj->add($val);
 */
```