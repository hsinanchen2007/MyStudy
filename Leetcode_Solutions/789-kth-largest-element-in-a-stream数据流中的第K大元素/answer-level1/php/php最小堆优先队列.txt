思路:一直维持含有k个元素的最小堆。
```php
class KthLargest {
    /**
     * @param Integer $k
     * @param Integer[] $nums
     */
    private $heap;
    private $arr;
    private $k;
    function __construct($k, $nums) {
        $this->arr=$nums;
        $this->k=$k;
        $this->heap=new SplMinHeap();

        //创建一个含有k个元素的最小堆
        foreach($nums as $key=>$val){
            if($this->heap->count()<$k){
                $this->heap->insert($val);
            }else if($val>$this->heap->top()){
                $this->heap->extract();
                $this->heap->insert($val);
            }
        }
    }
  
    /**
     * @param Integer $val
     * @return Integer
     */
    function add($val) {
        $this->arr[]=$val;
        //维持k个元素的最小堆
        if($this->heap->count()<$this->k){
            $this->heap->insert($val);
        }else if($val>$this->heap->top()){
            $this->heap->extract();
            $this->heap->insert($val);
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
