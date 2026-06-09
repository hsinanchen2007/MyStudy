### 解题思路
*题目要求：你的算法只能使用常数的额外空间*
- 这句话告知我们不能使用递归思路去求解，只能用不断迭代的思想慢慢遍历链表。

[PS：图片转载自"王小二"---图解k个一组翻转链表]()

做题之前先自己画个图想想大致思路，理清每一个临界位置的指向

- 首先通过`k`次`for`循环用`end`指针指向**翻转元素的末尾**

- 此时判断一下如果翻转元素不到`k`个，即`end`==`null`，说明已经到达末尾，直接返回即可

- 接下来需要定义两个指针`pre`和`pLast`分别记录**翻转元素的前驱和后继**，以便将翻转元素前后两部分连接起来

- 之后再重置`pre`和`end` 指针，进入下一次循环

- 遍历完之后返回`dummy`带头结点接下来的元素即可。


![866b404c6b0b52fa02385e301ee907fc015742c3766c80c02e24ef3a8613e5ad-k个一组翻转链表.png](https://pic.leetcode-cn.com/47c772ce6f7fd5c802ae9181973b52b0b892a0feeea6d7e3c51e3c220b89cb8c-866b404c6b0b52fa02385e301ee907fc015742c3766c80c02e24ef3a8613e5ad-k%E4%B8%AA%E4%B8%80%E7%BB%84%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.png)


### 代码

```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode end = dummy;
        while (end != null) {
            // 让 end 遍历到需要翻转的最后一个元素位置
            for (int i = 0; i < k && end != null; i++) {
                end = end.next;                    
            }
            // 只要 end 遍历到了 null 直接跳出循环
            if (end == null) {
                break;
            }
            // 定义 pLast 指向翻转元素后面第一个元素
            ListNode pLast = end.next;
            // 定义 start 指向翻转元素的第一个位置
            ListNode start = pre.next; 
            // 最后一个翻转元素先断链
            end.next = null;
            // 然后通过翻转方法 reverse() 后接在 pre 后面
            pre.next = reverse(start);
            
            // 保持下次循环一致的位置
            start.next = pLast;
            pre = start;
            end = pre;           
        }
        return dummy.next;
    }
    
    // 链表逆转模版
    private ListNode reverse(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode p = cur.next;
            cur.next = pre;
            pre = cur;
            cur = p;            
        }
        return pre;
    }
}
```