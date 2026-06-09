### 解题思路
此处撰写解题思路

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
     public void fun(ImmutableListNode head){
            if(head.getNext()==null){
                head.printValue();
                return;
            }
            fun(head.getNext());
            head.printValue();
        }

    public void printLinkedListInReverse(ImmutableListNode head) {
       fun(head);
    }
}
```