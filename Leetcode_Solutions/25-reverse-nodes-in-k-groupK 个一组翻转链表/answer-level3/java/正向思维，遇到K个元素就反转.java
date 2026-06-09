### 解题思路
虽然本算法不是最快的，但是是非常符合人的正向思考思路的
依次遍历，当凑够5个元素的时候，就反转一波然后开始下一个循环

当然，最正宗的解法是计数器+指针，依次遍历，每次都把后一个元素拎出来放到前一个元素之前
这种解法稍后给出
当然，这种解法最后要处理多余的元素，因为多余的元素不需要反转，所以可能还需要一个转回来的过程

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
    // 这个函数是用来反向构建关系的
    private ListNode reverseContainer(List<ListNode> container) {
        Collections.reverse(container);
        container.get(container.size() - 1).next = null;
        ListNode parent = new ListNode(-1);
        ListNode temp = parent;
        for (ListNode e : container) {
            temp.next = e;
            temp = temp.next;
        }
        return parent.next;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null){
            return head;
        }
        // 依次往下遍历
        // 只要下边还有节点就不停
        ListNode node = head;
        ListNode lastNode = null;
        ListNode newRoot = null;
        List<ListNode> container = new LinkedList<>();
        while (node != null) {
            // 如果满了就反转一波
            if (container.size() == k) {
                // 反转并构建指向关系，返回一个局部根
                ListNode e = reverseContainer(container);

                // 创建一个新的根
                if (newRoot == null) {
                    newRoot = e;
                }
                // 如果没有赋值过上一个循环的最后节点
                // 那么上一个循环的尾要指向本循环的头
                if (lastNode != null) {
                    lastNode.next = e;
                }

                // 更新本循环的尾部节点
                lastNode = container.get(container.size() - 1);

                // 清空容器
                container.clear();
            }
            // 处理逻辑
            // 往容器里面填充
            container.add(node);
            node = node.next;
        }

        // 处理容器里面剩下的
        if (lastNode == null) {
            // 证明没有反转过
            // 有两种可能
            // 第一种栈少于k
            // 第二种栈==k(刚好满)
            if (container.size() < k) {
                // 结尾置为null
                container.get(container.size() - 1).next = null;
                return container.get(0);
            } else if (container.size() == k) {
                return reverseContainer(container);
            } else {
                return null;
            }
        } else {
            // 结尾置为null
            if (container.size() < k) {
                container.get(container.size() - 1).next = null;
                lastNode.next = container.get(0);
            } else if (container.size() == k) {
                ListNode e = reverseContainer(container);
                lastNode.next = e;
            }
            return newRoot;
        }
    }
}
```