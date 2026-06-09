# 写在解题之前 

陆续做了几道链表题, 发现总是会出现预期与实际不符的情况, 导致花费时间指数上升, 因此决心把链表画下来, 一步一步走, 
体会题目要求与条件后, 再结合图解过程, 链表问题都迎刃而解. 

# 解题思路

> 一般情况

由于题目要求将位置为奇数元素按原有顺序放置在链表前半部分, 偶数位置元素按原有顺序放置在链表后半部分, 且要求原地修改, 使用O(1)的存储空间. 
于是想使用两个指针, 分别指向奇数链`odd_head`, 偶数链`even_head`. 
另用`odd`与`even`实际更新指针位置.
当链表遍历完时, 将奇数链与偶数链合并即可`odd.next = even_head`.

> 边界情况

由于奇数链被要求放在结果链的前半部分, 所以奇数链的最后一个元素不能为空. 
但是奇数链需要由even节点更新, 即只要even != null 并且 even.next != null, 
则可以更新奇偶链最新位置. 

> 思路草图

![picture.png](https://pic.leetcode-cn.com/af4c9d9880fb03d5f889babbaab595fb7f448c6f5492de51f5daab0eb9eee9a7-picture.png)


> 遍历过程视频

![单向链表之奇偶链表.mp4](9a32afdb-7335-4b6b-9774-a7edc7e1d7af)

# 代码

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null) return head;
		ListNode even = head.next;
		ListNode odd = head;
		ListNode even_head = even;
		ListNode odd_head = odd;
		while(even != null && even.next != null){  
			odd.next = even.next;
			odd = even.next;
			even.next = odd.next;
			even = odd.next;
		}
		odd.next = even_head;
		head = odd_head;
		return head;
    }
}
```

# 执行效率

![image.png](https://pic.leetcode-cn.com/216ac0abbeb9fa3ed6d7d4ed245e00572c7adf78bdc42c4bd21be868a58ceb45-image.png)
