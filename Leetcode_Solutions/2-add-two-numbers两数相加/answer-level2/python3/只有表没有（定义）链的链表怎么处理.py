### 解题思路
方案一：提取2个链表，相加后再创建一个新链表的方法，思路比较明确（不管几位数，一位一位扣就行。我这个方法是在第一个数后面插入新表，我的意中人（链表）是一个一个拍着队的进去，对链表怎么开头还是不太熟）
方案二：在l1和l2链表上直接相加，相当于返回较长链表的起始指针，写程序的时候有很多特殊条件需要注意，比较难搞

方案二好处是执行用时稍微快一点，怎么减少内存消耗这块还没接触，后面有体会了再说吧。

ps:话说这个单链表和网上搜到的不一样，对我这种新手+菜鸟太残酷了。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
    #方案二：采用原有链表l1/l2计算
        l3=l1
        l4=l2
        l1_long=0
        check_i=0
        while l1 is not None or l2 is not None:

            if l1 is not None:
                if l2 is not None:
                    l1.val=(l1.val+l2.val+check_i) # %10
                    check_i=0
                    if l1.val >= 10:
                        l1.val-=10
                        check_i=1;
                    l2.val=l1.val
                    #判断l1l2等长时链表尾部是否需要增加一个list
                    if l1.next is None and l2.next is None and check_i==1:
                        ListNode(1).next=l1.next
                        l1.next=ListNode(1)
                        check_i=0
                    l1 = l1.next
                    l2 = l2.next
                elif l2 is None:
                    l1.val=(l1.val+check_i) # %10
                    check_i=0
                    if l1.val >= 10:
                        l1.val-=10
                        check_i=1
                    #判断l1长时链表尾部是否需要增加一个list
                    if l1.next is None and check_i==1:
                        ListNode(1).next=l1.next
                        l1.next=ListNode(1)
                        check_i=0
                    l1 = l1.next
                    l1_long=1
            
            elif l1 is None and l2 is not None:  
                #l2数据比l1多，把l2插入到l1里,并把有可能超出的check_i清零
                l2.val=(l2.val+check_i)
                check_i=0
                if l2.val >= 10:
                        l2.val-=10
                        check_i=1
                #判断l2链表尾部是否需要增加一个list
                if l2.next is None and check_i==1:
                        ListNode(1).next=l2.next
                        l2.next=ListNode(1)
                        check_i=0
                l2 = l2.next

        if l1_long==1:
            return l3
        else:
            return l4
 

'''方案一：采用新建链表，战胜5%的人。。。
        #浮点型会有小尾巴，用字符试试
        l1_date = ""
        l2_date = ""
        #l1_date = 0.0
        #l2_date = 0.0
        i = 0  # 记录位数

        #while l1 or l2 is not None:
            # 顺序采用：l1_date = l1_date & str(l1.val)
        l1_i=l2_i=0
        while l1 is not None :
            l1_date = str(l1.val) + l1_date 
            l1 = l1.next
            l1_i+=1
        while l2 is not None :
            l2_date = str(l2.val) + l2_date 
            l2 = l2.next
            l2_i+=1
        i =4 # max(l1_i,l2_i)
            

        suml1l2 = int(l1_date) + int(l2_date)
        results=ListNode(1100)
        #results.next = None
        #suml1l2=int(suml1l2/10)
        while i>0:
            re_tem= ListNode(int(suml1l2 / 10**i)) 
            #while results.next != None:
                #results= results.next
            #self.next=re_tem
            re_tem.next=results.next
            results.next = re_tem
            #results.next=re_tem.next
            #re_tem =re_tem.next

            #results = re_tem.next
            #re_tem.next = results.next
            #results = results.next
            #suml1l2=int(suml1l2/10)
            i-=1
        return results

    ''' 
```