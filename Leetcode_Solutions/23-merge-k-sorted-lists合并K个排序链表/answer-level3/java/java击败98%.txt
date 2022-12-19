### 解题思路
分治

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
    	if(lists.length==0) {
    		return null;
    	}else if(lists.length==1) {
    		return lists[0];
    	}else {
    		int l=lists.length/2;
    		int length=lists.length;
    		while(l>=1) {
        		for(int i=0;i<l;i++) {
        			mergeTwoLists(lists,i,length-i-1);
        		}
                if(length%2==1) {
        			mergeTwoLists(lists,0,length/2);
        		}
        		l=l/2;
        		length=length/2;
    		}

    		return lists[0];
    	}
    }
	
	public static   void mergeTwoLists(ListNode[] lists,int i,int j) {
		ListNode l1=lists[i];
		ListNode l2=lists[j];
		if(l1!=null||l2!=null) {
			ListNode root=new ListNode(0);
			ListNode near=new ListNode(0);
			near=root;
			while(l1!=null&&l2!=null) {
				if(l1.val<l2.val) {
					near.next=l1;
					l1=l1.next;
					near=near.next;
				}else {
					near.next=l2;
					l2=l2.next;
					near=near.next;
				}
			}
			if(l1==null) {
				near.next=l2;
			}
			if(l2==null) {
				near.next=l1;
			}
			lists[i]=root.next;
		}
		
    }
}
```