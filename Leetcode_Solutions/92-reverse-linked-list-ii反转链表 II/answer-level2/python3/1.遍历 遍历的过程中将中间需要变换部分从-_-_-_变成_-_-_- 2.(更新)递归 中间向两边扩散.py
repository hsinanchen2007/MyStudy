# # 1.迭代
# **思路**:见标题 另外需要注意什么时候切断原本直接相联的两个ListNode的联系
# ```
class Solution:
	def reverseBetween(self,head,m,n):
		dummy=ListNode(0) #创建一个哑值
		dummy.next=head
		do=dummy #do是用来遍历链表的
		ind=0
		while ind<m-1:
			do=do.next
			ind+=1
		le=do #左边无需变换的节点们的尾巴
		t_tail,t_head=le.next,le.next
		le.next=None #切断左边无需变化部分和中间需要变化部分的联系
		t_next=t_tail.next
		for _ in range(n-m): #将中间的部分从->->->转化为<-<-<-
			t=t_next.next
			t_next.next=t_head
			t_head=t_next
			t_next=t
		le.next=t_head #连接左边不需要变换的部分和中间已经变换完成的部分
		t_tail.next=t_next #这里的t_next表示的是右边不需要变换部分的头
		return dummy.next #不直接head的原因是m=1的情况直接return head是错误的
# ```
# # 2.递归
# **思路**：根本思想是将需要变换的部分分成两段 从中间开始扩散 比如说:1 2 3 4 5的交换就首先是(2,4)然后是(1,5) 前一个元素的遍历(2-1)通过ListNode.next实现 而后一个元素的遍历(4-5) 通过递归的归实现
# **注意**：本来没怎么考虑递归的 但是看到官方题解和labuladong大佬题解的标题就有点坐不住了 还没看他们的解法也不知道想法是不是一样的(总之他们肯定比我写得好) 本人菜鸡 以下代码仅供参考 还请大家多多指教
# ```
class Solution:
	def reverseBetween(self,head,m,n):
		odd=True if not (m+n)%2 else False #中间需要变换的部分的长度是奇数->True 反之->False
		mid=(m+n)//2 if odd else ((m+n)//2)+1 #这个变量是🚩行用到的 得先稍微看一下那部分的逻辑
		#假如说需要翻转1,2,3,4,5 那么mid就是3(val2的索引 设索引从1开始) 也就是说我们第一次的交换是2,4 第二次的交换是1,5
		#假如说需要翻转1,2,3,4 那么mid就是3(val3的索引) 也就是说我们第一次交换是2,3 第二次的交换是1,4
		dummy=ListNode(0) #创建一个哑值 方便处理最终结果
		dummy.next=head
		def helper(head,ind): #辅助函数 ind用来表示当前节点是原链表中的第几个节点
			if ind<m:
				helper(head.next,ind+1)
			elif ind<mid: #这边是需要转换的部分 🚩
				tmp=helper(head.next,ind+1)
				head.val,tmp.val=tmp.val,head.val
				return tmp.next
			else:
				if odd: #注意分清楚是odd还是even 两种的第一个归是不一样的
					return head.next
				return head
		helper(head,1)
		return dummy.next
# ```

