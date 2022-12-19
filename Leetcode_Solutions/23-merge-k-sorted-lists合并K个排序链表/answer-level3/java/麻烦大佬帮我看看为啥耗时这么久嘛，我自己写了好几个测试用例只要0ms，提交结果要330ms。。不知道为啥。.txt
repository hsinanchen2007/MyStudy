```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
    	int pos = 0;
    	ListNode result = new ListNode(0);
    	ListNode head = result;
    	
    	for(int i = 0; i < lists.length; i++)
    	{
    		pos = i;
    		while(lists[i] != null)
    		{
    			int temp = lists[i].val;
    			for(int j = i +1; j < lists.length; j++)
    			{
    				if(lists[j]!=null)
    				{
    					if(lists[j].val < temp)
    					{
    						pos = j;
    						temp = lists[j].val;
    					}
    				}else
    				{
    					continue;
    				}
    			}
    			System.out.println(lists[pos].val);
    			result.next  = new ListNode(lists[pos].val);//把最小值插入到结果
    			result = result.next;//结果的链表向后移动
    			lists[pos] = lists[pos].next;//最小值的链表向后移动
    			pos = i;
    		}
    	}
    	
    	
 		return head.next;
    }
    
    
}
```
思路就是比较每一个链表的第一个元素，找到最小的，记下是第几个链表，然后插入到结果链表中，并把最小那个链表向后移动一个。然后循环。
