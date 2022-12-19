
相信用python的人都知道对于交换两个变量的值可以写成这样
```
x = 1
y = 2
x, y = y, x
```
但是其中的原理大都不是很清楚，这里我就来说一下：
首先先说赋值的两行，由于python是引用传递的方式，所以赋值的意思是开辟两块空间分别存1,2两个值，然后变量x,y分别指向1,2对应的空间；
对于交换这行代码首先先执行等号右边的表达式，即开辟一个元组空间存储元组然后，分别将2,1的值依次放入进去；之后的过程即是将x指向元组中2对应的空间，y指向1对应的空间
![1569642793822.jpg](https://pic.leetcode-cn.com/eb595127ff0d3bed790be5eb99df22eed9958c27d6fe377630b171dded0ccf9a-1569642793822.jpg)
即实现了交换两个变量的值，元组本身并没有变，只是x,y的指向变了，这里可以试一下以下代码输出什么来理解
```
x,y,z = 1,2,3
tuple = (x,y,z)
x = 4
print(tuple)
```
理解了这个原理接下来的三元赋值的方法就很好理解了：
```
class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p, rev = head, None
        while p:
            rev, rev.next, p = p, rev, p.next
        return rev
```
以`1->2->3->4->5->null`为例，我将画图来辅助理解这个循环的过程
![1569643564803.jpg](https://pic.leetcode-cn.com/abf5ac0785ae5429d1a8eacd0876b3bf4503283046ded5cfb21a7e77a9498356-1569643564803.jpg)




