### 1.循环链表法
- 首先说下我写的这个链表法因为超时并没有跑通oj,思路是正确的,给大家提供一个解题的思路
- 我们需要创建一个循环链表,每次遍历时设定两个指针,当遍历到第m个节点时,我们将这个节点删除掉,并维持好链表不让其断开
- 下次遍历从上一次的开始数m个节点,继续删除,直到链表中存在一个节点
### 代码
```
class Node(object):
    def __init__(self,data):
        self.val = data
        self.next = None
class Solution(object):

    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        head = Node(0)
        temp = head
        for i in range(1,n):
            temp.next = Node(i)
            temp = temp.next
        temp.next = head

        while temp.next != temp:
            for _ in range(m-1):
                head = head.next
                temp = temp.next
            head = head.next
            temp.next = head
        return temp.val


        
```
### 数学法
![image.png](https://pic.leetcode-cn.com/8822b7f938bc9c9a0f6fefb8904d7e63ebbd9a750df7bf40727aaafbbaa3e329-image.png)
- 定义f(n,m):表示 每次在n个数字0，1,...,n-1中删除第m个数字最后剩下的数字（也就是要求的结果）。（注意，要求数字标号需要是连续的，所以后面删除一个元素后标号不连续了，需要重新标号）。

- 在这n个数字中，第一个被删除的数字是 (m-1)%n (取余的原因是m可能比n大)，记作k，则k=(m-1)%n。删除后的序列为 0,1,...,k-1,k+1,...,n-1。由于下一次删除是从k+1开始计数的，所以相当于从标号为k+1,k+2,...,n-1,0,1,2,...,k-1的序列中继续删除第m个数字，最终剩下的数字就是结果。

- 剩下的n-1个数字如果重新按顺序标号得到序列0,1,...,n-2，则每次删除第m个数，最后剩下的数字就是f(n-1,m)。由于重新标号了，所以并不是f(n,m)=f(n-1,m)! 那么f(n-1,m)对应的数字在修改标号之前是什么数呢？

- 事实上，原先的不连续的序列A(k+1,k+2,...,n-1,0,1,2,...,k-1)变成了序列B(0,1,...,n-2)，而我们主要是想知道如何从序列B中的某个数找到序列A中对应的关系，先建立个映射表格
![image.png](https://pic.leetcode-cn.com/0decc9750a0224bc77b4c0557669982157615db19a297d704300f9ed81ada66a-image.png)

- 根据表格，可以很直观的看出，在B序列中数字x，对应于A序列中的(x+k+1)%n（注意：必须取余数，因为B序列中为n-k,而n-k+k+1为n+1,必须取余数才能得到1）。所以在B序列中标号为f(n-1,m)，对于在A序列中就为(f(n-1,m)+k+1)%n。

- 还记得k吗，k就是在第一次删除的时候删掉的数(与n有关的变量)，k=(m-1)%n。

- 将其带入上面的式子，就得到:

- (f(n-1,m)+k+1)%n = (f(n-1,m)+(m-1)+1)%n = (f(n-1,m)+m)%n

- 因此，我们就得到了这个递归公式，而当n=1的时候，也就是序列中只有标号为0的数字，显然最后剩下的数字就是0，所以整个公式就是：
- `f(n,m)=(f(n-1,m)+m)%n`,其中n=1时,f(n,m)等于0

### 代码
```
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n < 1 or m < 1:
            return None
        last = 0
        for i in range(2, n+1):
            last = (last + m)%i
        return last
```
