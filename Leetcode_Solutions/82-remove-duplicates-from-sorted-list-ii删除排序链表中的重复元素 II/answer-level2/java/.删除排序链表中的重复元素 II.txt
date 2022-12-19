### 解题思路
应该没有人比我的更慢，空间复杂度更高了吧，用了hashmap+list

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode result=new ListNode(0);
        ListNode temp=result;
        HashMap<Integer,Integer> map=new HashMap<>();
        while(head!=null){
            int num=head.val;
            head=head.next;
            if(map.containsKey(num)){
                int count=map.get(num)+1;
                map.put(num,count);
            }else{
                map.put(num,1);
            }
        }//while
        Set<Integer> set=map.keySet();
        List<Integer> list=new ArrayList<Integer>();
        for(Integer i:set){
            if(map.get(i)==1){
               list.add(i);
            }
        }
        //集合排序
        Collections.sort(list);
        for(Integer i:list){
            ListNode node=new ListNode(i);
            temp.next=node;
            temp=node;
        }
        return result.next;
    }
}
```