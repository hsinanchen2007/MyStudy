

```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        
        p = head
        q = head
        
        while q and q.next:
            p = p.next
            q = q.next.next
            
        node = self.reverse(p)
        
        while node:
            if node.val != head.val:
                return False
            node = node.next
            head = head.next
        
        return True
            
        
    def reverse(self, head):
        if not head or not head.next:
            return head
        
        last = self.reverse(head.next)
        
        head.next.next = head
        head.next = None
        
        return last
```


![image.png](https://pic.leetcode-cn.com/d2a377ba060bc4986358b221eb060f79024a5021807e1a9d83f70be0993b5586-image.png)


这个也太慢了吧。。。然后改成循环：

```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        
        p = head
        q = head
        
        while q and q.next:
            p = p.next
            q = q.next.next
            
        pre = None
        cur = p
        
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
            
        while pre:
            if head.val != pre.val:
                return False
            head = head.next
            pre = pre.next
        
        return True
```
稍微好了一点点。。。可能是空间复杂度提升之后的trade off吧。。。（人啊，很多时候都要trade off，记于1024节日的手抖后）
**时间复杂度O(n)，空间复杂度O(1)**

![image.png](https://pic.leetcode-cn.com/4f1bf962a371bc121bb68a8ff3ac427a285c6761ce2e2aeb58740f55d8d31bcd-image.png)


### 2.用数组保存元素值

假设上面来得慢是空间复杂度的提升的问题，那我来试试增大空间复杂度看看结果（我是不是有猫饼，居然要增大复杂度。。。）

那么就拿一个数组保存链表的元素值，然后双指针判断首位是否相等，比较好写：

```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # if not head:
        #     return True
        
        array = []
        
        while head:
            array.append(head.val)
            head = head.next
            
        i = 0
        j = len(array) - 1
        
        while i < j:
            if array[i] != array[j]:
                return False
            i += 1
            j -= 1
        
        return True
        
```

然而结果。。。嗬，**时间复杂度和空间复杂度都O(n)**，突然意识到时间复杂度根本没提升啊还期待快很多吗。。。
这个方法，卒。还是老老实实逆转吧。。。（希望生活也逆转一下叭拜托了）

![image.png](https://pic.leetcode-cn.com/4e2c1eeb390f326ffff7d7c138faa18c860d3d3ce150f02b8df1cd3752fdb8b5-image.png)


