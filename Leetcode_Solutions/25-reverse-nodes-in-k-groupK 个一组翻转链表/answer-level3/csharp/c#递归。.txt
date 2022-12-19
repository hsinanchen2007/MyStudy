    public class Solution
    {
            public ListNode ReverseKGroup(ListNode head, int k)
        {
            List<ListNode> list = new List<ListNode>();
            ListNode p = head;
            for (int i = 0; i < k; i++)
            {
                if (head == null) { return p; }
                list.Add(head);
                head = head.next;
               
            }
            for (int i = 1; i < k; i++)
            {
                list[i].next = list[i - 1];
            }
            list[0].next = ReverseKGroup(head, k);
            return list[k - 1];
        }
    }

