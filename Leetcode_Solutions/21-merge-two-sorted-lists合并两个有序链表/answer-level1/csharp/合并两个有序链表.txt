说实话一直觉得递归的代码有点难理解，因此本人的方法是先排序，最后生成链表，代码如下：
```
public ListNode MergeTwoLists(ListNode l1, ListNode l2)
        {
            List<int> list = new List<int>();
            while (l1 != null && l2 != null)
            {
                if (l1.val <= l2.val)
                {
                    list.Add(l1.val);
                    l1 = l1.next;
                }
                else
                {
                    list.Add(l2.val);
                    l2 = l2.next;
                }
            }

            // l1的剩余部分
            while (l1 != null)
            {
                list.Add(l1.val);
                l1 = l1.next;
            }

            // l2的剩余部分
            while (l2 != null)
            {
                list.Add(l2.val);
                l2 = l2.next;
            }

            int length = list.Count;

            // 链表为空
            if (length == 0)
            {
                return null;
            }

            // 一个元素
            if (length == 1)
            {
                return new ListNode(list[0]);
            }

            // 两个元素
            if (length == 2)
            {
                return new ListNode(list[0]) { next = new ListNode(list[1]) };
            }

            // 三个及以上元素
            ListNode root = new ListNode(list[0]);
            ListNode nextNode = new ListNode(list[length - 1]);
            for (int i = length - 2; i > 0; i--)
            {
                ListNode node = new ListNode(list[i]);
                node.next = nextNode;
                nextNode = node;
            }
            root.next = nextNode;
            return root;
        }
```
