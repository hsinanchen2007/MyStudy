[24：两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

```python
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """        
        laste, pre = head, None
        while laste.next.next:
            temp = laste.next
            laste.next = pre
            pre = laste
            pre.next = temp.next                        
        #laste = pre
        return laste.next
```
上面的代码是不对的，但是我也记录下来，这是我思考的过程。
上面的代码是怎么得到的呢？
![链表-0007.png](https://pic.leetcode-cn.com/87ed08389c4033613c192d9aa85e3e02c0e79850d7c4d538a430977e9a0c64bf-%E9%93%BE%E8%A1%A8-0007.png)


----------------
```python
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        new,pre=head.next,None
        while new:
            a = new
            b = new.next
            new.next = pre
            #出错地方
            pre = head
            pre.next = b.next           
            new = b       
        return head.next
```
这个代码也是不对的！为什么？因为我们让`pre=head`，永远执行这条命令，也就是都指向`head`，也是不对的。我们需要一个动态变化的节点

-----------
正确的：
```python
class Solution(object):  
    def swapPairs(self, head):  
        """ 
        :type head: ListNode 
        :rtype: ListNode 
        """  
        if head == None:
            return head
        cur,cur.next = ListNode(0),head

        first =cur
        
        while cur.next and cur.next.next:
            n1 = cur.next
            n2 = n1.next
            nxt = n2.next
            
            n1.next = nxt
            n2.next = n1
            cur.next = n2
            
            cur = n1
        return first.next
```
图解释：
![链表-0008.png](https://pic.leetcode-cn.com/ea1f18123f32fc1bee015cb862726e4002ee0a4630bbfa85ca91ddf62a33f2e0-%E9%93%BE%E8%A1%A8-0008.png)


以上代码或是思路是迭代的过程。那么动态规划怎能弄呢？

`迭代`和`动态规划`他们之间的关系，我就多说几句。
动态规划一定是可以迭代实现的，那为什么还要动态规划呢？大家看上述代码或是我花的图（丑我知道，你别说~+！）可以观察出，迭代是在逐步进行中的，范围在一点一点的缩小，而且是从前往后进行的。比如，`f(n)=f(n-2)+f(n-2)`，这样的问题，为您`f(3)`是什么？迭代是：它是正向的过程

```python
f(3)=f(2)+f(1)=(f(1)+f(0))+f(1)
```
而动态规划呢？它是逆向的过程。

```python
f(0)=1
f(1)=1
f(2)=f(1)+f(0)
f(3)=f(2)+f(1)
```
可以感觉到吗？说的再直观点，就是`动态规划`必须先去后回，也就是舍不得孩子不好套狼。而`递归`呢，是一整块披萨，一点一点的吃。
那么我们现在尝试用`动态规划`解这一题。

**尊重知识产权：**
[递归实现](https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/pyhton3-die-dai-di-gui-jian-yao-shuo-ming-by-leaco/)
```python
class Solution(object):  
    def swapPairs(self, head):  
        """ 
        :type head: ListNode 
        :rtype: ListNode 
        """  
        #先下移后交换
        
        if not head or not head.next:
            return head
        # 下移两位  返回 值为两两交换后  两个节点中的前一个节点
        resultmp = self.swapPairs(head.next.next) 
        # 交换 当前两节点
        # 当前两节点
        A, B = head, head.next
        # 交换
        A.next, B.next = resultmp,A 
        
        # 返回 两两交换后  两个节点中的前一个节点
        return  B 
```
上面代码主要是先下移，再交换。那能不能先交换后下移呢？其实先交换再下移就是迭代呀。