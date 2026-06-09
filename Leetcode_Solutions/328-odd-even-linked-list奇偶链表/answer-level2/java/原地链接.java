思路分析：用3个指针标记，分别记录奇数节点的位置，偶数节点的位置，返回的头节点。首先对空节点及单个节点进行判断；  从第二个几点开始进行遍历，根据位置的奇偶性进行插入，标记的指针随之移动。
注意的点：最后一个节点的next指向要置null。

![image.png](https://pic.leetcode-cn.com/937b516f6630649f8a224445e16ca6f69a9ff43f31647fbec8866c45096f828c-image.png)


```
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head==null||head.next==null)return head;
		ListNode h1=head;//奇数节点的位置
		ListNode h=head;//标记返回的头节点
		ListNode h2=head;//偶数节点的位置
		head=head.next;//从第二个节点开始遍历
		int i=2;
		while(head!=null) {
			ListNode t=head.next;//记录下一个节点位置
			if(i%2==1) {//odd
				head.next=h1.next;
				h1.next=head;
				h1=h1.next;//奇数指针随之移动
			}else {
				head.next=h2.next;
				h2.next=head;
				h2=h2.next;
			}
			i++;
			head=t;
		}
		h2.next=null;//最后一个节点的next指向要置null
		return h;
    }
}
