思路：一般而言，链表都是从头读到尾的，题目要求我们从尾到头打印链表，这种逆序的操作很显然可以考虑使用栈。

一种方式就是显式使用栈，相信这一点大家都会。

另一种方式可以借助递归，在系统栈中完成相关的操作，这里“打印”输出的位置是在递归方法返回以后，类似于“回溯算法”中“状态重置”的位置。

### 方法一： 使用递归完成逆序输出操作

注意下面代码中执行相关操作的位置。

**参考代码 1**：

```Java []
import java.util.ArrayList;
import java.util.List;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class Solution {

    public int[] reversePrint(ListNode head) {
        if (head == null) {
            return new int[0];
        }

        List<Integer> res = new ArrayList<>();
        printListFromTailToHead(head, res);

        // 这里代码有点长，但做的事情只是把 res 转到 int[]
        int size = res.size();
        int[] resArray = new int[size];
        for (int i = 0; i < size; i++) {
            resArray[i] = res.get(i);
        }
        return resArray;
    }

    private void printListFromTailToHead(ListNode node, List<Integer> res) {
        if (node == null) {
            return;
        }

        // 如果有后继结点，就一直递归下去
        if (node.next != null) {
            printListFromTailToHead(node.next, res);
        }
        // 重点：在递归返回的时候把当前结点的值添加到结果列表中
        res.add(node.val);
    }
}
```
```Python []
from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if head == None:
            return []

        res = []
        self.helper(head, res)
        return res

    def helper(self, node, res):
        if node is None:
            return
        # 应该先判断下一个结点是否为空，如果不为空，则递归调用，在回溯的时候，才添加到结果中
        if node.next:
            self.helper(node.next, res)
        # 回溯时添加
        res.append(node.val)
```


**复杂度分析**：

+ 时间复杂度：$O(N)$，这里 $N$ 为链表的长度；
+ 空间复杂度：$O(N)$，系统栈需要 $N$ 长度的空间。



### 方法二：非递归（使用栈）

说明：栈作为一种缓存结构，用于逆序操作是很自然的。

**参考代码 2**：

```Java []
import java.util.ArrayDeque;
import java.util.Deque;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class Solution {

    public int[] reversePrint(ListNode head) {
        if (head == null) {
            return new int[0];
        }

        // Java 在 Stack 类的文档里建议使用 Deque
        Deque<Integer> stack = new ArrayDeque<>();
        ListNode curNode = head;
        while (curNode != null) {
            stack.addLast(curNode.val);
            curNode = curNode.next;
        }


        int size = stack.size();
        int[] res = new int[size];
        for (int i = 0; i < size; i++) {
            // 这里因为提前读取了 size，因此在 stack 发送 pop 的时候，
            // 不必检测 stack 是否为空
            res[i] = stack.removeLast();
        }
        return res;
    }
}
```
```Python []
from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        p = head
        stack = []
        while p:
            stack.append(p.val)
            p = p.next
        return stack[::-1]
```



**复杂度分析**：

+ 时间复杂度：$O(N)$，这里 $N$ 为链表的长度；
+ 空间复杂度：$O(N)$，显示使用栈也需要 $N$ 长度的空间。