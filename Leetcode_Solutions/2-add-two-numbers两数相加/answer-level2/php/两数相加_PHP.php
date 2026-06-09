先说下思路吧：看到题后，因为是两个链表，头部即是其中一个数的最低位，所以其实说白了就是让两个链表，每个相对应的部位进行相加，只是有个注意的地方是，相加后可能有进位，需要把这个进位给带到下一个节点去，保持这种节点相加，最后即可算出答案。下面直接给出代码，并带注释：
```php []
    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
        //首先初始化一个新的链表，头结点设为0值，因为0代表着没值。
        $result = new ListNode(0);
        $nextRst = $result;
        //设立两个变量，一个是进位值$carry（只会有0和1），一个$singleValue是两个相同节点相加后模10后的值。
        $carry = $singleValue = 0;
        //对两个链表进行循环，只要有一个没有遍历完，都继续
        while (!empty($l1) || !empty($l2)) {
            //Step 1:分别把两个节点的值复制给对应变量
            $aValue = !empty($l1) ? $l1->val : 0;
            $bValue = !empty($l2) ? $l2->val : 0;
            //Step 2:两个值相加后加上进位值（也就是$carry，初次循环默认就是函数初始化时的0），最后模10
            $singleValue = ($aValue + $bValue + $nextRst->val) % 10;
            //Step 3:同上，只是这里计算进位值
            $carry = floor(($aValue + $bValue + $nextRst->val) / 10);
            //Step 4:把模10后的值，赋值给$nextRst当前节点的值，
            $nextRst->val = $singleValue;
            if (!empty($l1)) {
                $l1 = $l1->next;
            }
            if (!empty($l2)) {
                $l2 = $l2->next;
            }
            if (!empty($l1) || !empty($l2)) {
                //Step 5:把进位传给下一个节点的val值，备用（给Step 2，Step 3使用）
                $nextRst->next = new ListNode($carry);
                //Step 6:节点遍历
                $nextRst = $nextRst->next;
            }
        }
        if ($carry) {
            //此处判断的原因在于，当两个链表中最后一个节点相加完成后，仍然有进位，那就只能新增一个节点1了
            $nextRst->next = new ListNode($carry);
        }
        return $result;
    }
```
