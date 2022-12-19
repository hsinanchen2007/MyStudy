
```
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] result = new ListNode[k];
        if (root == null) {
            return result;
        }
        
        // 计算长度
        ListNode p = root;
        int total = 0;
        while (p != null) {
            ++total;
            p = p.next;
        }
        
        // 统计每个分段的数量，并分组
        int baseCnt = total / k;
        int addCnt = total % k;
        p = root;
        ListNode pre = root;
        for (int i = 0; i < k; i++) {
            int sum = baseCnt + ((--addCnt >= 0) ? 1 : 0);
            result[i] = p;
            while (--sum >= 0) {
                pre = p;
                p = p.next;
            }
            pre.next = null;
        }
        
        return result;
    }
}
```



