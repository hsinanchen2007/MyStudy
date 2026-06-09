这一题在初学数据结构的时候曾经作为选择题出现过，所以对于借助结点的双指针算法还是会的；但是我也想拓展一下，不追求效率还有没有其他方法：
思路：翻转此题中的链表只用改变ListNode中的int 类型的val就行了，那我可以遍历一下把他们存储起来然后赋值不就行了，代码如下：（包括测试代码）
```java
public class ReverseLinked {
public static ListNode reverseList(ListNode head) {
		List<Integer> list = new ArrayList<>();
		ListNode node = head;
		while(node!=null) {
			list.add(node.val);
			node = node.next; 
		}
		System.out.println(list);
//用collections工具类来实现list的翻转
		Collections.reverse(list);
		node = head;
		int i=0;
		while(node!=null){
			node.val = list.get(i++);
			node = node.next;
		}
		return head;
	}
public static void main(String[] args) {
		ReverseLinked.ListNode head = new ReverseLinked().new ListNode(5);
		head.next = new ReverseLinked().new ListNode(4);
		head.next.next = new ReverseLinked().new ListNode(3);
		head.next.next.next = new ReverseLinked().new ListNode(2);
		head.next.next.next.next = new ReverseLinked().new ListNode(1);
 		System.out.println(reverseList(head));
	}
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
	@Override
	public String toString() {
		ListNode node = this;
		StringBuffer sb = new StringBuffer();
		sb.append("[");
		while(node!=null) {
			sb.append(node.val+",");
			node = node.next;
		}
		sb.setCharAt(sb.length()-1, ']');
		return sb.toString();
	}
}
```
当然我能也可以直接存储object对象一个一个链接起来，我用stack也写了一个效率不高也没有提交但是也是一种思路：
```java
private static ListNode reverseList1(ListNode head) {
		Stack<ListNode> stack = new Stack<>();
		while(head!=null) {
			stack.add(head);
			head = head.next;
		}
		head = stack.pop();
		ListNode node = head;
		while(!stack.empty()) {
			node.next = stack.pop();
			node = node.next;
		}
//必须将此时的node的next赋值为null不然就循环起来了
		node.next = null;
		return head;
	}
```
