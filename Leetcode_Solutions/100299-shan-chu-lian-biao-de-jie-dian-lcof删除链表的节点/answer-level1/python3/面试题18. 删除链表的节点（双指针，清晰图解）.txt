#### 解题思路：

> 删除值为 `val` 的节点可分为两步：定位节点、修改引用。

1. **定位节点：** 遍历链表，直到 `head.val == val` 时跳出，即可定位目标节点。
2. **修改引用：** 设节点 `cur` 的前驱节点为 `pre` ，后继节点为 `cur.next` ；则执行 `pre.next = cur.next` ，即可实现删除 `cur` 节点。

![Picture0.png](https://pic.leetcode-cn.com/0091d27673ec013c5557c7f9e7c731d3437f0ce655439269a6e24ce501235e4b-Picture0.png){:width=450}

##### 算法流程：

1. **特例处理：** 当应删除头节点 `head` 时，直接返回 `head.next` 即可。
2. **初始化：** `pre = head` , `cur = head.next` 。 
3. **定位节点：** 当 `cur` 为空 **或** `cur` 节点值等于 `val` 时跳出。
   1. 保存当前节点索引，即 `pre = cur` 。
   2. 遍历下一节点，即 `cur = cur.next` 。
3. **删除节点：** 若 `cur` 指向某节点，则执行 `pre.next = cur.next` 。（若 `cur` 指向 $null$ ，代表链表中不包含值为 `val` 的节点。
4. **返回值：** 返回链表头部节点 `head` 即可。

<![Picture1.png](https://pic.leetcode-cn.com/5d9fab71127c5ad3f0cf26bef0592a9df8de32663d4b9267cfe677a52d845234-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/4aa5819dd662aff2e17d0979c53dbf0c84174a67199ce2a12f0bc80bbfeeb342-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/1fd00f7f756687109b06a3a43871da1f5b0f5972673bfb0d5af1d4119774f372-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/b221899d92f9dfaf2f214d6e2f3c303d731821c40225e9b839ec0ff6ee687547-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/a14390e81c93812a552168b00c9ae22ee17426b02a561775354b0b9295f0fd90-Picture5.png)>

##### 复杂度分析：

- **时间复杂度 $O(N)$ ：** $N$ 为链表长度，删除操作平均需循环 $N/2$ 次，最差 $N$ 次。 
- **空间复杂度 $O(1)$ ：** `cur`, `pre` 占用常数大小额外空间。

#### 代码：

```python []
class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head.val == val: return head.next
        pre, cur = head, head.next
        while cur and cur.val != val:
            pre, cur = cur, cur.next
        if cur: pre.next = cur.next
        return head
```

```java []
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if(head.val == val) return head.next;
        ListNode pre = head, cur = head.next;
        while(cur != null && cur.val != val) {
            pre = cur;
            cur = cur.next;
        }
        if(cur != null) pre.next = cur.next;
        return head;
    }
}
```