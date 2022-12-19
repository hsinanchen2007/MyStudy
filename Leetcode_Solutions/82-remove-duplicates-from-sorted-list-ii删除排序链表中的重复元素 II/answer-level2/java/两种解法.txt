方法一 ：
两次遍历，第一次遍历获取重复的值，第二次遍历删除重复的节点
```
  public ListNode deleteDuplicates(ListNode head) {
		  if(head == null || head.next == null){
			  return head;
		  }
		  ListNode point = head;
		  Set set = new HashSet<Integer>();
		  Set setDup = new HashSet<Integer>();
		  while(point != null){
			  if(set.contains(point.val)){
				  setDup.add(point.val);
			  }else{
				  set.add(point.val);
			  }
			  point = point.next;
		  }
		  
		  ListNode prehead = new ListNode(-1);
		  prehead.next = head;
		  point = prehead;
		  while(point.next != null){
			  // 删除重复节点
			  while(setDup.contains(point.next.val)){
				  point.next = point.next.next;
			  }
			  point = point.next;
		  }
		  return prehead.next; 
	  }
```

方法二：
一次遍历，直接删除，这里需要参考，题83的解法
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/solution/zhi-jie-shan-chu-by-xun-shui-de-yu-7/
```
public ListNode deleteDuplicates2(ListNode head) {
        if(head == null || head.next == null){
	        	return head;
	        }
	        ListNode pre = new ListNode(head.val-1);
	    	pre.next = head;
	    	ListNode point = pre;
	    	
	    	boolean dup = false;
	    	while(point != null && point.next!=null && point.next.next != null){
	    		// 直接删除重复节点， 如2->2->3，此处会删除第二个值为2的节点
	    		while(point.next!=null && point.next.next!=null &&point.next.val == point.next.next.val ){
	    			point.next = point.next.next;
	    			dup = true;
	    		}
	    		if(dup){
	    			//发生了重复则  删除重复中剩余的第一个节点
		    		point.next = point.next.next;
		    		dup = false;
	    		}else{
	    			point = point.next;
	    		}
	    	}
	    	return pre.next;
	}
```

