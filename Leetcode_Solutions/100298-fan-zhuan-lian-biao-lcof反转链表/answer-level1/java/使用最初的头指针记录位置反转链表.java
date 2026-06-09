### 解题思路
此处撰写解题思路
##### 初始：
![image.png](https://pic.leetcode-cn.com/c391c4e0c6d9d52db372095a323ca05ae3fcec8cc81781e18ca9f0299eb63948-image.png)

##### 第一步
![image.png](https://pic.leetcode-cn.com/f1a8019b8f247729975ecd841897dd09e3b33b796cb1910e3d04d2a80d9a9e01-image.png)

##### 迭代到save.next == null
![image.png](https://pic.leetcode-cn.com/e31b8a68dd50382dd467c84c2371089d00dd749aff2d4164be584918d5259e93-image.png)
![image.png](https://pic.leetcode-cn.com/04d908f03baa6a0ad69f0117be62fdc1be0a0987a47708470787035753f6f723-image.png)

##### save指向target，删除环边
![image.png](https://pic.leetcode-cn.com/7b2e7457329335349b2499af0b4812d62657d62dccc1c1f33eadc707ae568258-image.png)

##### 返回save

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
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next == null)
            return head;
        ListNode target = head;
        ListNode save = target.next;
        while(save.next != null) {
            head.next = save.next;
            save.next = target;
            target = save;
            save = head.next;
        }
        save.next = target;
        head.next = null;
        return save;
    }
}
```