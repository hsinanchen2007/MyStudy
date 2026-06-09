
# 利用Set
这题的要求是去除重复的元素，既然是去重，那么有一种数据结构就可以派上用场。   
Set，我们将链表中的元素遍历一遍，放到Set中，这样就自动去重了。   
![1571361212.jpg](https://pic.leetcode-cn.com/01c90719debd59bffdd7e4df5ee6c90547f008a35f1bd003524e7847d3c79e25-1571361212.jpg)

需要注意，Set存入进去的时候是不保证顺序的，如果要让Set中元素按照插入的顺序存放，可以使用LinkedHashSet这样的类来完成。
```java
class Solution {
	public ListNode deleteDuplicates(ListNode head) {
		LinkedHashSet s = new LinkedHashSet();
		//遍历链表，将元素放入LinkedHashSet
		//此时的s变量中保存的就是去重的元素了
		
		//遍历 s，将元素取出
		int[] arr = 。。。。
		//遍历链表，修改链表中元素的值
    }
}
```
上面我没有做具体实现，只写了一些注释。因为上面那种实现方式在面试的时候是无法通过的，如果你这么写了，   
面试官会继续追问，如何不利用API自己去重。   
面试的时候你可以选说出上面的那种实现方式，虽然不是最优解，但可以实现要求。上面那种方式实现起来很简单，   
先把最简单的实现方式说出来，缓解一下情绪也是不错的，等面试官继续追问后，再说出更优解。   
所以上面那个代码我就不实现啦，感兴趣的同学们可以自行实现一下，下面我们来说说如何不利用库函数的方式，一遍遍历完成去重。   


# 一次遍历解法
一次遍历的方式，需要用a和b两个指针，然后b指针不断往前走，如果a指针和b指针的元素相等则啥都不做；   
如果a指针和b指针的元素不等，则a指针也往前走一位，并将b指针的值赋给a指针。   
空说不好理解，下面是动态实例图：   
![640.gif](https://pic.leetcode-cn.com/fc98958adefcce2eb53fad217ae84abd62a7762859655897d1d9fcc9dae934be-640.gif)


代码实现代码如下：
```java []
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
		if(head==null || head.next==null) {
			return head;
		}
		ListNode i = head;
		ListNode j = head;
		while(j!=null) {
			//如果i不等于j，则i前进一位，然后将j的值赋给i
			//请配合动画演示理解
			if(i.val!=j.val) {
				i = i.next;
				i.val = j.val;
			}
			//不管i是否等于j，j每次都前进一位
			j = j.next;
		}
		i.next = null;
		return head;
    }
}
```
```python []
class Solution(object):
	def deleteDuplicates(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		if not (head and head.next):
			return head
		i,j = head,head
		while j:
			# 如果i不等于j，则i前进一位，然后将j的值赋给i
			# 请配合动画演示理解
			if i.val!=j.val:
				i = i.next
				i.val = j.val
			# 不管i是否等于j，j每次都前进一位
			j = j.next
		i.next = None
		return head
```

(全文完)   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)