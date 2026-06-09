### 解题思路
关键点：链表是顺序存储，从尾到头打印链表，符合栈的后入先出的访问规则，因此可借助栈来实现，java的容器LinkedList可以较好的实现栈和队列数据结构。因此可以使用LinkedList来解决该题。

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
import java.util.LinkedList;
import java.util.Iterator;

class Solution {
    public int[] reversePrint(ListNode head)  {
        MyStack<Integer> stack = new MyStack<Integer>();
        while(head != null){
            stack.push(head.val);
            head = head.next;
        }
        int[] result = new int[stack.size()];
        int j = 0;
        while(!stack.empty()){
                result[j++] = stack.pop() ;
        }
        return result;

    }

    private class MyStack<T> {
        private LinkedList<T> storage = new LinkedList<T>();
        public void push(T v){
            storage.addFirst(v);
        }
        public T pop(){
            return storage.removeFirst();
        }
        public T peek(){
            return storage.getFirst();
        }
        public boolean empty(){
            return storage.isEmpty();
        }
        public int size(){
            return storage.size();
        }
    }
}
```