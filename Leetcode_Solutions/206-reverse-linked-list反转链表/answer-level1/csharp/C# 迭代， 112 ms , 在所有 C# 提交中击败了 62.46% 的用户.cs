参考：[http://www.pianshen.com/article/517476376/](http://www.pianshen.com/article/517476376/)

![585213d637ce67804647eba51570727d.png](https://pic.leetcode-cn.com/3d7bc23b7220eda9501244596c0785c76723bc1b79b008a79846b7619fedfe75-585213d637ce67804647eba51570727d.png)


```
public class Solution {
    public ListNode ReverseList(ListNode head) 
    {
          ListNode pre=null;
          ListNode next=null;

          while(head!=null)
          {
              next=head.next;

              head.next=pre;
              
              pre=head;
              head=next;
          }
          return pre;
    }
}
```