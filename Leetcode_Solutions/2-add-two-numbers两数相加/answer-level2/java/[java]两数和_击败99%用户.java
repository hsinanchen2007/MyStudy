### 解题思路
see more in the video;
![两数之和.jpg](https://pic.leetcode-cn.com/d50bb97c88bbd5ea2a5cb1249b6e6b14b77ac3b3f8696ea016e1a9c92ac3c6c5-%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.jpg)
![...ecode_2_improved.mp4](5f1a8baa-bb83-456d-bf39-769e892a69ba)

### 代码

```java
 class Solution
{
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) 
	{       
		ListNode l1_cur = l1;
		ListNode l2_cur = l2;
		ListNode l3 = new ListNode(0);
		ListNode l3_cur = null;
		int count1 = 0;
		int count2 = 0;
		
		while(l1_cur !=null)   // 判断L1位数
		{
			count1 ++;
			l1_cur = l1_cur.next;
		}

		while(l2_cur !=null)   // 判断L2位数
		{
			count2 ++;
			l2_cur = l2_cur.next;
		}
			
		if(count1 > count2)
		{
			l2_cur = l2;
			int dif = count1 - count2;
			while(l2_cur.next !=null)   // travel to the last
			{
				l2_cur = l2_cur.next;
			}			
			
			while(dif != 0)
			{
				ListNode lNew = new ListNode(0);
				lNew.next = null;
				
				l2_cur.next = lNew;
				l2_cur = l2_cur.next;
				dif--;
			}
		}
		
		else if(count1 < count2)
		{
			l1_cur = l1;
			int dif = count2 - count1;
			while(l1_cur.next !=null)   // travel to the last
			{
				l1_cur = l1_cur.next;
			}			
			
			while(dif != 0)
			{
				ListNode lNew = new ListNode(0);
				lNew.next = null;
				
				l1_cur.next = lNew;
				l1_cur = l1_cur.next;
				dif--;
			}			
		}
		else
		{
			
		}
		//deal the equal listed
		{			
				l1_cur = l1;
				l2_cur =l2;
				l3_cur = l3;
				while(l1_cur != null && l2_cur != null)
				{
					int c = l1_cur.val+l2_cur.val;
					ListNode lNew = new ListNode(c);
					lNew.next = null;
					
					l3_cur.next  = lNew;
					l3_cur = l3_cur.next;

                    l1_cur = l1_cur.next;
					l2_cur = l2_cur.next;	
				}
				
				l3_cur = l3.next;  // >10 deal
				while(l3_cur != null)
				{
					if(l3_cur.val >= 10)
					{
						l3_cur.val -= 10;
						if(l3_cur.next != null)
						{
							
							l3_cur.next.val += 1;	
						}
						else
						{
							ListNode lNew = new ListNode(1);
							lNew.next = null;
							
							l3_cur.next = lNew;
							l3_cur = lNew;
						}
						
						l3_cur = l3_cur.next;
					}
					else
					{
						l3_cur = l3_cur.next;
					}
				}
				return l3.next;
			
		}		
		
	}	
}
```