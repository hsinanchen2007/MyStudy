# LRU简介
既然要设计LRU缓存，那我们首先要搞清楚它的原理。
假设有下面这么一个数组，里面存储的都是数字，存储的时间顺序是左边早右边晚，也就是最左边的元素是刚刚放入的，最右边的元素是最久的时间放入的。
![1570951221(1).jpg](https://pic.leetcode-cn.com/9b2d356821a7c6056ec6457ac12dd27d43e118945c9084bd181778fc5063c111-1570951221\(1\).jpg)

缓存的大小是有限的，LRU的核心就是在缓存空间被用满的时候，如何剔除掉一些元素，让空间变得可以用，能继续塞入一个元素。
当我们访问一个元素时，需要重新指定这个元素的顺序，将其标记为最新的，如果空间不够用的时候，就找到最旧的元素将其删除即可。
所以，按照LRU的原理，获取一个元素时，不光要返回这个元素，还需要改变这个元素在数组中的位置，比如下面是获取元素5，那么就需要把5这个元素放到最左边，因为最左边是最早的时间嘛。
![img_2540.jpg](https://pic.leetcode-cn.com/af3eb557df157e873282da465a97eba92014d9a2716d68445535a59937608cd8-img_2540.jpg)

如果数组空间不够怎么办呢？我们申请的这个数组只能放6个数字，这时候要插入元素7，那就必须淘汰掉一个元素，淘汰的这个元素，就是最久远的，也就是元素6。之后将7这个元素放到数组的第一位。
![img_2541.jpg](https://pic.leetcode-cn.com/d97d320f8ff03ffff999a947035e30c3f1bbcae002737b03ea77b9769f46d00b-img_2541.jpg)

上面我们只用数组举了一个例子，实际上想实现0(1)复杂度的get，O(1)复杂度的put，数组肯定是不行的。因为数组删除一个元素之后需要挪动元素位置，这就无法满足O(1)时间复杂度这个需求了。
想要实现get和put都是O(1)实现复杂度最好的数据结构就是hash表，但是hash表这种结构无法实现元素的遍历。我们需要定位某个元素是最新的，某个元素是最旧的，但是hash表无法做到。
我们可以结合两种数据结构，双向链表和hash表，双向链表可以用O(1)时间复杂度定位到第一个元素，以及最后一个元素，这样我们就能定位到最新和最旧了。

# 使用库函数实现
python库函数中有一个类叫做：
```python
OrderedDict
```
这个类本身就支持将访问的某个元素移动到最开头这种功能，所以直接借助库函数就可以实现了。
对于Java来说，也有一个类似的类：
```java
LinkedHashMap
```

代码实现如下：
```python
# 这句相当于Java的 class LRUCache extend Object {}
# python 里面没有{}，通过缩进来控制代码格式的，而且是强制缩进，
# 如果某一行缩进三个空格，下面一行缩进了四个空间，整个代码就编译不通过
class LRUCache(object):
    # __init__ 就相当于Java的构造函数，def是定义一个函数的意思
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        # 导入python的库函数，python的注释使用#开头的
        import collections
        # self.d 就相当于 Java的 this.d = 。。。
        self.d = collections.OrderedDict()
        self.size = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        # 假如key在缓存中，需要先获取到key对应的值，然后删除这个
        # key，再重新插入一遍(插入时会自动放入到第一位)
        if(key in self.d):
            value = self.d[key]
            # del self.d[key] 类似java中的
            # this.d.remove(key)
            del self.d[key]
            self.d[key] = value
            return value
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        # 如果key在缓存中，需要先将这个key删除，最后统一再插入
        if(key in self.d):
            del self.d[key]
        # 如果key不在缓存中，那么检查缓存是否满了
        # len(self.d) 相当于Java的 this.d.length
        # 如果满了就删掉最久没用过的那个元素
        else:
            if(len(self.d)==self.size):
                self.d.popitem(False)
        # 最后统一插入这个元素
        self.d[key] = value
```

# 双向链表实现方式
首先我们要自己定义一个链接结点
```python
class Node(object):
    # __init__类似java的构造函数，self类似java的this
    #这里我们定义了key和value，时候是冗余了，这主要是因为
    #删除元素时，我们通过双向链表可以轻松找到最后一个元素，
    #如果只存value的话，就没法通过链表节点反推到hash表中的位置，
    #所以需要冗余一个key
    def __init__(self,key=None,value=None):
        self.key = key
        self.value = value
        self.pre = None
        self.next = None
```

下图中左边部分就是hash表，每个槽子中存储的就是元素的key。
下面中右边部分是双向链表，存储的是key:value，双向链表最上方最下方分别是链表的head和链表的tail。
我们来看看双向链表+hash表这种组合，获取元素的具体步骤
假设我们现在要获取2这个元素，对应到双向链表就是【2:200】这个节点。
![get_1.jpg](https://pic.leetcode-cn.com/9a4fe89dce8ed124b714540c9f68a98037777e6b52bd0c02c5bcb389d4295224-get_1.jpg)

【2:200】这个元素会被放到双向链表的开头，但是这个元素的key，也就是2，在hash表中的位置是不变的。
![get_2.jpg](https://pic.leetcode-cn.com/8d78d92bfe53fbb91e268f7ead813c96701c3b5c06a610c0f2ec08204706509d-get_2.jpg)

再来看看插入一个元素的情况
假设空间不够了，那么就需要找到双向链表中的最后一个节点，这里是【4:400】这个节点
![put_1.jpg](https://pic.leetcode-cn.com/f229bad30f4df3d15300f17b1abbb84ce8b886324e1c5b66a0e3ecba51a449bf-put_1.jpg)

通过这个链表节点，我们知道key是4，然后找到hash表中的4这个key。这也就是为什么要在链表节点中冗余一份key的原因。
之后我们将双链表中的最后一个元素删除。
![put_2.jpg](https://pic.leetcode-cn.com/06f623c8325d490d59e6a5c84fd5e880d5f511151a58aafe95880de0194c9513-put_2.jpg)

现在，将hash表中4这个key删除掉。接着添加一个新元素9到双向链表的开头。
再将key9放到元素hash表4中的那个位置。
![put_3.jpg](https://pic.leetcode-cn.com/68b40b095c5b13fe5863c8526024ac9c2e30ebcd1d0586089c44d74c642ad12b-put_3.jpg)

代码实现如下
```python
#定义一个链表节点
class Node(object):
    # __init__相当于java的构造函数
    # key和value这两个参数如果不传入，默认用None
    # 也就是java的null
    def __init__(self,key=None,value=None):
        self.key = key
        self.value = value
        # 定义前驱和后继节点
        self.pre = None
        self.next = None

#定义双向链表
class LinkList(object):
    # 在构造器中，创建head，tail两个节点
    def __init__(self):
        self.head = Node()
        self.tail = Node()
        #head和tail默认是相互指向
        self.head.pre = self.tail
        self.head.next = self.tail
        self.tail.pre = self.head
        self.tail.next = self.head

    # 将一个元素 添加到双链表的开头
    def add_to_first(self,node):
        #当前元素的下一个节点指向head元素的下一个
        #head <--> 1 <--> 2...
        # 这句话就是将node插入到 元素1的前面
        node.next = self.head.next
        # 这句就是将 元素1的前驱节点，指向node
        self.head.next.pre = node
        #将node的前驱节点指向head
        node.pre = self.head
        #将head的后继节点指向node
        self.head.next = node

    def delete(self,node):
        # 1<-->2<-->node<-->3<-->4
        # 让node的前驱指向node的后继，也就是1->3
        node.pre.next = node.next
        #node的后继指向node的前驱，也就是3-->1
        #这样就完成 1<-->3 关联了
        node.next.pre = node.pre
        # 最后将node节点的前驱和后继设置为空
        node.pre = None
        node.next = None

    #获取最后一个元素
    def get_last(self):
        if(self.head==self.tail):
            return None
        return self.tail.pre

    # 删除一个元素，并将其插入到链表开头
    def remove_add_first(self,node):
        self.delete(node)
        self.add_to_first(node)

# 定义LRU对象
class LRUCache(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        # dict是python内置的map，类似Javaa的HashMap
        self.cache = dict()
        self.linklist = LinkList()
        self.cap = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        #如果key在hash表中，则删除这个key
        #并将其放到双向链表的开头，最后返回元素值
        if(key in self.cache):
            node = self.cache[key]
            self.linklist.remove_add_first(node)
            return node.value
        #不存在就返回-1
        return -1


    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        #如果key在hash表中，获取这个元素
        #因为hash表中的value就是一个链表节点
        #所以这里的tmp就是一个链表节点，并将其删除
        #这里不插入，最后统一插入
        if(key in self.cache):
            tmp = self.cache[key]
            self.linklist.delete(tmp)
        else:
        #如果key不在hash表中，需要看缓存是否满了
        #len(sele.cache)类似java的 this.cache.length
            if(len(self.cache)==self.cap):
                #如果满了就拿到双链表的最后一个节点
                tmp = self.linklist.get_last()
                #tmp就是一个链表节点，根据这个节点的key
                #到hash表删除对应的值
                del self.cache[tmp.key]
                #在双向链表中也将这个节点删除
                self.linklist.delete(tmp)
        #不管key是否在hash表中，最后都统一插入
        node = Node(key,value)
        self.cache[key] = node
        self.linklist.add_to_first(node)
```
(全文完)
**我致力于用图画的方式演示算法的执行，如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)
