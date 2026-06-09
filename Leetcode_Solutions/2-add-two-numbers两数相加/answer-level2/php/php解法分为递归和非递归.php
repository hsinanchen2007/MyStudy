- 非递归方法
思路：代码有点长，但是逻辑非常清晰。主体就是3个循环，第一遍循环，条件是2个链表都没达到尾部时，循环结束后，2个链表有可能都达到了尾部，或者其中一个达到了尾部，对于没有达到尾部的链表接着进行循环。当3个循环都结束后，如果step=1，说明还有进位。
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
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
        $sum=0;
        $step=0;    //代表进位
        $dummyHead=new ListNode(0);
        $cur=$dummyHead;
        while($l1!=null&&$l2!=null){
            $sum=$l1->val+$l2->val+$step;
            if($sum>=10){
                $cur->next=new ListNode($sum%10); 
                $step=1;               
            }else{
                $cur->next=new ListNode($sum);
                $step=0;
            }
            $cur=$cur->next;
            $l1=$l1->next;
            $l2=$l2->next;
        }

        while($l1!=null){
            $sum=$l1->val+$step;
            if($sum>=10){
                $cur->next=new ListNode($sum%10); 
                $step=1;               
            }else{
                $l1->val=$sum;
                $cur->next=$l1;
                $step=0;
                break;  //已经没有进位，提前结束循环
            }
            $cur=$cur->next;
            $l1=$l1->next;
        }

        while($l2!=null){
            $sum=$l2->val+$step;
            if($sum>=10){
                $cur->next=new ListNode($sum%10); 
                $step=1;               
            }else{
                $l2->val=$sum;
                $cur->next=$l2;
                $step=0;
                break;  //已经没有进位，提前结束循环
            }
            $cur=$cur->next;
            $l2=$l2->next;
        }
        
        if($step==1){
            $cur->next=new ListNode(1);     //表明还有进位          
        }
        return $dummyHead->next;
    }
}
```
- 递归方法
思路：将原问题分解为更小的问题。2个链表求和，也就是拿出2个链表的头部元素相加，再对剩余2个链表进行相加，如果元素头部大于等于10，说明需要进位，对后面求出来的链表进1位。
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
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
        if($l1==null){
            return $l2; //递归结束条件
        }

        if($l2==null){
            return $l1; //递归结束条件
        }

        $l1->next=$this->addTwoNumbers($l1->next,$l2->next);    //求出剩余链表的和，放入l1链表
        $l1->val=$l1->val+$l2->val;         //计算2个链表第一个元素和，放入l1链表         
        $t=$l1->next;
        if($l1->val>=10){       //处理第一个元素相加大于等于10，产生进位的情况
            $l1->val=$l1->val%10;
            if($t==null){
                $l1->next=new ListNode(1);
            }else{
                while($t!=null){
                    $t->val+=1;                    
                    if($t->val<10){
                        break;
                    }else{
                        $t->val=0;
                        if($t->next==null){
                            $t->next=new ListNode(1);
                            break;
                        }
                    }
                    $t=$t->next;
                }
                
            }
        }

        return $l1;     //最后将l1返回
    }
}
```

