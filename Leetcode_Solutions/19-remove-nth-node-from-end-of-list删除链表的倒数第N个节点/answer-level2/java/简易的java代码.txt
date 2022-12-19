### 代码

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head,int n){
		// 1.5趟扫描实现
		// 第一趟扫描，计算链表长度
		ListNode p = head;
		int sum = 0;
		while(p!=null){
			sum++;
			p = p.next;
		}
		int index = sum - n;
		int count = 1;
		p = head;
		if(index == 0){
			return head.next;
		}
		while(count<index){
			p = p.next;
			count++;
		}
		ListNode temp = p.next.next;
		p.next = temp;
		return head;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/7348f182d9a0816f3105f08ff75b6a2a14de0c6916fbb566c529ec0ba38f1ec1-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/1c63c9dbb9c3a8e65067906031a06ecf96ecc8b13e9c68b46eb3121f4a68b27f-wechat.png)

