用一个变量记录递归深度，到链表末的时候就知道数组长度，然后逆序赋值就行
```
class Solution {
    int[] ans;
    public int[] reversePrint(ListNode head) {
        return dfs(0,head);
    }
    int[] dfs(int depth,ListNode head){
        if(head ==null){
            // 到最后一个节点初始化数组
            return  new int[depth];
        }
        int[] ans = dfs(depth + 1,head.next);
        // 逆序记录
        ans[ans.length - depth - 1] = head.val;
        return ans;
    }
}
```
