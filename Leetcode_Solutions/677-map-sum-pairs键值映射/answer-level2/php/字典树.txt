
1.根节点不包含任何字符，其余节点都包含一个字符和一个值，没有即为0
2.每个节点的所有子节点包含的字符都不相同。
3.从根节点到某一节点，路径上经过的节点链接起来就是该节点对应的字符
4.将该字符下所有节点的值相加即为以该字符开头的所有字符的和
![1579155688530.jpg](https://pic.leetcode-cn.com/69b07e990557985d37a710b81d7bdf3dfc0161cd29cbcc9e1649d6bf5df67b8e-1579155688530.jpg)

class MapSum {

    protected $_result =[];
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->_result = new TireNode('/');
    }
  
    /**
     * @param String $key
     * @param Integer $val
     * @return NULL
     */
    function insert($key, $val) {
        $p = $this->_result;
        $strlen = strlen($key);
        for ($i = 0; $i < $strlen; $i++) {
            $key_str = $key[$i];
            $nodeVale = 0;
            if ($i + 1 == $strlen) {
                $nodeVale = $val;
            }
            if (isset($p->child[$key_str])) {
                if ($i + 1 == $strlen) {
                    $p->child[$key_str]->data = $nodeVale;
                }
            } else {
                $newNode = new TireNode($key_str, $nodeVale);
                $p->child[$key_str] = $newNode;
            }
            $p = $p->child[$key_str];
        }
        $p->is_end = true;
    }
  
    /**
     * @param String $prefix
     * @return Integer
     */
    function sum($prefix) {
        $result = 0;
        $p = $this->_result;
        $strlen = strlen($prefix);
        for ($i = 0; $i < $strlen; $i++) {
            $key_str = $prefix[$i];
            if (!empty($p->child[$key_str])) {
                $p = $p->child[$key_str];
            }else {
                break;
            }
        }
        //
        if ($i == $strlen) {
            $result = $this->sumNodeValue($p);
        }
        return $result;
    }
    private function sumNodeValue($p)
    {
        $result = $p->data;
        if ($p->child) {
            foreach ($p->child as $node) {
                $result += $this->sumNodeValue($node);
            }
        }
        return $result;
    }
}

/**
 * 前缀树节点
 */
class TireNode
{

    public $data;
    public $child = [];
    public $is_end = false;

    public function __construct($key, $value = 0)
    {
        $this->name = $key;
        $this->data = $value;
    }
}
/**
 * Your MapSum object will be instantiated and called as such:
 * $obj = MapSum();
 * $obj->insert($key, $val);
 * $ret_2 = $obj->sum($prefix);
 */