  public static ListNode RemoveNthFromEnd(ListNode head, int n)
        {
            if (head == null) return null;
            Dictionary<int, ListNode> dic = new Dictionary<int, ListNode>();
            int k = 0;
            dic.Add(k, head);
            while(head.next!=null)
            {
                head = head.next;
                k++;
                dic.Add(k, head);
            }
            if(n==1)
            {
                if (k > 0)
                {
                    dic[k - 1].next = null;
                    return dic[0];
                }
                else
                {
                    return null;
                }
            }
            else
            {
                if (n == k + 1)
                {
                     return dic[1];
                }
                else
                {
                    dic[k - n].next = dic[k - n + 2];
                    return dic[0];
                }
            }
        }