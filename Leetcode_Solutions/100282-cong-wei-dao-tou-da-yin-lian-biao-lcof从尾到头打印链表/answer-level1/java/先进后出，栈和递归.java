### 解题思路
题目描述了一个先进后出的结构，很容易想到栈，
进而想到递归，递归也可以实现先进后出，只要将本节点的操作置于递归之后即可。


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
        while (head != null) {
            stack.push(head.val);
            head = head.next;
        }
        int size = stack.size();
        int[] res = new int[size];
        for (int i = 0; i < size; i++) {
            res[i] = stack.pop();
        }
        return res;
    }

}
```
### 递归

实现一个addResult()方法，先递归，后做本函数内添加操作。

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
    private ArrayList<Integer> res = new ArrayList<>();
    public int[] reversePrint(ListNode head) {
        addResult(head);
        int size = res.size();
        int[] a = new int[size];
        for(int i = 0; i < size; i++){
            a[i] = res.get(i);
        }
        return a;
    }
    private void addResult(ListNode head){
        if(head != null){
            if(head.next != null){
                addResult(head.next);
            }
            res.add(head.val);
        }
    }
}
```