主要是解题，理解题目的意思，然后整理思路
1.其中循环的可递归的部分就是$k的位置。
2.用两个指针，表示开始和结束位置，下面$start开始，$end结束。
3.主要递归下一次开始的位置是 $start->next = $this->reverseKGroup($end,$k)，这地方比较烧脑。
4.烧脑部分：记住刚开始$start = $head ,这里$start->next 只是确定开始下一段旅程的位置


class Solution {

    /**
     * @param ListNode $head
     * @param Integer $k
     * @return ListNode
     */
    function reverseKGroup($head, $k) {
        if($head==null){
            return $head;
        }
        $start = $head; //开始位置
        $end = $head;
        for($i=0;$i<$k;$i++){
            if($end == null){
                return $head;
            }
            $end=$end->next;  //$k个结束的位置，及a-b在链接中的位置
        }
         //$start到$end，就是要反转的一段路，下次开始反转开始的位置就是$b，递归拼接到$newHead中
        $newHead = $this->reverList($start,$end);
        $start->next = $this->reverseKGroup($end,$k);//这里是递归，$head理解成一段
        return $newHead;
    }


    function reverList($a,$b){ 
         //这是一个反转函数，这个公式得熟记，这里应为是一段，所以while比较的是$curr!=$b,$curr表示当前节点
        $prev = null;
        $curr= $a;
        while($curr!=$b){
            $tmp = $curr->next;
            $curr->next = $prev;
            $prev = $curr;
            $curr = $tmp;
        }
        return $prev;
    }

}