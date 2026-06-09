
# 利用set求解
我们可以利用set这个数据结构来解决这道题，首先定义一个Set。   
之后遍历链表的节点，每遍历一个节点，就将这个节点的元素放入set中，如果这个链表没有环，那么最终遍历就结束了。   
如果链表有环的话，那么肯定有一个元素会被访问两次，当第二次访问这个元素的时候，set中就有记录了，这样就可以判断出链表是否有环了。   
   
![动画演示.gif](https://pic.leetcode-cn.com/d1a29692cd293258c00307c0ec7f1114558800f4b17f3a9a49fa7a8301cc5e7b-%E5%8A%A8%E7%94%BB%E6%BC%94%E7%A4%BA.gif)

代码实现
```java []
public class Solution {
    public boolean hasCycle(ListNode head) {
        Set s = new HashSet();
        //定义一个set，然后不断遍历
        while(head!=null) {
        	//只要某个节点在set中出现过，说明遍历到重复元素了
            if(s.contains(head)) {
                return true;
            }
            s.add(head);
            head = head.next;
        }
        return false;
    }
}
```
```python []
class Solution(object):
    def hasCycle(self, head):
        #定义一个set，然后不断遍历链表
        s = set()
        while head:
            #如果某个节点在set中，说明遍历到重复元素了，也就是有环
            if head in s:
                return True
            s.add(head)
            head = head.next
        return False
```
   
   
   
# 快慢指针解法
假设有个圆形的操场，操场上有a和b两个人，a和b最开始的时候是站在一起的     
![1571476513(1).jpg](https://pic.leetcode-cn.com/1f058ad70e9c0fbc288dee4dccccc389098ebb1a3fb21540fb2c159a3e3650be-1571476513\(1\).jpg)
假设b的速度是a的一倍，b不停的跑把a甩在身后了     
![1571476520(1).jpg](https://pic.leetcode-cn.com/de27b50090ce6aeeac913f97584cb446d8f24b9e550a05f79831473500836865-1571476520\(1\).jpg) 
b跑了N圈之后，终于追上a了   
![1571476526(1).jpg](https://pic.leetcode-cn.com/c658db0eef5b7668b265bc8d1a82347a38d83472ee643b828ac4eddc06e56574-1571476526\(1\).jpg)
   
按照这个思路，我们可以假设有a和b两个指针，一个慢一个快，如果链表是有环状的，那么走的快的那个指针迟早会跟慢指针重合的
![快慢指针动画演示.gif](https://pic.leetcode-cn.com/3accd61508b1f33ea00e3fedbaaf598122eaec2f8c47b4d7ea2485c21f37f644-%E5%BF%AB%E6%85%A2%E6%8C%87%E9%92%88%E5%8A%A8%E7%94%BB%E6%BC%94%E7%A4%BA.gif)

代码实现
```java []
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null || head.next==null) {
            return false;
        }
        //定义两个指针i和j，i是慢指针，j是快指针
        ListNode i = head;
        ListNode j = head.next;
        while(j!=null && j.next!=null) {
            if(i==j) {
                return true;
            }
            //i每次走一步，j每次走两步
            i = i.next;
            j = j.next.next;
        }
        return false;
    }
}
```
```python []
class Solution(object):
	def hasCycle(self, head):
		"""
		:type head: ListNode
		:rtype: bool
		"""
		if not (head and head.next):
			return False
		#定义两个指针i和j，i为慢指针，j为快指针
		i,j = head,head.next
		while j and j.next:
			if i==j:
				return True
			# i每次走一步，j每次走两步
			i,j = i.next, j.next.next
		return False
```

(全文完)   
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)