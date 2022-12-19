### 解题思路
利用栈来记录逆序，依次pop进行打印

### 代码

```java
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * interface ImmutableListNode {
 *     public void printValue(); // print the value of this node.
 *     public ImmutableListNode getNext(); // return the next node.
 * };
 */

class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        Stack<ImmutableListNode> stack =new Stack<>();
        while(head!=null){
            stack.push(head);
            head=head.getNext();
        }
        ImmutableListNode node;
        while(!stack.isEmpty()){
            node=stack.pop();
            node.printValue();
        }
    }
}
```