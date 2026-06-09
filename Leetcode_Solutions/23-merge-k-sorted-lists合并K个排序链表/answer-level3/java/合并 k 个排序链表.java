典型的**归并分治思想，自底向上**，依次合并(可结合归并排序理解，将每个链表理解成排序的值)

分治法：
1. 分解原问题为若干个子问题，这些子问题是原问题的规模较小的实例；
2. 递归求解这些子问题，如果规模足够小，则直接求解；
3. 合并这些子问题的解即可得到原问题的解。

**代码**：
```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;
        return solve(lists, 0, lists.length-1);
    }
    
    private ListNode solve(ListNode[] arr, int left, int right){
        if(left == right) return arr[left];

        int mid = (left + right) >> 1; 
        ListNode lNode = solve(arr, left, mid);   
        ListNode rNode = solve(arr, mid+1, right); 

        return merge(lNode, rNode);
    }
    
    private ListNode merge(ListNode node1, ListNode node2){
        if(node1 == null) return node2;
        if(node2 == null) return node1;
        
        if(node1.val < node2.val){
            node1.next = merge(node1.next, node2);
            return node1;
        }else{
            node2.next = merge(node1, node2.next);
            return node2;
        }
    }
}
```
**时间复杂度**：O(nlogn)