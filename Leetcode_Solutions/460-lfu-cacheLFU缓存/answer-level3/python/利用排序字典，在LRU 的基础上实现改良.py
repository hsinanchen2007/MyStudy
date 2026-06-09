### 解题思路

![图片.png](https://pic.leetcode-cn.com/47abc86f7abff87bdda21ac012b6849d482c5d0002ba7ba461df114f9a4cec71-%E5%9B%BE%E7%89%87.png)

我们需要搞清楚删除每个元素的思路就可以，首先是按照频率进行排序，其次在同频率下按照最近使用。因此在同样的使用频率下其实就是一个LRU系统。 对于LRU系统的实现，我们借助python中collections.OrderedDict()来实现。具体的参考第146题。
本题中，首先我们有一个字典，链接到每个结点，然后节点包括了两个属性，一个是排序字典，一个是当前结点对应的频率。
我们在删除最少使用元素时，只需要删除star节点后面的一个节点的内容即可。如果该节点内排序字典长度为1。则删除这个节点，否则按照LRU的设计理念，删除字典最左侧的内容。

### 代码

```python
class Listnode():
    def __init__(self, fre = None):
        self.num = fre
        self.dic = collections.OrderedDict()
        self.next = None
        self.pre = None


class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.dic = {}
        self.star = Listnode(0)
        self.end = Listnode(float('inf'))
        self.star.next = self.end
        self.end.pre = self.star
        self.capacity = capacity
    
    def move(self, node, key): # 频率加一
        if node.next.num == node.num + 1:
            node.next.dic[key] = node.dic[key]
            node.dic.pop(key)
            self.dic[key] = node.next
        else:
            new_node = Listnode(node.num+1)
            new_node.next = node.next
            node.next.pre = new_node
            new_node.pre = node
            node.next = new_node
            new_node.dic[key] = node.dic[key]
            node.dic.pop(key)
            self.dic[key] = new_node
        if len(node.dic) == 0:
            node.pre.next = node.next
            node.next.pre = node.pre

    def delet(self):
        node = self.star.next
        #if len(node.dic) == 0:
        #    return
        if len(node.dic) == 1:
            self.star.next = node.next
            node.next.pre = self.star
            [key, value] = node.dic.popitem(last=False)
        else:
            [key, value] = node.dic.popitem(last=False)
        return key


        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.dic:
            return -1
        node = self.dic[key]
        value = node.dic[key]
        self.move(node, key)
        return value
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.dic:
            node = self.dic[key]
            node.dic[key] = value
            self.move(node, key)
        else:
            if self.capacity == 0:
                return 
            if len(self.dic) == self.capacity:
                delkey = self.delet()
                print(delkey)
                self.dic.pop(delkey)
            if self.star.next.num == 1:
                node = self.star.next
                node.dic[key] = value
                self.dic[key] = node
            else:
                node = Listnode(1)
                self.star.next.pre = node
                node.next = self.star.next                 
                self.star.next = node
                node.pre = self.star
                self.dic[key] = node
                node.dic[key] = value



        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```