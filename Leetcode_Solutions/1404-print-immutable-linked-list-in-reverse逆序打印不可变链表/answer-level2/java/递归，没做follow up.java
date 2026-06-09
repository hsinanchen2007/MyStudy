### 解题思路
此处撰写解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.44%
的用户
内存消耗 :
38.3 MB
, 在所有 Java 提交中击败了
18.18%
的用户
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
        if (head == null) return;
        printLinkedListInReverse(head.getNext());
        head.printValue();
    }
}
```