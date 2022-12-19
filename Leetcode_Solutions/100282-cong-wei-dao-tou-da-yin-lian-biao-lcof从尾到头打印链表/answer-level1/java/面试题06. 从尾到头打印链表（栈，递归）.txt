## 栈
### 解题思路
利用栈先进后出的特点，先依次将链表节点压入栈中，同时获得链表节点个数；再将节点从栈中弹出，顺序就变成了从尾到头，将节点的值输出到int数组。
时间复杂度：O(n)，遍历链表和弹出栈帧都是O(n)
空间复杂度：额外使用O(n)的栈空间
需要注意的是，栈(stack)底层使用数组实现，每次压入栈帧和弹出栈帧，都会引起数组的拷贝，效率其实不高。

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
        // 利用栈--先进后出的特点
        Stack<ListNode> stack=new Stack();
        // 将所有节点依次压入栈
        ListNode e=head;
        int length=0;
        while(e!=null){
            stack.push(e);
            e=e.next;
            length++;
        }
        int[] array=new int[length];
        for(int i=0; i<length; i++){
            array[i]=stack.pop().val;
        }
        return array;
    }
}
```

## 递归
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
    // 使用LinkedList，增删元素比ArrayList效率高
    // addLast()：向尾部插入元素、poll()：弹出头部元素，并删除
    private LinkedList<Integer> valueList = new LinkedList<>();
    public int[] reversePrint(ListNode head) {
        // 调用递归函数
        recurve(head);
        int size=valueList.size();
        int[] array=new int[size];
        for(int i=0; i<size; i++){
            array[i]=valueList.poll();
        }
        return array;
    }

    // 递归函数
    private void recurve(ListNode head){
        // 递归到尾节点指向的空指针时，不再递归调用
        if(head!=null){
            recurve(head.next);
            valueList.addLast(head.val);
        }
    }
}
```
