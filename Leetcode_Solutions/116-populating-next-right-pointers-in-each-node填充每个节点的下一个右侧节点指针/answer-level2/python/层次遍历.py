1.对完美二叉树进行层次遍历，设置遍历的层数，当遍历到每层的最后一个元素的时候其next指针指向NULL
否则指向下一个遍历的节点，
2.遍历完美二叉树使用队
```
from collections import deque
class Solution(object):
    def connect(self, root):
        if not root:
            return root
        p=root
        queue = deque([(1,p)])
        i=0
        while(queue):
            num,p=queue.popleft()
            i+=1
            if(i==pow(2,num)-1):#判断是否为本层最后一个元素
               root.next=None
            else:
                p.next=queue[0][1]#指向队中的第一个元素，也就是这个节点的右侧第一个
            if(p.left):
                queue.append((num+1,p.left))
            if(p.right):
                queue.append((num+1,p.right))

        return root


```
