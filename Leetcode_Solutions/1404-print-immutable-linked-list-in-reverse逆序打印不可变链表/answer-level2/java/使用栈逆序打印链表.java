栈的特点是后进先出，如果将链表元素顺序压入栈，则链表元素的弹出顺序是逆序。因此首先将所有链表元素顺序压入栈，然后依次弹出并打印。
```
class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        Stack<ImmutableListNode> stack = new Stack<ImmutableListNode>();
        ImmutableListNode temp = head;
        while (temp != null) {
            stack.push(temp);
            temp = temp.getNext();
        }
        while (!stack.isEmpty()) {
            ImmutableListNode node = stack.pop();
            node.printValue();
        }
    }
}
```
