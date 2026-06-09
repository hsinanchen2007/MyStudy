思路：创建一颗线段树，查询和更新操作都是log(n)的时间复杂度
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
     * @param Integer $val
     * @return NULL
     */
    function update($i, $val) {
        if(!$this->tree){
            throw new Exception('empty tree');
        }
        $this->tree->set($i,$val);
    }
  
    /**
     * @param Integer $i
     * @param Integer $j
     * @return Integer
     */
    function sumRange($i, $j) {
        if(!$this->tree){
            throw new Exception('empty tree');
        }
        return $this->tree->query($i,$j);
    }
}

/**
 * 线段树
 * Class SegmentTress
 * @package app\common\core
 */
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

    public function set($i, $val)
    {
        if ($i < 0 || $i >= $this->size()) {
            throw new Exception("下标越界");
        }

        $this->data[$i] = $val;
        $this->_set(0, 0, $this->size() - 1, $i, $val);
    }

    protected function _set($tree_index, $l, $r, $i, $val)
    {
        if ($l == $r) {
            $this->tree[$tree_index] = $val;
            return;
        }

        $mid = $l + floor(($r - $l) / 2);
        $lc = $this->leftChild($tree_index);
        $rc = $this->rightChild($tree_index);
        if ($i >= $mid + 1)
            $this->_set($rc, $mid + 1, $r, $i, $val);
        else
            $this->_set($lc, $l, $mid, $i, $val);

        $this->tree[$tree_index] = $this->merge->merge($this->tree[$lc], $this->tree[$rc]);
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
 * $obj->update($i, $val);
 * $ret_2 = $obj->sumRange($i, $j);
 */
```
