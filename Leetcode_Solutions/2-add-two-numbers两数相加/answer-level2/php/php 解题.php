结果:

![WX20190617-135447@2x.png](https://pic.leetcode-cn.com/e27f73bbd54dcee01671d948f25fa302be1f963193fc49469dc06450cd6df5b2-WX20190617-135447@2x.png)

代码:
```
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val) { $this->val = $val; }
 * }
 */
class Solution {

    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
        $listNode1 = $this->getNodeArr($l1);
        $listNode2 = $this->getNodeArr($l2);
        $node1 = implode('', $listNode1);
        $node2 = implode('', $listNode2);
        
        $count = $this->bigDataAdd(strrev($node1), strrev($node2));
        
        $arr = str_split(strrev($count));
        
        $listNode = new ListNode(array_shift($arr));
        
        for ($i = 0; $i < count($arr); $i++) {
            $this->addNode($listNode, $arr[$i]);
        }
        
        return $listNode;
    }
    
    function getNodeArr($listNode) {
        $arr = [];
        $tmp = $listNode;
        
        do {
            $arr[] = $tmp->val;
            
            if ($tmp->next === null) {
                $tmp = false;
                break;
            }
            
            $tmp = $tmp->next;
        } while ($tmp);
        
        return $arr;
    }
    
    function addNode($node, $value) {
      $lastNode = $this->findLastNode($node);
      $nextNode = new ListNode($value);
      $lastNode->next = $nextNode;
    }
    
    function findLastNode($node){
      if (empty($node->next)) {
        return $node;
      } else {
        return $this->findLastNode($node->next);
      }
    }
    
    function bigDataAdd($a,$b) {
        $m = strlen($a);
        $n = strlen($b);
        $num = $m>$n?$m:$n;//取最长数进行循环相加和进位
        $result = '';//结果
        $flag = 0; //进位标志
        while($num--){
            $t1 = 0;//用来存储当前位加数
            $t2 = 0;//用来存储当前位被加数
            if($m>0){
                $t1 = $a[--$m];
            }
            if($n>0){
                $t2 = $b[--$n];
            }
            $t = $t1+$t2+$flag;//当前位加法运算考虑上一轮的进位标志
            $flag = intval($t/10);//本轮是否进位
            $result = ($t%10).$result;//向高位添加结果
        }
        //最高位加完发现还有进位标志，需要再向最高位+1
        if ($flag) {
            $result = $flag.$result;
        }
        return $result;
    }
}
```