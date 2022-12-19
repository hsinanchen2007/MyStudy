在没有进位，并且已经遍历完一个ListNode并且无需再进位以后，会跳出循环。

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2){
            // 判一下有null的情况
            if (l1 == null)
            {
                return l2;
            }
            else if (l2 == null)
            {
                return l1;
            }

            // 全都非null，以l1为被加数，因此，结果返回的就是l1的
            ListNode res = l1;
            bool sign = false;

            // 先加第一位
            l1.val += l2.val;
            if (l1.val > 9)
            {
                sign = true;
                l1.val -= 10;
            }

            // 循环加后续位
            while (l2.next != null || sign)
            {
                if (l1.next == null)
                {
                    if (l2.next == null)
                    {
                        // 只有sign，生成节点后直接break
                        l1.next = new ListNode(1);
                        break;
                    }
                    else if (!sign)
                    {
                        // 只有l2，直接把l2的后续拼接上来即可跳出循环
                        l1.next = l2.next;
                        break;
                    }
                    else
                    {
                        l1.next = new ListNode(l2.next.val + 1);
                    }
                }
                else if (l2.next == null)
                {
                    // 此处不需要判sign，因为sign在循环条件中已经判断过了，此处sign必为true
                    ++l1.next.val;
                }
                else if (!sign)
                {
                    // 没有sign
                    l1.next.val += l2.next.val;
                }
                else
                {
                    l1.next.val += l2.next.val;
                    ++l1.next.val;
                }

                // 判断是否需要后续的进位
                if (l1.next.val > 9)
                {
                    sign = true;
                    l1.next.val -= 10;
                }
                else
                {
                    sign = false;
                }

                // l1和l2右移，l1必然右移，l2要判断是否需要
                l1 = l1.next;
                l2 = l2.next ?? l2;
            }

            return res;
    }
}
```


PS，同样的代码，两次提交会出现耗时差异，一次124，一次168，不知道为啥