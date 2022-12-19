将每个非空链表的头节点放入优先队列，后续逐个拿到最小值后，若对应的链表不为空，则再将对应链表的头节点放入优先队列，直到所有的链表为空。

    class TreeMinHeap extends SplMinHeap
    {
        public function compare($data1, $data2)
        {
            return $data2->node->val - $data1->node->val;
        }
    }

    class NodeObj
    {
        public $node;
        public $linkedIndex;

        public function __construct($node, $index)
        {
            $this->node = $node;
            $this->linkedIndex = $index;
        }
    }
    class ListNode {
        public $val = 0;
        public $next = null;
        function __construct($val) { $this->val = $val; }
    }
    class Solution {

        /**
        * @param ListNode[] $lists
        * @return ListNode
        */
        function mergeKLists($lists) {
            $heap = new TreeMinHeap();
            foreach ($lists as $key => $list) {
                if (empty($list)) continue;
                $heap->insert(new NodeObj($list, $key));
                $lists[$key] = $lists[$key]->next;
            }

            $tmp = $newHead = new ListNode(0);
            while ($heap->count() > 0) {
                $nodeObj = $heap->extract();
                $node = $nodeObj->node;
                $node->next = null;
                $tmp->next = $node;
                $tmp = $tmp->next;

                $index = $nodeObj->linkedIndex;
                if ($lists[$index] != null) {
                    $heap->insert(new NodeObj($lists[$index], $index));
                    $lists[$index] = $lists[$index]->next;
                }
            }
            return $newHead->next;
        }
    }