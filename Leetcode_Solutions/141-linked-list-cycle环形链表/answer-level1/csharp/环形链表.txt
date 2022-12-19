**思路：** 快慢指针，快慢指针同时从头节点出发，快指针每次走两步，慢指针每次走一步，如果存在环的话，快指针迟早赶上慢指针。
```
public bool HasCycle(ListNode head)
        {
            //if (head == null || head.next == null)
            //{
            //    return false;
            //}

            ListNode slow = head;
            ListNode fast = head;

            while (fast != null && fast.next != null)
            {
                slow = slow.next;
                fast = fast.next.next;
                //网友指正，这个判断可以直接放到while中
                //if (fast == null)
                //{
                //    return false;
                //}
                //if (slow.val == fast.val)，不应该比较值，而应该直接比较对象查看其内存地址是否一致
                if(slow == fast)
                {
                    return true;
                }
            }

            return false;
        }
```
**注：** 多拿例子试，边界问题有点恶心。