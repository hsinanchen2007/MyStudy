![aaa.png](https://pic.leetcode-cn.com/1b21bb009b524b011961ab038ac13871499be4c29f1564d287cf6c029fa0d468-aaa.png)

直观方法，比较简单。速度一般般，内存有点大。PHP语言数组问题还是比较费的。大家可以优化一下。
```
class SnapshotArray {
    var $snap=[];
    var $arr=[];
    function __construct($length) {    
    }

    function set($index, $val) {
        $this->arr[$index]=$val;
    }

    function snap() {
        array_push($this->snap,$this->arr);
        return count($this->snap)-1;
    }
  
    function get($index, $snap_id) {
        $res = isset($this->snap[$snap_id][$index])?$this->snap[$snap_id][$index]:0;
        return $res;
    }
}
```
