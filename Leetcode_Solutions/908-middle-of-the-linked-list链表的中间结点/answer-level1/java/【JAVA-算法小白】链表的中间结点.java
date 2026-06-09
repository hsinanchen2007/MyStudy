### 解题思路
如注解中代码所示，自己用的Vector当动态数组，好处是取数据方便O（1），唯一不好的是需要遍历整个ListNode太暴力。

### 代码

```java
import java.util.Vector;
 /**
 *第一想法是暴力遍历找到长度，再次遍历，若长度%2==0取长度/2+1，否则取长度/2元素
 *第二个想法是将链表中元素放进数组，但是不知长度，若是超级长，需要动态扩容
 *Vector 类实现了一个动态数组。和 ArrayList 很相似，但是两者是不同的：
 *Vector 是同步访问的。
 *Vector 包含了许多传统的方法，这些方法不属于集合框架。
 *Vector 主要用在事先不知道数组的大小，或者只是需要一个可以改变大小的数组的情况。
 *
 */
class Solution {
    public ListNode middleNode(ListNode head)
    {
        Vector<ListNode> array=new Vector<>(10,2);
        while (head!=null)
        {
            array.add(head);
            head=head.next;
        }
        int size=array.size();
        return array.get(size/2);
    }
}
```