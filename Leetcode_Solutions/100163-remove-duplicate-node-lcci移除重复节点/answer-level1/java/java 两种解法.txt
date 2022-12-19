### 解法一：两层while循环，双指针，也可以说是三指针（暴力解法）
### 解题思路
以时间换空间，空间复杂度较小，耗时较长
1.快慢双指针，第一层大循环为slow非空的循环，
2.第二层循环为fast循环，prev的下一个始终指向fast，保证出现fast.val==slow.val
时，可以有效的删除相同结点，只需要fast和prev即可完美做到
3.slow和fast双层循环依次进行，slow和fast以及以后的依次比较，直到结束

### 代码

```java
class Solution {
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null || head.next==null) return head;
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev;
        while(slow!=null){
            fast  = slow.next;
            prev = slow;
            while(fast!=null){
                if(fast.val==slow.val)
                    prev.next = fast.next;
                else
                    prev = prev.next;
                fast = fast.next;
            }
            slow = slow.next;
        }
        return head;
    }
}
```
### 解法二：继承上面算法一的内层循环的两个指针，哈仪表存储检验
### 解题思路
1.HashSet中存入未曾出现的元素，prev和current依次向后推进
2.HashSet出现出现过的元素，使用prev和current删除重复结点
3.只用单层循环即可完成目标
注：prev可以定义为头结点，也可以定义为head，修改小部分代码，即可完成

### 代码

```java
class Solution {
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null || head.next == null ) return head;
        ListNode current = head;
        ListNode prev = new ListNode(0);
        prev.next = head;
        Set<Integer> s = new HashSet<Integer>();
        while(current!=null){
            if(!s.contains(current.val)){
                s.add(current.val);
                prev = current;
            }
            else{
                prev.next = current.next;
            }
            current=current.next;
        }
        return head;
    }
}
```
