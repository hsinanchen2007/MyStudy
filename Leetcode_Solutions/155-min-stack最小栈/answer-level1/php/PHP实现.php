### 结果

执行用时: 36 ms, 在所有 PHP 提交中击败了 74.58% 的用户
内存消耗: 22.1 MB, 在所有 PHP 提交中击败了 76.92% 的用户

### 代码
```
class MinStack {

    public $min=null;

    public $stack=[];

    /**
     * initialize your data structure here.
     */
    function __construct() {
        
    }
  
    /**
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        if($this->min===null || $x < $this->min){
            $this->min = $x;
        }

        $this->stack[] = $x;
    }
  
    /**
     * @return NULL
     */
    function pop() {
        if(count($this->stack) == 0){
            return null;
        }

        $popNum = array_pop($this->stack);

        if($popNum == $this->min){
            //重新拿最小的值
            $min = null;
            foreach($this->stack as $num){
                if($min===null || $num < $min){
                    $min = $num;
                }
            }

            $this->min = $min;
        }

        return $popNum;
    }
  
    /**
     * @return Integer
     */
    function top() {
        return $this->stack[count($this->stack) - 1];
    }
  
    /**
     * @return Integer
     */
    function getMin() {
        return $this->min;
    }
}
```
