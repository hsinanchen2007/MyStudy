- 非递归方法
思路：这个思路和大家都差不多，建立2个链表，一个链表存储小x的所有元素，另一个存储大于等于x的元素。对原链表进行一遍循环，就可以将2个链表构建完。复杂度应该是O（n）。遍历结束后，将小于x的链表尾，指向大于等于x的链表的头，然后返回小于x的链表头，就是最后的答案。为了维持原来的位置，需要在链表尾添加元素，所以2个链表都设置了尾指针，方便添加元素。
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
     * @param Integer $x
     * @return ListNode
     */
    function partition($head, $x) {
        $cur=$head;
        $newHead1=null; //小于x元素链表的头指针
        $newHead2=null; //大于等于x元素链表的头指针
        $lpos=null; //小于x元素链表的尾指针
        $rpos=null; //大于等于x元素链表的尾指针
        //对原链表进行一遍遍历
        while($cur!=null){
            if($cur->val<$x){
                if($lpos==null){
                    $lpos=new ListNode($cur->val);
                    $newHead1=$lpos;                    
                }else{
                    $lpos->next= new ListNode($cur->val);
                    $lpos=$lpos->next;
                }                
            }else{
                if($rpos==null){
                    $rpos=new ListNode($cur->val); 
                    $newHead2=$rpos;            
                }else{
                    $rpos->next= new ListNode($cur->val);
                    $rpos=$rpos->next;
                }
            }
            $cur=$cur->next;
        }

        //判断一下，第一个链表是否为空
        if($newHead1==null){
            return $newHead2;
        }else{
            $lpos->next=$newHead2;
            return $newHead1;
        }
    }
}
```
