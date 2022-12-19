算不得什么好法子，（运行时间80+， 内存14+）不过胜在是独立思考写出来的，记录一下...

**思路**
- 维护一个列表的桶`bucket`，list里每个元素（桶）都是是一个OrderedDict; 字典的元素为: `key: value` `查找的键：对应的值`
    桶0装着刚存储的键值对
    桶1装着使用过1次的键值对：使用次数=get的次数 和 put(key, 新值)的操作次数
    桶2装着使用过2次的键值对
    桶3装着使用过3次的键值对
    ...
- 维护一个字典`table`，存放着 `key: 桶id`键值对
    需要get(key)的时候，`table[key]` 获得的是桶id, 然后到对应的桶获取 `value = bucket[桶id][key]]`

- 维护桶的个数`bucket_num`：以便获知是否需要新增一个桶：比如之前某个元素使用次数为5，再使用一次就变成6，然而对应的桶还不存在，此时就需要新建一个桶

- 维护元素的个数`length`：以便和capacity比较，是否需要删除某个旧元素

- 维护最小桶的指针`cur`：比如现在有[{1:1, 2:2}, {3:3}, {4:4}], 即
    桶0: key-1, key-2使用过0次（即没有被更新过或者get过）
    桶1: key-3, 使用过1次
    桶2: key-4, 使用过2次
    此时最小指针cur指向桶0，元素个数达到capacity，需要删除某个元素的时候，就要在最小桶处删除一个元素，此处桶0有2个元素，左边是更旧的，右边是更新的。即同样是使用过0次，但是key-1比key-2更早加入，所以如果要删除一个元素就应该删除key-1

**时间复杂度**
有空再看吧，这题做得我好气馁...

```
from collections import OrderedDict
class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.bucket = [OrderedDict()] # {key:value} 初始化第0个item是一个OrderedDict
        self.bucket_num = 1 # 桶的个数
        self.length = 0 # 元素个数
        self.table = {} # 维护键和桶的键值对  key: bucket_id
        self.cur = 0 # 维护最小桶的指针
        self.capacity = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.table:  # 键不存在
            return -1
        else:  # 键存在
            b_num = self.table[key]  # bucket id
            new_bucket = b_num + 1
            if self.bucket_num - 1 < new_bucket: # 判断是否需要新建桶，因为更大的桶可能已经存在
                self.bucket.append(OrderedDict())  # 创建新桶
                self.bucket_num += 1 # 桶个数加1
            val = self.bucket[b_num].pop(key)  # 移除旧桶的 key: val
            self.bucket[new_bucket][key] = val  # 新桶存入 key: val
            self.table[key] = new_bucket  # 更新 key: 桶的关系
            if self.cur == b_num and len(self.bucket[b_num])==0: # 如果原本的桶是最小桶, 且已清空，则更新最小桶的指针
                self.cur += 1
            return val

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        # 如果key已存在，则需要更新值，同时key对应的使用次数+1，即需要换大一码的桶
        if key in self.table:
            self.get(key)
            b_num = self.table[key]
            self.bucket[b_num][key] = value

        else: # key 不存在，则添加
            if self.length == self.capacity: # 如果元素个数等于容量，需要删除一个元素
                if not self.capacity: # 如果桶容量为0，则返回
                    return
                k, v = self.bucket[self.cur].popitem(last=False)  # 删除最小桶的key: val
                self.table.pop(k)
                self.length -= 1
            self.bucket[0][key] = value # 新增的元素先添加到桶0
            self.cur = 0  # 更新最小桶的指针
            self.table[key] = 0  # 更新桶和key的关系
            self.length += 1 # 元素个数+1
```
