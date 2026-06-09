原始链表：1->2->3->4->5->NULL
第一次：5->1->2->3->4->NULL
第二次：4->5->1->2->3->NULL

第一反应是想到最粗暴的求解方式，每次查找链表的尾节点，拿出来后指向原头节点，并设置为新的头结点，就得k次循环链表。

再仔细看处理过程，k值未知的前提下，感觉是不是得连成个环，再考虑了下有没有反转链表的必要。后面慢慢觉得通过环和k与链表大小的关系，进行链表前进寻找新头节点。

1、一次循环链表得到链表长度，同时将尾结点的next指向头节点，得到一个环链表。
2、根据例子发现，链表长度为5，k为2，链表前进三次得到的节点即为新的头节点。同时若k与链表长度相等，处理前后链表相同，所以只需处理k % linkListLength。
3、上一步找到的头结点的前节点即为尾结点，所以查找头节点的next过程中，保存next前的节点，最后将尾结点的next指针指向为null，重新得到单链表。
4、执行过程为一次循环链表+链表长度次以内的链表前进。

最后看了下题解，发现思路一致，感觉还挺舒服有点成就感，果然思考的过程比结果更加重要。

    /**
     * @param ListNode $head
     * @param Integer $k
     * @return ListNode
     */
    function rotateRight($head, $k) {
        if ($head == null || $head->next == null) {
            return $head;
        }

        $len = 1;
        $tmp = $head;
        while ($tmp->next != null) {
            $tmp = $tmp->next;
            $len++;
        }
        $tmp->next = $head;

        if ($k > $len) {
            $nums = $k % $len;
        } else {
            $nums = $k;
        }
        $nums = $len - $nums;

        while ($nums--) {
            $tmp = $head;
            $head = $head->next;
        }
        $tmp->next = null;

        return $head;
    }