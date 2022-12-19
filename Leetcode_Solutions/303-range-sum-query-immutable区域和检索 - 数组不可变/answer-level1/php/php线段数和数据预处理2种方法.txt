思路1：利用线段树，求区间值。
代码:
```php
class NumArray {
    private $tree;
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        if(sizeof($nums)>0){
            $this->tree=new SegmentTress($nums,new SumMerge());        
        }
    }
  
    /**
     * @param Integer $i
     * @param Integer $j
     * @return Integer
     */
    function sumRange($i, $j) {
        if(!$this->tree){
            throw new Exception('tree is empty');
        }

        return $this->tree->query($i,$j);
    }
}

class SegmentTress
{
    private $data;
    private $tree;
    private $merge;

    public function __construct($arr, $merge)
    {
        foreach ($arr as $item) {
            $this->data[] = $item;
        }

        $this->merge = $merge;

        $this->buildTree(0, 0, sizeof($this->data) - 1);
    }

    protected function buildTree($i, $l, $r)
    {
        if ($l == $r) {
            $this->tree[$i] = $this->data[$l];
            return;
        }

        $mid = $l + floor(($r - $l) / 2);
        $li = $this->leftChild($i);
        $ri = $this->rightChild($i);
        $this->buildTree($li, $l, $mid);
        $this->buildTree($ri, $mid + 1, $r);

        $this->tree[$i] = $this->merge->merge($this->tree[$li], $this->tree[$ri]);
    }

    public function size()
    {
        return sizeof($this->data);
    }

    public function get($index)
    {
        return $this->data[$index];
    }

    public function leftChild($i)
    {
        return 2 * $i + 1;
    }

    public function rightChild($i)
    {
        return 2 * $i + 2;
    }

    public function query($ql, $qr)
    {
        if ($ql < 0 || $qr >= $this->size() || $ql > $qr) {
            throw new Exception("索引不合法");
        }

        return $this->_query(0, 0, $this->size() - 1, $ql, $qr);
    }

    protected function _query($i, $l, $r, $ql, $qr)
    {
        if ($l == $ql && $r == $qr) {
            return $this->tree[$i];
        }

        $mid = $l + floor(($r - $l) / 2);
        $lc = $this->leftChild($i);
        $rc = $this->rightChild($i);

        if ($ql >= $mid + 1)
            return $this->_query($rc, $mid + 1, $r, $ql, $qr);
        else if ($qr <= $mid)
            return $this->_query($lc, $l, $mid, $ql, $qr);

        $lResult = $this->_query($lc, $l, $mid, $ql, $mid);
        $rResult = $this->_query($rc, $mid + 1, $r, $mid + 1, $qr);

        return $this->merge->merge($lResult, $rResult);
    }

    public function __toString()
    {
        // TODO: Implement __toString() method.
        $ret = "[";

        $len = sizeof($this->data) * 4;
        for ($i = 0; $i < $len; $i++) {
            if (isset($this->tree[$i]))
                $ret .= $this->tree[$i];
            else
                $ret .= "null";

            if ($i != $len - 1) {
                $ret .= ", ";
            }
        }
        $ret .= "]<br>";

        return $ret;
    }
}

class SumMerge
{

    public function merge($a, $b)
    {
        // TODO: Implement merge() method.
        return $a + $b;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * $obj = NumArray($nums);
 * $ret_1 = $obj->sumRange($i, $j);
 */
```
思路2：对数据进行预处理，设置一个sum数组，数组里sum[$i]表示0，1。。i-1的和。
代码:
```php
class NumArray {
    private $sum;
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->sum[0]=0;
        for($i=1;$i<=sizeof($nums);$i++){
            $this->sum[$i]=$this->sum[$i-1]+$nums[$i-1];
        }
    }
  
    /**
     * @param Integer $i
     * @param Integer $j
     * @return Integer
     */
    function sumRange($i, $j) {
        return $this->sum[$j+1]-$this->sum[$i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * $obj = NumArray($nums);
 * $ret_1 = $obj->sumRange($i, $j);
 */
```

