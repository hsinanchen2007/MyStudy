/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val) { $this->val = $val; }
 * }
 */
class Solution
{

    /**
     * @param array ListNode $l1
     * @param array ListNode $l2
     * @return array ListNode
     */
    function addTwoNumbers($l1, $l2)
    {
        $l1 = ReverseFactory::getEntityFactory()->toReverse($l1);
        $l2 = ReverseFactory::getEntityFactory()->toReverse($l2);
        return ReverseFactory::getEntityFactory()->toSum();
    }
}

class Reverse
{
    /**
     * Reverse constructor.
     * @param $arr
     */

    private $arr;
    static private $instance;

    static public function getInstance()
    {
        //判断$instance是否是Uni的对象
        //没有则创建
        if (!self::$instance instanceof self) {
            self::$instance = new self();
        }
        return self::$instance;
    }

    /**
     * @return mixed
     */
    public function getArr()
    {
        return $this->arr;
    }

    /**
     * @param mixed $arr
     */
    public function setArr($arr): void
    {
        $this->arr[] = $arr;
    }

    public function toReverse($arr): void
    {
        $arr = array_reverse($arr);
        $arr = implode("", $arr);
        $this->setArr($arr);
    }

    public function toSum()
    {
        $sum = 0;
        foreach ($this->getArr() as $value) {
            $sum += (int)$value;
        }
        $sum = (string)$sum;

        $re = [];
        for ($i = 0; $i < strlen($sum); $i++) {
            $re[] = $sum[$i];
        }

        return array_reverse($re);
    }
}

class ReverseFactory
{
    public static function getEntityFactory()
    {
        return Reverse::getInstance();
    }
}