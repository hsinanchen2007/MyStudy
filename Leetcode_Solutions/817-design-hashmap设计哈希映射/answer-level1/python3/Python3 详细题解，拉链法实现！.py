##### 哈希表原理：
        
    Hash，一般翻译做“散列”，也有直接音译为“哈希”的，就是把任意长度的输入（又叫做预映射， pre-image），通过散列算法，变换成固定长度的输出，该输出就是散列值。这种转换是一种压缩映射，也就是，散列值的空间通常远小于输入的空间，不同的输入可能会散列成相同的输出，而不可能从散列值来唯一的确定输入值。
    
简单的说就是一种将任意长度的消息压缩到某一固定长度的消息摘要的函数。


    数组的特点是：寻址容易，插入和删除困难；而链表的特点是：寻址困难，插入和删除容易。

那么我们能不能综合两者的特性，做出一种寻址容易，插入删除也容易的数据结构？
    
答案是肯定的，这就是我们要提起的哈希表，哈希表有多种不同的实现方法，下面是最常用的一种方法——拉链法，我们可以理解为“链表的数组”。

    
##### 拉链法：它的思想很简单，在哈希表中的每个位置上，用一个链表来存储所有映射到该位置的元素。


    
    (1)对于put(key, value)操作:
        我们先求出key的哈希值(取模)，然后遍历该位置上的链表:
            如果链表中包含key，则更新其对应的value；
            如果链表中不包含key，则直接将（key，value）插入该链表中。
    
    (2)对于get(key)操作:
        求出key对应的哈希值后，遍历该位置上的链表.
            如果key在链表中，则返回其对应的value，否则返回-1。
    
    (3)对于remove(key)，求出key的哈希值后，遍历该位置上的链表，如果key在链表中，则将其删除。
"""

```python
class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hash = [[] for _ in range(20011)]  # 开辟一个大数组，长度为质数，注意这里不能用 [[]] * 20011
        # 一般定义成离2的整次幂比较远的质数，这样取模之后冲突的概率比较低。

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        t = key % 20011
        for item in self.hash[t]:  # 遍历哈希到的链表中，查找key,并更新值
            if item[0] == key:
                item[1] = value
                return  # 更新完之后，直接返回
        self.hash[t].append([key, value])  # 如果链表中找不到对应的key，将其新添到链表中

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        t = key % 20011
        for item in self.hash[t]:
            if item[0] == key:
                return item[1]
        return -1  # 可能哈希的位置，所对应的链表不为空，但是不存在该值

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        t = key % 20011
        delete = []
        for item in self.hash[t]:
            if item[0] == key:
                delete = item  # remove方法，这里可以偷懒，把对应的value值设为-1，即表示它已经删除
        if delete:
            self.hash[t].remove(delete)
```

