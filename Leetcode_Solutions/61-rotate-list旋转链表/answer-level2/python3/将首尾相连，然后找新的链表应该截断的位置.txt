![image.png](https://pic.leetcode-cn.com/ca97bb15e50b43500ac75d9fb39a0e7555be226b7771add814596f7c5230d11c-image.png)

emmmm好像很浪费内存，但是时间还可以
旋转k个，如果k大于链表长度的话就只有k除以长度n的余数有意义，作为一个有效的k值。
先循环计数算出链表长度，然后找到有效的k。
原链表的末尾会变成新链表的第k个，所以原末尾和原链表头相连
然后原链表的第k个节点和后一个节点断开
所以再找到第k个节点然后把next赋为None，并返回他的下一个节点作为新的链表头即可

```python []
class Solution:
    def rotateRight(self, head, k):
 
        n=1
        temp = head
        if temp:
            while temp.next:
                n+=1

                temp = temp.next
        else:
            return head
        
        validk = k % n
        if validk ==0:
            return head

        count = 0
        temp2 = head
        while temp2:
            count += 1
            if count == n-validk:
                tempend = temp2
            temp2 = temp2.next
        result = tempend.next
        tempend.next = None
        temp.next = head
        
        return result
```
