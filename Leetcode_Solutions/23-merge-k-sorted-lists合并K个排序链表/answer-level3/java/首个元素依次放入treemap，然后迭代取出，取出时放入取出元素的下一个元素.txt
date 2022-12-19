
执行结果：
通过
显示详情
执行用时 :
17 ms
, 在所有 Java 提交中击败了
47.13%
的用户
内存消耗 :
38.3 MB
, 在所有 Java 提交中击败了
96.36%
的用户
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0)return null;
       
        Map<Integer,Set<ListNode>> map = new TreeMap<Integer,Set<ListNode>>();
        
        ListNode res = new ListNode(0);
        ListNode temp = res;
         
        for(int i=0; i<lists.length; i++){
            ListNode no = lists[i];
            if(no!=null){
               putNode2Map(map,no);
            }
        }  
        //System.out.println(map.size());
        
        while(true){
            if(map.size()==0)break;
            Map.Entry<Integer,Set<ListNode>> entry = map.entrySet().iterator().next();
            Integer key = entry.getKey();
            Set<ListNode> set = entry.getValue();
            
            List<ListNode> node2add=new ArrayList<ListNode>();
            for(ListNode no:set){
                temp.next = no;
                temp = no;
                
                if(no.next!=null){
                    node2add.add(no.next);
                }
            }
            map.remove(key);
            for(ListNode no:node2add){
                putNode2Map(map,no);
            }
        }
        return res.next;
    }
    
    private void putNode2Map(Map<Integer,Set<ListNode>> map,ListNode no){
         if(map.get(no.val)==null){
            Set<ListNode> set = new HashSet<ListNode>();
            map.put(no.val,set);
        }
        map.get(no.val).add(no);
    }
}
```
