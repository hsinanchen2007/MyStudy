### 代码

```java
class Solution {
    public ListNode rotateRight(ListNode head,int k){
		if(head == null){
			return head;
		}
		ListNode p = head;
		int len = 1;
		while(p.next!=null){
			len++;
			p = p.next;
		}
        if(len == 1 || k % len == 0){
			return head;
		}
		ListNode tail = p;
		int index = len - (k % len);
		int count = 1;
		p = head;
		while(count<index){
			count++;
			p = p.next;
		}
		ListNode q = p.next;
		p.next = null;
		tail.next = head;
		return q;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/539d5308c814e5895babecc5489be5b04e8608ea9d93dacec17b90250c9b5c31-1.png)
