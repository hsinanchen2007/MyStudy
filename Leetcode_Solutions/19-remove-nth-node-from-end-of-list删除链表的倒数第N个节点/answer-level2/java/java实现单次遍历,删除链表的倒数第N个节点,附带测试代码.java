这结果,不是很稳定:
执行用时 :
0 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
34.8 MB
, 在所有 java 提交中击败了
86.79%
的用户 
```
package leetcode;


public class RemoveNthFromEnd {
	
	// 采用快指针先出发,慢指针在快指针移动n步后开始移动,同时记录满指针此时的链表前置
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int fast = 0; // 快指针
        int slow = 0; // 慢指针
        ListNode dummy = new ListNode(0); // 用来记录头指针
        dummy.next = head;
        ListNode nnode = dummy; // 当慢指针移动的时候,记录该node节点
        while (head.next != null) {
            head = head.next;
            fast += 1;
            if (fast >= slow + n ) { // 慢指针出发条件,并持续移动
                slow += 1;
                nnode = nnode.next;  // 记录慢指针的node值
            }
        }
        if (nnode == null) {
            return null;
        }
        if (nnode.next != null) {
            nnode.next = nnode.next.next;
        }
        return dummy.next;
 
    }

 
	
	public static void main(String[] args) {

        int[] test = new int[]{1, 2, 3, 4, 5}; // ,2,3,4,5
        ListNode aa = new ListNode(0);
        ListNode dummy = aa;
        for (int i : test) {
            aa.next = new ListNode(i);
            aa = aa.next;
            System.out.println(" add node " + i);
        }
        RemoveNthFromEnd removeNthFromEnd = new RemoveNthFromEnd();

        ListNode node = removeNthFromEnd.removeNthFromEnd(dummy.next, 1);
        if (node != null) {
            System.out.println("--" + node.val);

            while (node.next != null) {
                node = node.next;
                System.out.println("--" + node.val);
            }
        }
    }
}

```
