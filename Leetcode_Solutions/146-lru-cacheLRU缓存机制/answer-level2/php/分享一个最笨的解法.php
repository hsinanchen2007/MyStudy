大家很多用来解决这个问题，我采用的是很基础的数组解法，数组中设置顺序和实际值，然后每次存入时进行判断和排序。

代码如下

class LRUCache {
    
    private $size = 0;
    private $data = [];

    
    /**
     * @param Integer $capacity
     */
    function __construct($capacity) {
        $this->size = $capacity;
        $this->data = [];
    }
  
    /**
     * @param Integer $key
     * @return Integer
     */
    function get($key) {

        if(array_key_exists($key,$this->data))
        {
            $this->sortKey($this->data,$key);
            return $this->data[$key]['val'];
        }else{
            return -1;
        }

    }
  
    /**
     * @param Integer $key
     * @param Integer $value
     * @return NULL
     */
    function put($key, $value) {
        $key = $key;
        $length  = count($this->data);
    
        if(array_key_exists($key,$this->data)){
            $this->data[$key]['val']=$value;
            $this->sortKey($this->data,$key);

        }else if($length==$this->size)
        {
            $target = "";
            $this->sortAdd($this->data);
            foreach($this->data as $k => $v){
                if($v['sort']==$this->size+1){
                    $target = $k;
                }
            }
            unset($this->data[$target]);
            $this->data[$key]['val']=$value;
            $this->data[$key]['sort']=1; 
        }else{
            $this->sortAdd($this->data);
            $this->data[$key]['val']=$value;
            $this->data[$key]['sort']=1;
        }
    }
    
    function sortAdd(&$array){
        if(empty($array)){
            return;
        }
        foreach($array as &$val)
        {
            $val['sort']++;
        }
    }
    
    function sortKey(&$array,$key){
        $old_sort =$array[$key]['sort'];
            foreach($array as $k =>&$v){
                if($v['sort']>$old_sort){
                    continue;
                }
                if($k != $key){
                    $v['sort']++; 
                }else{
                    $v['sort'] = 1;
                }
            }
    
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * $obj = LRUCache($capacity);
 * $ret_1 = $obj->get($key);
 * $obj->put($key, $value);
 */