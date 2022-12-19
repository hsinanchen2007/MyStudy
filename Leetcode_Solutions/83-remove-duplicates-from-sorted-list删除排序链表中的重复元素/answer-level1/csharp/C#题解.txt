```
public static ListNode DeleteDuplicates(ListNode head)
        {
            if (head == null)
            {
                return null;
            }
            Dictionary<string, string> dic = new Dictionary<string, string>();
            dic.Add(head.val.ToString(), head.val.ToString());
            ListNode liNext = head;
            while (liNext.next != null)
            {
                if (!dic.ContainsKey(liNext.next.val.ToString()))
                {
                    dic.Add(liNext.next.val.ToString(), liNext.next.val.ToString());
                    liNext = liNext.next;
                }
                else
                {
                    liNext.next = liNext.next.next;
                }
                if (liNext == null)
                {
                    break;
                }
            }
            return head;
        }
```
