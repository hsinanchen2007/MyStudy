**方法1：基于链表计算**
自链表头起，逐个相加对应元素，满十进一，若无数据则补0。
由于输出也是链表结构，为创建链表方便，设置哑节点作为head，并在输出时丢弃该节点，即返回head.next。
注意：
（1）最后要验证是否还有最后一位进位，若有需再添加一个节点；
（2）输出的链表在逐个添加尾部节点时需使用另一个游标=head，以保持输出所需的表头不变。
效率：
（1）时间复杂度：$O(N)$（ $N=max(len(l1),len(l2))$ ）
```
class Solution1:
    def addTwoNumbers(self, l1, l2):
        head = ListNode(0)
        prove = head
        unit = 0
        while(l1!=None or l2!=None):
            l1_value = l1.val if l1 else 0
            l2_value = l2.val if l2 else 0
            sums = l1_value+l2_value+unit
            digit = sums%10
            unit = sums//10
            node = ListNode(digit)
            prove.next = node
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            prove = prove.next
        if unit:
            prove.next = ListNode(1)
        return head.next
```

**方法2：转换计算**
先将链表存储的数据转换为十进制数，进行加法计算后，创建ListNode按逆序存储该数据（在链表表头/尾部逐次插入的效率一样）。
效率：
（1）时间复杂度：$O(N)$（ $N=max(len(l1),len(l2))$ ）  
```
class Solution2:
    def transform(self,l):
        prove = l
        number = 0
        local = 0
        while(prove!= None):
            number+= prove.val*10**local
            local+= 1
            prove= prove.next
        return number
    def addTwoNumbers(self, l1, l2):
        number = self.transform(l1) + self.transform(l2)
        head = None
        for i in str(number):             #链表表头逐次插入
            node = ListNode(int(i))
            if head== None:
                head = node
            else:
                node.next = head
                head = node
        return head
```
