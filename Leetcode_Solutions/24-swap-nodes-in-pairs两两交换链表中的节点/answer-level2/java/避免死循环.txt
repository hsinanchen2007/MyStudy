### 解题思路
将一个新的ListNode不断的指向该指向的地方，两个指针p1,p3判断next是否存在，是否需要交换

![](https://pic.leetcode-cn.com/3ad499dcfc3969bf8fa5135934df3bafba195685f7381020e3bb6731f08d87cb-image.png)


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null) {
        	return null;
        }
        if(head.next==null) {
        	return head;
        }
//和之前的解决方法一样，new一个虚头
        ListNode p0 = new ListNode(-1);
//记录p0位置
        ListNode res = p0;

//p1当前交换位置，p3下一次交换位置
        ListNode p1 = head;
        ListNode p3 = head.next.next;
        
        while(p3 != null) {
        	
        	p0.next = p1.next;
        	p0 = p0.next;
        	p0.next = p1;
        	p0 = p0.next;
        	p1 = p3;
//偶数进行下一轮，单数直接返回
        	if(p3.next != null) {
        		p3 = p3.next.next;
        	}else {
        		p0.next = p1;
            	p0 = p0.next;
            	p0.next = null;
            	return res.next;
        	}
        	
        }
        
        
        p0.next = p1.next;
    	p0 = p0.next;
    	p0.next = p1;
    	p0 = p0.next;
//将p0最后一个元素的next置为knll，不然死循环
    	p0.next = null;
        
        return res.next;
        
    }
}
```

