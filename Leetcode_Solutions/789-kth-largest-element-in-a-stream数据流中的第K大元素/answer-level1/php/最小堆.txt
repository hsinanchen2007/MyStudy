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
        $this->heap = new SplMinHeap();
        $this->k = $k;
        foreach ($nums as $key=>$num){
            
            if($key+1>$k){
                if(!$this->heap->isEmpty()){
                    $min = $this->heap->top();
                    if($num>$min){
                        $this->heap->extract();
                        $this->heap->insert($num);
                    }
                }
        
            }else{
                $this->heap->insert($num);
            }
        }
    }
  
    /**
     * @param Integer $val
     * @return Integer
     */
    function add($val) {
        if(!$this->heap->isEmpty() && $this->heap->count()==$this->k){
            if($val>$this->heap->top()){
                $this->heap->extract();
                $this->heap->insert($val);
            }
        }else{

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
// @lc code=end


```