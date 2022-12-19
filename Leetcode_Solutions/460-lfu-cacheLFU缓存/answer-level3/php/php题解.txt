
![image.png](https://pic.leetcode-cn.com/6076c1a5f3d6c153980134ffb9a4d40c7ed4304fafa517e9b07eea483ff52ce3-image.png)

代码比较烂


```

class LFUCache {
    //记录一共插入了多少个key
    public $key_num_size = 0;
    //一个二维数组 存储 访问频次<=>key 例如 numkey[0] = [1=>1,2=>2] 意思是访问0次的有键1 和2 并且2是后插入的
    public $num_key = [];
    //一纬数组 存储 key<=>访问频次 
    public $key_num = [];
    //一纬数组 存储key<=>value
    public $key_val = [];
    //最小的访问频次是几，比如全程只插入 那最小的频次就都是0
    public $last = 0;
    //记录容量
    public $cap = 0;

    function __construct($capacity) {
        $this->cap = $capacity;
    }

    function get($key) {
        if($this->cap<=0){
            return -1;
        }
        //查到
        if(isset($this->key_num[$key])){
            $xuhao = $this->key_num[$key];//获取这个key访问了几次
            $this->key_num[$key]=$xuhao+1;//更新这个key的访问次数
            $value = $this->key_val[$key];//获取这个key对应的值
            unset($this->num_key[$xuhao][$key]);//从原来的频次数组里删这个key
            $this->num_key[$xuhao+1][$key]=$key;//从尾巴追加到新的频次数组
            if($xuhao == $this->last){//如果这个key原来的频次是最小频次
                if(count($this->num_key[$xuhao]) <=0){//如果这个key从最小频次数组删掉后，数组空了
                    $this->last = $xuhao+1;//更新最小频次
                }
            }
            return $value;
        }else{//没查到
            return -1;
        }
    }

    /**
     * @param Integer $key
     * @param Integer $value
     * @return NULL
     */
    function put($key, $value) {
        if($this->cap<=0){
            return ;
        }
        if(isset($this->key_num[$key])){//如果插入的值已经有了
            $xuhao = $this->key_num[$key];//获取这个key访问了几次
            $this->key_num[$key]=$xuhao+1;//更新这个key的访问次数
            $this->key_val[$key] = $value;//值更新
            unset($this->num_key[$xuhao][$key]);//原频次中删除
            $this->num_key[$xuhao+1][$key]=$key;//新频次中尾巴追加
            //更新最小频次
            if($xuhao == $this->last){
                if(count($this->num_key[$xuhao]) <=0){
                    $this->last = $xuhao+1;
                }
            }

        }else{//这是个新的key
            if($this->key_num_size == $this->cap){//当前容量已满
                $xkey = key($this->num_key[$this->last]);//头部是当前频次中最旧的key，这里不能用array_shift 因为会重置键编程从0开始
                unset($this->num_key[$this->last][$xkey]);//频次中请空
                unset($this->key_val[$xkey]);//清空
                unset($this->key_num[$xkey]);//清空
                $this->key_num_size--;//当前已存储个数更新
            }
            $this->last = 0;//到这里是铁定新插入一个新的key了，最小频次给0
            if(!isset($this->num_key[0])){//可有可无
                $this->num_key[0] = [];
            }
            $this->key_num[$key] = 0;//这个key的访问频次是0，因为头一次插入
            $this->num_key[0][$key]=$key;
            $this->key_val[$key] = $value;
            $this->key_num_size++;
        }

    }

}

```
