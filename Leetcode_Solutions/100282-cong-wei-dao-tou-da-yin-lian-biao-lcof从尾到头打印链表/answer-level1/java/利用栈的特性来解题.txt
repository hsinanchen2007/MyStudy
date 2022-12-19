### 解题思路
![image.png](https://pic.leetcode-cn.com/c6697dd16c2448907d40ef5bd59c3331642460a47069b1a381407ea342839ed9-image.png)
第一步：先将所有的节点放入栈中，并用变量num记录一共有多少个。
第二步：for循环将栈中的所有数取出来放入数组中
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
        Stack<Integer> stack = new Stack<>();
        int num = 0;
        while(head!=null){
            stack.push(head.val);
            num++;
            head = head.next;
        }
        int[] res = new int[num];
        for (int i = 0; i < num; i++) {
            res[i] = stack.pop();
        }
        return res;
    }
}
```