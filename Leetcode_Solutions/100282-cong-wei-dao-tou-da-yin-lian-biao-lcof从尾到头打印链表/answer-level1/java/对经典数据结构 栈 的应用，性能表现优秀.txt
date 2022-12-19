### 写在前面
从头节点遍历链表，越是先访问的数据越是要后打印，已满足从尾到头打印链表的需求，正因为这样的特点，我们可以找到相应的数据结构实现该功能，也就是栈。

先遍历链表，将每个数据入栈，然后再逐个出栈存到数组中并返回数组即可

此方法性能效果也比较好
![QQ截图20200213142519.png](https://pic.leetcode-cn.com/604ecf4aaad0d07e6d25722b3230e4093934aa52b7b289b7e44606af456e991b-QQ%E6%88%AA%E5%9B%BE20200213142519.png)

- 时间复杂度：O（n）
- 空间复杂度：O（n）


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
    public int[] reversePrint(ListNode head) {
        Stack<Integer> stack = new Stack<Integer>();
		if(head == null)  //如果链表为空，则返回一个空数组即可
			return new int[0];
		ListNode node = head;
		int count = 0; //记录入栈的数的个数
		while(true) {
			if(node.next == null) {
				stack.push(node.val);
				count++;
				break;
			}
			stack.push(node.val);
			count++;
			node = node.next;
		}
		int[] arr = new int[count];
		for(int i = 0;!stack.isEmpty();i++) {
			arr[i] = stack.pop(); 
		}
		return arr;
    }
}
```