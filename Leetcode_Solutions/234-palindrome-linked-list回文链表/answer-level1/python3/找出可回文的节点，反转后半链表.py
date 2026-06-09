### 解题思路
1、循环找出貌似满足回文条件的节点，记录后半链表
2、后半段链表进行反转
3、对比两段链表，是否一样

### 代码

```python3


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True

        pre,cur = head,head.next
        head1 = None
        
        while cur:
            #while循环找出相邻两个相等，就把链路拆断
            if pre.val == cur.val:
                #特殊考虑1个用例，[1,2,2,2,1]的情况
                if cur.next and cur.val == cur.next.val:
                    pre.next=None
                    head1=cur.next
                #其他相邻两个相等的情况
                else:
                    pre.next=None
                    head1=cur

                break
            #[1,0,1]考虑这种情况
            elif cur.next and pre.val == cur.next.val:
                pre.next=None
                head1 = cur.next
                break

            else:
                pre,cur = cur,cur.next
  
        #把后半段进行反转
        pre1,cur1 = None,head1
        while cur1:
            cur1.next,pre1,cur1 = pre1,cur1,cur1.next
        head1 = pre1

        #两半段链路进行对比，看是否一样
        cur,cur1 = head,head1
        while cur and cur1:
            if cur.val == cur1.val:
                cur,cur1 = cur.next,cur1.next
            else:
                return False
        
        if cur == None and cur1 ==None:
            return True
        else:
            return False
```