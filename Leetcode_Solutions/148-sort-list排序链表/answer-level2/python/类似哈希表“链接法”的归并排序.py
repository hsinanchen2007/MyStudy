链表因为不具备数组随机访问这一特性。因此很多数组里设计遍历和交换的排序方法都不适用于链表排序，唯独归并排序相对合适一点，即使是这样，归并排序找链表中间这件事情，也要遍历。这道题的标准答案我认为是 [@Krahets](/u/jyd/) 编写的 [精选题解：Sort List （归并排序链表）](https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/) ，欢迎大家点击观看。

这道题要注意一点，题目要求：

> **常数级空间复杂度。**

因此所有递归实现的方法都是不符合要求的。所以这道题就当开阔视野，实际用到的方法和技巧并不常见。

+ 我个人认为掌握自顶向下（递归）实现的归并排序即可。

下面这个方法比较具有技巧性，借助了哈希表“链接法”的实现，可能编码上还有优化的空间，大家看一看就好了，我个人觉得不需要掌握。

（温馨提示：下面的幻灯片中，有几页上有较多的文字，可能需要您停留一下，可以点击右下角的后退 “|◀” 或者前进 “▶|” 按钮控制幻灯片的播放。）

<![148-1.png](https://pic.leetcode-cn.com/5dde7ef2dbf5dfc6ba492967ad90ae47c8b69912c933c6ff7fdd1b193df79a3a-148-1.png),![148-2.png](https://pic.leetcode-cn.com/c346cb3c15ca1573ad84812ebc7414ea15f603a77eaec8da8e65b49406d57c9b-148-2.png),![148-3.png](https://pic.leetcode-cn.com/6cba91ad06d27ba535ab7f5479ded87728ab6a443dbc6180aa999ca7205d2398-148-3.png),![148-4.png](https://pic.leetcode-cn.com/191596efb354dc1a20d5c2cc074a5849afd30a4524e2ebdc1f52453657cb5f8f-148-4.png),![148-5.png](https://pic.leetcode-cn.com/c31c4944662863515d3c8b2ba480c6d3d66edb1250514aa918afbf538a69bfc1-148-5.png),![148-6.png](https://pic.leetcode-cn.com/41707f28feeec83b718eb3402135d4184f90f4069372dbf54f6da5b86ad3376f-148-6.png),![148-7.png](https://pic.leetcode-cn.com/855652a477f968df5f59eaf66d6c61388d0e36abd5298d96d6bb02f1b0f49707-148-7.png),![148-8.png](https://pic.leetcode-cn.com/177b1e7f1e186062f06eb54abaa1a9a0c89899901d25f6ae851cb2cb47a15f19-148-8.png),![148-9.png](https://pic.leetcode-cn.com/261d0c730ba13d41aed5ea6b690c8b44a6d05d0de6f219f000c5df68ae5b43d6-148-9.png),![148-10.png](https://pic.leetcode-cn.com/d6eefcc333bd3362c60f32808b7fab93eec20c1c65cee6930d2c7cf0cae38748-148-10.png),![148-11.png](https://pic.leetcode-cn.com/c65fa18c769b01844170815abb245dc85a8d348924466cd301ce75b3dc888b09-148-11.png),![148-12.png](https://pic.leetcode-cn.com/05cfa4d484aabc6b57598602b5d0653784646b9c928b48fd5f19b36ea62b20d6-148-12.png),![148-13.png](https://pic.leetcode-cn.com/5ab524c4b1cdd9eded4c53d25c50b6dbd17c7ae9d070ec99eaed95afa12d0b39-148-13.png),![148-14.png](https://pic.leetcode-cn.com/849c0c08926d27356efd734be87f73e7a8dd86d8b4e74d6962962228652a685f-148-14.png),![148-15.png](https://pic.leetcode-cn.com/92858f3f9669b8c2f278029b715e2d467307a8a4fec93f67733d17b2676442c8-148-15.png),![148-16.png](https://pic.leetcode-cn.com/75ab2a5b498b86c2d99d753d3da59d324c4b183edadbea6f93e7af100da427b0-148-16.png),![148-17.png](https://pic.leetcode-cn.com/26a88cb6fab5285cc5e9b06d32e3e73e8b2b0b6eeadbb45b50d86a406701cf5c-148-17.png),![148-18.png](https://pic.leetcode-cn.com/6291f1d052621a96ef6d5ce0b4cb9a8c8f8cb48c766bcb7d0ffa9c0836a9ac6f-148-18.png),![148-19.png](https://pic.leetcode-cn.com/61fcc46a226ec29242dc14238e4a6495b48c5e9f4def7aafa79527dc6235f518-148-19.png),![148-20.png](https://pic.leetcode-cn.com/c965e5623aa846259a16dfb32a6eeb7be72412568efcc8791e49d26bd470ef66-148-20.png),![148-21.png](https://pic.leetcode-cn.com/af5ea17697e91188bb270ad6e1112a80f7fa92ad9e9fa7aaaef6055696ad77b7-148-21.png),![148-22.png](https://pic.leetcode-cn.com/58c1457d8f202fd3010b2761482645da71ac98b30d60844fcd1f596d2c470d7e-148-22.png),![LeetCode 第 148 题：“单链表”自底向上实现“归并排序”题解配图.png](https://pic.leetcode-cn.com/60298b1a71e739500b8ce112a35920e1205b5db2e9c526c51b5f68be2d8da0cf-LeetCode%20%E7%AC%AC%20148%20%E9%A2%98%EF%BC%9A%E2%80%9C%E5%8D%95%E9%93%BE%E8%A1%A8%E2%80%9D%E8%87%AA%E5%BA%95%E5%90%91%E4%B8%8A%E5%AE%9E%E7%8E%B0%E2%80%9C%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F%E2%80%9D%E9%A2%98%E8%A7%A3%E9%85%8D%E5%9B%BE.png),![148-24.png](https://pic.leetcode-cn.com/a2dc861706e5193ecfa52a5c28dc8032b1d0a48c8ad065d362e130bd2b9cc65e-148-24.png)>




**参考代码**：

```Java []
public class Solution {

    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        // 这里设置 64 ，是一个绰绰有余的数字，可以满足结点数量为 2^64 这么多的单链表的排序
        ListNode[] counter = new ListNode[64];
        ListNode curNode = head;
        // 遍历到的最大的 counter 数组的索引
        int maxIndex = 0;
        while (curNode != null) {
            // 先把当前元素暂存起来，马上我们就要把它放到 counter 数组合适的位置上
            ListNode carryNode = curNode;
            // curNode 指针马上后移，方便下次处理
            curNode = curNode.next;
            // 拿出的节点就和原来的链表没有关系了，我们在 counter 数组中完成排序，所以要切断它和原链表的关系
            carryNode.next = null;
            // 尝试从 counter 数组 0 号索引开始放置
            int i = 0;
            // 只要非空当前位置非空，就进行一次 merge，merge 以后尝试放到下一格，如果下一格非空就继续合并
            // 合并以后再尝试放到下一格，直到下一格为空，直接放在那个为空的下一格就好
            while (counter[i] != null) {
                ListNode newMergeNode = mergeTwoSortLinkedList(carryNode, counter[i]);
                counter[i] = null;
                i++;
                carryNode = newMergeNode;
            }
            // 遇到了空，就把 carryNode 放在数组的这个位置上
            counter[i] = carryNode;
            // 记录最多使用到 counter 数组的第几位，最后合并的时候要用上
            if (i > maxIndex) {
                maxIndex = i;
            }
        }
        // 遍历整个 count 数组，将它们全部归并，这个操作就和归并 n 个有序单链表是一样的了，我们这里采用两两归并
        // 还可以采用 LeetCode 第 23 题的办法完成这一步
        // 参考：https://liweiwei1419.github.io/leetcode-solution/leetcode-0023-merge-k-sorted-lists/
        ListNode res = null;
        for (int i = 0; i <= maxIndex; i++) {
            if (counter[i] != null) {
                res = mergeTwoSortLinkedList(res, counter[i]);
            }
        }
        return res;
    }

    /**
     * 归并两个已经排好序的单链表，是我们非常熟悉的操作了，可以递归完成，也可以穿针引线，这里我们递归完成
     *
     * @param list1 顺序存放的单链表1
     * @param list2 顺序存放的单链表2
     * @return 合并以后的单链表
     */
    private ListNode mergeTwoSortLinkedList(ListNode list1, ListNode list2) {
        ListNode dummyNode = new ListNode(-1);
        ListNode p1 = list1;
        ListNode p2 = list2;
        ListNode curNode = dummyNode;
        // 两者都不为空的时候，才有必要进行比较
        while (p1 != null && p2 != null) {
            if (p1.val < p2.val) {
                // 指针修改发生在这里
                curNode.next = p1;
                p1 = p1.next;
            } else {
                // 指针修改发生在这里
                curNode.next = p2;
                p2 = p2.next;
            }
            curNode = curNode.next;
        }
        // 跳出循环是因为 p1 == null 或者 p2 == null
        if (p1 == null) {
            curNode.next = p2;
        }
        if (p2 == null) {
            curNode.next = p1;
        }
        return dummyNode.next;
    }
}
```

下面补充 “自顶向下” 的 归并排序” 的写法，注意 3 种 Python 写法的不同之处。


```Java []
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }

    ListNode(int[] nums) {
        ListNode currNode = this;
        currNode.val = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currNode.next = new ListNode(nums[i]);
            currNode = currNode.next;
        }
    }

    @Override
    public String toString() {
        ListNode currNode = this;
        StringBuilder s = new StringBuilder();
        while (currNode != null) {
            s.append(currNode.val);
            s.append(" -> ");
            currNode = currNode.next;
        }
        s.append("NULL");
        return s.toString();
    }
}

// 分治法不符合要求：常数级空间复杂度

public class Solution {

    public ListNode sortList(ListNode head) {
        // 递归终止的条件，即满足下面条件就不用找中点，可以直接返回
        if (head == null || head.next == null) {
            return head;
        }
        // 使用归并排序、分治思想，先要找到链表的中间结点
        ListNode fast = head;
        ListNode slow = head;
        // 下面这段代码是找链表中间结点的一般做法
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        // 定义位于中间结点的下一个结点，从它那里将一个链表切开
        ListNode midNext = slow.next;
        // 这里一定要记得从中间切开，分割成两个链表
        slow.next = null;
        ListNode listNodeLeft = sortList(head);
        ListNode listNodeRight = sortList(midNext);
        // 合并两个已经排序的单链表，这是我们很熟悉的操作了
        return mergeOfTwoSortListNode(listNodeLeft, listNodeRight);
    }

    private ListNode mergeOfTwoSortListNode(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        if (l1.val < l2.val) {
            l1.next = mergeOfTwoSortListNode(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeOfTwoSortListNode(l1, l2.next);
            return l2;
        }
    }


    public static void main(String[] args) {
        int[] nums = new int[]{12, 10, 8, 9, 6, 5, 4, 3};
        ListNode head = new ListNode(nums);
        System.out.println(head);
        Solution solution = new Solution();
        ListNode sortList = solution.sortList(head);
        System.out.println(sortList);
    }
}
```
```python [-Python 代码 1]
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head

        # 找到中点
        slow = head
        fast = head
        # 使用这种方式，当结点个数为 2 个时候，slow 在左结点
        # 不会导致死循环
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        head2 = slow.next
        slow.next = None

        lnode = self.sortList(head)
        rnode = self.sortList(head2)

        return self.__merge_two_sorted_list(lnode, rnode)

    def __merge_two_sorted_list(self, head1, head2):
        if head1 is None:
            return head2
        if head2 is None:
            return head1

        if head1.val < head2.val:
            head1.next = self.__merge_two_sorted_list(head1.next, head2)
            return head1
        else:
            head2.next = self.__merge_two_sorted_list(head1, head2.next)
            return head2
```

```python [-Python 代码 2]
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# 这里有个小陷阱，如果遇到问题，不要着急，代码调试就好了

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        # 找到中点
        slow = head
        fast = head
        while fast and fast.next:
            # 这里要保存一下前一个指针
            p = slow
            slow = slow.next
            fast = fast.next.next

        p.next = None
        # print_node_list(head)
        # print_node_list(head2)
        lnode = self.sortList(head)
        rnode = self.sortList(slow)
        return self.__merge_two_sorted_list(lnode, rnode)

    def __merge_two_sorted_list(self, head1, head2):
        if head1 is None:
            return head2
        if head2 is None:
            return head1

        if head1.val < head2.val:
            head1.next = self.__merge_two_sorted_list(head1.next, head2)
            return head1
        else:
            head2.next = self.__merge_two_sorted_list(head1, head2.next)
            return head2


def create_node_list(arr):
    head = ListNode(arr[0])
    cur = head
    for i in range(1, len(arr)):
        cur.next = ListNode(arr[i])
        cur = cur.next
    return head


def print_node_list(head):
    while head:
        print(head.val, '->', end=' ')
        head = head.next
    print('NULL')


if __name__ == '__main__':
    arr = [4, 2, 1, 3]
    head = create_node_list(arr)
    print_node_list(head)

    solution = Solution()
    result = solution.sortList(head)
    print_node_list(result)
```


```python [-Python 代码 3]
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# 这里有个小陷阱，如果遇到问题，不要着急，代码调试就好了

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        # 玄机在这里，如果非要用 while fast and fast.next:
        # 让快指针先走一步，以避免死循环
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        new_head = slow.next
        slow.next = None

        lnode = self.sortList(head)
        rnode = self.sortList(new_head)
        return self.__merge_two_sorted_list(lnode, rnode)

    def __merge_two_sorted_list(self, head1, head2):
        if head1 is None:
            return head2
        if head2 is None:
            return head1

        if head1.val < head2.val:
            head1.next = self.__merge_two_sorted_list(head1.next, head2)
            return head1
        else:
            head2.next = self.__merge_two_sorted_list(head1, head2.next)
            return head2


def create_node_list(arr):
    head = ListNode(arr[0])
    cur = head
    for i in range(1, len(arr)):
        cur.next = ListNode(arr[i])
        cur = cur.next
    return head


def print_node_list(head):
    while head:
        print(head.val, '->', end=' ')
        head = head.next
    print('NULL')


if __name__ == '__main__':
    arr = [4, 2, 1, 3]
    head = create_node_list(arr)
    print_node_list(head)

    solution = Solution()
    result = solution.sortList(head)
    print_node_list(result)
```
