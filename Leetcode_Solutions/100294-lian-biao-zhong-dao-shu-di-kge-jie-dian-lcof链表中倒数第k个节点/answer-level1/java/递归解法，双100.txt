

```
class Solution {
    Integer len=null; 
    public ListNode getKthFromEnd(ListNode head, int k) {
            return getNode(head,k,1);
    }
    ListNode getNode(ListNode node,int k,int d){
        ListNode res;
        if(node.next==null){len=d;res= null;}//走到底时计算长度
        else  res= getNode(node.next,k,d+1); //dfs
         
        if(len!=null&&k==len-d+1)return node; //回溯时观察该节点是否是倒数第k个点
       //如果是则返回该节点
        else return res; //否则返回dfs结果
        

    }
}
```
