![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/f2e1fcd5bc5bb804322262841132bab64f9702449c6448f5b1abb444d1073f36-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

### 代码

```java
class Solution {
    public int[] reversePrint(ListNode head) {
        int total = 0;
        ListNode tmp = head;
        while (tmp != null) {
            total++;
            tmp = tmp.next;
        }
        int[] res = new int[total];
        for (int i = total - 1; i >= 0; i--) {
            res[i] = head.val;
            head = head.next;
        }
        return res;
    }
}
```