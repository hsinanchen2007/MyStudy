```
public class Solution {
    public void DeleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```

[微软-内推]（北京上海苏州无锡）大量职位招人，长期有效 https://leetcode-cn.com/circle/article/Cj79fP/