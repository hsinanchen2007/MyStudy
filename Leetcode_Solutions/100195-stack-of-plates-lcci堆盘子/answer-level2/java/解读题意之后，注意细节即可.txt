### 解题思路
![image.png](https://pic.leetcode-cn.com/d0529ece6af7390790a0b7b3cc49b00cf4467499e5cafb8858c92f316d888806-image.png)
* 思路：
 *  构建数据结构，数据元素是链表，关系是数组，由于数组大小未知（需要扩容）并且涉及到数据元素的移动，所以我偷懒使用List集合
 *  根据题意，push和pop操作只能在最后一个栈中操作。
 * 算法：
 *    1.创建一个List，构建一个node节点
 *    2.push操作：如果数组中有栈，并且最后一个栈还没满，那么直接加入最后一个栈即可。如果数组中没有栈或者最后一个栈满了，那么在后面新加一个栈
 *    3.pop操作：pop操作需要符合后进先出的特点，所以要从最后一个栈中弹出元素，如果弹出栈空，那么删除该栈。
 *    4.popAt操作：找到置顶索引的栈,如果没有栈，那么返回-1，否则返回栈顶元素，如果pop之后该栈大小为0，那么删除该栈，后面的栈往前移动一位

### 代码

```java
class StackOfPlates {
    List<ListNode> list;
    private int cap;
    public StackOfPlates(int cap) {
        this.cap = cap;
        list = new ArrayList<>();
    }

    public void push(int val) {
        ListNode s = new ListNode(val);
        if (cap > 0) {
            if (list.size() != 0 && list.get(list.size() - 1).val < cap) {
                ListNode head = list.get(list.size() - 1);
                s.next = head.next;
                head.next = s;
                head.val++;
            } else {
                ListNode head = new ListNode(1);
                head.next = s;
                list.add(head);
            }
        }

    }

    public int pop() {
        return popAt(list.size() - 1);
    }

    public int popAt(int index) {
        if (list.size() <= 0 || list.size() <= index) {
            return -1;
        }
        ListNode head = list.get(index);
        int temp = head.next.val;
        head.next = head.next.next;
        head.val--;
        if (head.val == 0) {
            list.remove(index);
        }
        return temp;
    }
    private static class ListNode{
        int val;
        ListNode next;
        public ListNode(int val) {
            this.val = val;
        }
    }
}
/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates obj = new StackOfPlates(cap);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAt(index);
 */
```