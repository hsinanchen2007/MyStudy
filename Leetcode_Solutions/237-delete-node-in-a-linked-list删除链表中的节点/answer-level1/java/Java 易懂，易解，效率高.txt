**1.关注代码的规范性、完整性、鲁棒性。
2.此方法注意两点：(1):无法删除最后一个结点的值(2):并没有真正的删除结点,只是改变了结点的值而已,这种方法在工程上是不推荐使用的;
3.完结。**

        public void deleteNode(ListNode node) {
            if (node == null)
                return;
            ListNode next = node.next;
            if (next != null) {
                throw new RuntimeException("can not remove last node");
            }
            node.val = next.val;
            node.next = next.next;
        }