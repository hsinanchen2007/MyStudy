![2020032001.PNG](https://pic.leetcode-cn.com/2b13cfa68d5febaf354d6d03b1f3a0d87b0e52cfba3b13fa9583b4b7174c160c-2020032001.PNG)

### 解题思路
思路:
1. 先遍历一遍链表, 得到结点的个数cnt, 

2. 依据结点的个数, 声明一个长度等于结点个数的整型数组out, out用来记录结果

3. 声明栈stackNode 放置链表结点

4. 声明栈stackNum 放置链表结点在数组out中对应的索引值

5. 遍历链表, 
--5.1 当stackNode 为空, 或者stackNode 的栈顶的元素值大于或等于当前结点的元素值,将该结点放入栈stackNode中, 并将该结点在out中对应的索引值放入stackNum中,

--5.2 当满足stackNode非空, 且stackNode 的栈顶的元素值小于当前结点的元素值时, 将stackNode 和 stackNum(记出栈元素对应的索引值 index=stackNum.pop())的元素出栈, 并将出栈的元素在out中对应的索引位置赋值为temp.val, 即out[index] = temp.val;

6. 最后, 在判断stackNum是否为空, 若stackNum 非空, 将stackNum中的元素对应的out索引位置全部赋值为0; 返回数组out即可

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
    public int[] nextLargerNodes(ListNode head) {
    	int cnt = 0;
    	ListNode temp = head;
    	while(temp!=null) {
    		cnt++;
    		temp = temp.next;
    	}
    	int[] out= new int[cnt];
        Deque<ListNode> stackNode = new LinkedList<>();
        Deque<Integer> stackNum = new LinkedList<>();
        temp = head;
        cnt = 0;
        while(temp != null) {
        	while(!stackNode.isEmpty()&&(stackNode.peek().val<temp.val)) {	
        		stackNode.pop();
        		out[stackNum.pop()] = temp.val; 
        	}
    		stackNode.push(temp);
    		stackNum.push(cnt);
    		cnt++;
    		temp = temp.next;
        }
        while(!stackNum.isEmpty()) {
        	out[stackNum.pop()] = 0;
        }
        return out;
    }
}
```