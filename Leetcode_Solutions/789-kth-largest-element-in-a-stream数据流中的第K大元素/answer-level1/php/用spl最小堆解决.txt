``` php
/*
 * @lc app=leetcode.cn id=703 lang=php
 *
 * [703] 数据流中的第K大元素
 */

// @lc code=start
class KthLargest {
    /**
     * @param Integer $k
     * @param Integer[] $nums
     */
    function __construct($k, $nums) {
        $this->heap = new SplminHeap();
        $this->k = $k;
        foreach($nums as $num){
            $this->heap->insert($num);
        }
        
    }
  
    /**
     * @param Integer $val
     * @return Integer
     */
    function add($val) {
        $this->heap->insert($val);
        foreach($this->heap as $key=>$value){
            if($key==$this->k-1){
                return $value;
            }
        }
        
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * $obj = KthLargest($k, $nums);
 * $ret_1 = $obj->add($val);
 */
// @lc code=end
```
