思路:刚开始没看懂题,前一个数组是代码执行循序,后面是传入的值,max_value取数组最大,push_back向数组添加值,pop_front弹出数组第一个值
```
class MaxQueue
{
   
    /**
     */
    function __construct()
    {
        $this->Queue = [];
    }

    /**
     * @return Integer
     */
    function max_value()
    {
        if (empty($this->Queue)) {
            return -1;
        }
         return  max($this->Queue);
      
    }

    /**
     * @param Integer $value
     * @return NULL
     */
    function push_back($value)
    {
        array_push($this->Queue,$value);
        return NULL;
    }

    /**
     * @return Integer
     */
    function pop_front()
    {
        if (empty($this->Queue)) {
            return -1;
        }

        $result=array_shift($this->Queue);
        return $result;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * $obj = MaxQueue();
 * $ret_1 = $obj->max_value();
 * $obj->push_back($value);
 * $ret_3 = $obj->pop_front();
 */
```
