```
public ListNode[] splitListToParts(ListNode root, int k) {
        int length = 0;
        ListNode h = root;
        while (h != null) {
            h = h.next;
            length++;
        }
        //能否完全分给k份
        boolean lengthLessK = length / k == 0;
        //如果不够分成k份，则每份只能分1个 ， 否则可以分 length / k个
        int cutCount =  lengthLessK ? 1 : length / k;
        // 如果不够分成k份， 则不需要前面几份多分， 否则前面prevCount份每份需要多分一个
        int preCount = lengthLessK ? 0 : length % k;
        ListNode[] listNodes = new ListNode[k];
        for (int i = 0; i < k; i++) {
            ListNode newHead = new ListNode(0);
            ListNode cur = newHead;
            //判断如果prevCount > 0 ，则每份需要多分一份
            for (int j = 0; j < (preCount <= 0 ? cutCount : cutCount + 1); j++) {
                if (root != null) {
                    cur.next = root;
                    cur = root;
                    root = root.next;
                }
            }
            //将需要多分的数量减一
            preCount--;
            //切断前面的节点和后面的联系
            cur.next = null;
            listNodes[i] = newHead.next;
        }
        return listNodes;
    }
```
