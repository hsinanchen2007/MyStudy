
#### (Java 实现 ，【1，1】用例，测试通过，用时1毫秒。自己大意了，这么久才发现转换问题..惭愧)
```
class Solution {
    public ListNode deleteDuplicates(ListNode head) {

            // 1.base cases
            if (head == null || head.next == null) return head;

            // 2.哑节点,快慢指针
            ListNode dummy = new ListNode(-1);
            dummy.next = head;
            ListNode slow = dummy;
            ListNode fast = head;

            while (fast != null)
            {
                // 楼下 Fitz 大神提示的对！
                if((fast.next != null && fast.val !==fast.next.val) || fast.next == null) 
                {                  
                    if (slow.next == fast)     //   3.2 & 3.3 
                    {
                        slow = fast;
                    }
                    else                    
                    {
                        slow.next = fast.next;
                    }
                }
                fast = fast.next;
            }

            return dummy.next;

    }
}
```

#### (C# 实现 ，fast.val != fast.next?.val --> C#的语法糖)
```
    public ListNode DeleteDuplicates(ListNode head) {
            // 1.base cases
            if (head == null || head.next == null) return head;

            // 2.哑节点,快慢指针
            ListNode dummy = new ListNode(-1);
            dummy.next = head;
            ListNode slow = dummy;
            ListNode fast = head;

            // 3.1 fast 遍历链表,让fast 去嗅探不相等元素
            // 3.2 slow.next == fast --> slow 与 fast 之间没有重复元素，slow 动。
            // 3.3 slow.next != fast --> slow 与 fast 之间存在重复元素，让slow指向的元素跳过这些重复元素，slow 不动。
            while (fast != null)
            {
                if (fast.val != fast.next?.val)
                {                  
                    if (slow.next == fast)     //   3.2 & 3.3 
                    {
                        slow = fast;
                    }
                    else                    
                    {
                        slow.next = fast.next;
                    }
                }
                fast = fast.next;
            }

            return dummy.next;
    }
```

 3.1 fast 遍历链表
 3.2 slow 变更：head 到 slow的链表,已经符合题目要求
 3.3 slow.next 变更：删除了重复元素

快慢指针实战二：[leetcode 369  给单链表加一](https://leetcode-cn.com/problems/plus-one-linked-list/solution/c-kuai-man-zhi-zhen-bu-fan-zhuan-lian-biao-by-kao-/)


### 11-20 更新 

// C# 语法糖
if(fast.val != fast.next?.val)    
{
    ...
}

等价于

// java C# 通用写法
if((fast.next != null && fast.val !==fast.next.val) || fast.next == null)
{
    ...
}


欢迎指点，吐槽，互相学习~