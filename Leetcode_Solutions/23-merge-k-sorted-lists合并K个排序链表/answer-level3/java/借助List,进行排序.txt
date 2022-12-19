### 解题思路
将所有ListNode添加至List
List排序
List节点next:pq.get(i).next=pq.get(i+1);

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
    public ListNode mergeKLists(ListNode[] lists) {
       List<ListNode> pq = new LinkedList<>();
    	for(int i=0;i<lists.length;i++) {
    		ListNode temp = lists[i];
    		while(temp!=null) {
    			pq.add(temp);
    			temp=temp.next;
    		}
    	}
        if(pq.size()==0){
            return null;
        }
    	Collections.sort(pq,(a,b) -> a.val-b.val);
    	for(int i=0;i<pq.size()-1;i++) {
    		pq.get(i).next=pq.get(i+1);
    	}
        return pq.get(0);
    }
}
```