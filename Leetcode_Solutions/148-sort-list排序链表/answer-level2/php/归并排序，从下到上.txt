### 解题思路
此处撰写解题思路

### 代码

```php
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
     * @param ListNode $head
     * @return ListNode
     */
     //归并排序
    public function sortList($node){
        $dummyHead = new ListNode ();
        $dummyHead->next = $node;
        $cur = $node;
        $left = null;
        $right = null;
        $len = 0;
        //求链表长度
        while($cur) {
            ++$len;
            $cur = $cur->next;
        }
        for($size = 1; $size < $len; $size=$size * 2) {
            $cur = $dummyHead->next;
            $tail = $dummyHead;
            while($cur) {
                $left = $cur;
                $right = $this->split($left, $size);
                //*******左边有，右边没有，直接将左边链表在链表尾部*****
                if($right==null){
                    $tail->next=$left;
                    break;
                }
                $cur = $this->split($right, $size);
                //print_r($left);
               // print_r($right);
                $tail->next = $this->mergeSingleLinkedList($left, $right);
                //print_r($tail->next);
                while($tail->next) {
                    $tail = $tail->next;
                }
            }
        }
        return $dummyHead->next;
    }

    /**
     * 分割链表，拿到右边
     * @param $head
     * @param $n
     * @return null
     */
    public function  split($head,$n){
        $cur = $head;
        $right=null;

        while (--$n && $cur) {
            $cur = $cur->next;
        }
        if(!$cur) return null;
        $right = $cur->next;
        $cur->next = null;
        return $right;
    }
     public function mergeSingleLinkedList($node1,$node2){
        if($node1==NULL || $node2==NUll ){
            return '';
        }

        $newNode=new ListNode();//链表不断向后移动
        $head=$newNode;//保持头的位置，需要不断向后移循环的时候，需要赋值

        while($node1!==NULL && $node2!==NUll ){
            if($node1->val<$node2->val){
                $newNode->next=$node1;
                $node1=$node1->next;

            }else{
                $newNode->next=$node2;
                $node2=$node2->next;
            }
            $newNode=$newNode->next;
        }

        //链表长度不一样
        if($node1!=null){
            $newNode->next=$node1;
        }
        if($node2!=null){
            $newNode->next=$node2;
        }

        return $head->next;//返回新链表的头节点, ->next 不带头节点
    }
}
```