本想用动态规划来做这题，思路如下：
先遍历一遍，得到所有节点的值的数组。令`s(i, j)`为下标从i到j的连续节点序列的元素和，则有如下递推公式：
- 若`i == j`，则`s(i, j) = node[i].val`
- 若`i < j`，则`s(i, j) = s(i, j- 1) + node[j].val`

于是写啊写，写啊写，写来写去发现越写越乱。。。
尽管提示貌似也是这么暗示的。。。

于是看了下题解和评论，发现了 [@philhsu](/u/philhsu/) 写的用前缀和实现的思路。于是灵光一闪，就有了下面这个优雅的解法！

`

    public ListNode removeZeroSumSublists(ListNode head) {
        if (head == null) {
            return null;
        }

        // 前序和：从第一个元素到当前节点的所有元素之和
        // 将每一个节点的前序和存于Map中，当某个前序和已经存在于Map中时，则表明两个相同的前序和之间有个总和为0的连续节点序列
        HashMap<Integer, ListNode> map = new HashMap<>();
        int sum = 0;
        ListNode cur = head;

        while (cur != null) {
            sum += cur.val;
            if (sum == 0) {
                // 前序和为0，则弃掉从开始至当前节点的序列
                head = cur.next;
                cur = cur.next;
                map.clear();
            } else {
                if (map.containsKey(sum)) {
                    // 遇到一个总和为0的连续节点序列，移除它；
                    map.get(sum).next = cur.next;

                    // 然后重头再来
                    cur = head;
                    map.clear();
                    sum = 0;
                } else {
                    map.put(sum, cur);
                    cur = cur.next;
                }
            }
        }

        return head;
    }

`
