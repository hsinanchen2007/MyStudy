函数的返回值的是数组，我看题目的形式以为返回的是链表，按照返回链表做了。在idea跑通了。
1. 思路：
先将原链表值存入集合，然后对集合从后往前遍历寻找是否存在更大值，动态规划思想
然后将链表从后往前连接，最后返回的就是答案数组的链表形式
```
    public static ListNode nextLargerNodes(ListNode head) {

        List<Integer> list = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            list.add(cur.value);
            cur = cur.next;
        }
        int size = list.size();
        //从后往前寻找更大值，创建最大值的节点，从后往前连接 <--
        int after = Integer.MIN_VALUE;
        //最后一个节点肯定是0值，因为之后没有元素比它大
        ListNode end=new ListNode(0);
        for (int i = size - 2; i >= 0; i--) {
            ListNode in = null;
            //存在更大就以该更大值创建节点。当前更大，则以0创建节点
            if (list.get(i) > list.get(i + 1)) {
                in = new ListNode(0);
            } else {
                in = new ListNode(list.get(i + 1));
                //当存在更大值时，需要修改当前值为更大值，用作下次被比较的对象。动态规划思想
                list.set(i, list.get(i + 1));
            }
            //从后往前连接节点
            in.next = end;
            end = in;
        }
        return end;
    }
```
