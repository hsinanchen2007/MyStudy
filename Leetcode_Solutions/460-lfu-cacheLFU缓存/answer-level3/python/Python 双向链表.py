今天这个题倒是真的难。。。 以下是抄的一份答案
大概的意思就是维护这样一个双向链表
![image.png](https://pic.leetcode-cn.com/289e935072c54f40201a6ecb3aa1bfb6cda06672da666c7211dbafdc76e4732e-image.png)
然后边界条件非常多... 这个可以从代码里体会
写不来。。。 学习一下这种数据结构


```python
class LFUCache(object):

    def __init__(self, capacity: int):
        self.cache = {} # key:cacheNode
        self.capacity = capacity
        self.freqHead = None

    def moveForward(self,cacheNode, freqNode):
        # 没有这个频率对应的freqNode
        if not freqNode.nxt or freqNode.nxt.freq != freqNode.freq + 1:
            targetFreqNode = FreqNode(freqNode.freq + 1, None, None)
            targetEmpty = True
        else:
            targetFreqNode = freqNode.nxt
            targetEmpty = False
        # 把cacheNode转移到下一个freq
        cacheNode.removeRelations()
        targetFreqNode.append_cache_to_tail(cacheNode)
        if targetEmpty:
            freqNode.insert_behind(targetFreqNode)
        # 如果被删空
        if freqNode.count_caches() == 0:
            # 恰好为头结点 -> 更新
            if self.freqHead == freqNode:
                self.freqHead = targetFreqNode
            # 删掉
            freqNode.remove()

    def dumpCache(self):
        headFreqNode = self.freqHead
        # 字典删除这个cache
        self.cache.pop(headFreqNode.cacheHead.key)
        # freqNode删除这个cache
        headFreqNode.pop_head_cache()
        # 如果头结点删空 
        if headFreqNode.count_caches == 0:
            self.freqHead = headFreqNode.nxt
            headFreqNode.remove()

    def createCache(self, key, value):
        cacheNode = CacheNode(key, value, None, None, None)
        # 存入字典
        self.cache[key] = cacheNode
        if not self.freqHead or self.freqHead.freq != 0:
            newFreqNode = FreqNode(0, None, None)
            newFreqNode.append_cache_to_tail(cacheNode)
            if self.freqHead:
                self.freqHead.insert_before(newFreqNode)
            self.freqHead = newFreqNode
        else:
            self.freqHead.append_cache_to_tail(cacheNode)

    def get(self, key: int) -> int:
        if key in self.cache:
           cacheNode = self.cache[key]
           freqNode = cacheNode.freqNode
           value = cacheNode.value
           # 从当前freqNode下的链表中删除，添加到下一个链表头
           self.moveForward(cacheNode, freqNode)
           return value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity <= 0:
            return -1
        if key not in self.cache:
            if len(self.cache) >= self.capacity:
                self.dumpCache()
            self.createCache(key, value)
        else:
            cacheNode = self.cache[key]
            freqNode = cacheNode.freqNode
            cacheNode.value = value
            self.moveForward(cacheNode, freqNode)
            


class CacheNode(object):
    def __init__(self, key, value, freqNode, pre, nxt):
        self.key = key
        self.value = value
        self.freqNode = freqNode
        self.pre = pre
        self.nxt = nxt

    def removeRelations(self):
        if self.freqNode.cacheHead == self.freqNode.cacheTail:
            self.freqNode.cacheHead = self.freqNode.cacheTail = None
        elif self.freqNode.cacheHead == self:
            self.nxt.pre = None
            self.freqNode.cacheHead = self.nxt
        elif self.freqNode.cacheTail == self:
            self.pre.nxt = None
            self.freqNode.cacheTail = self.pre
        else:
            self.pre.nxt = self.nxt
            self.nxt.pre = self.pre
        self.pre = self.nxt = self.freqNode = None

        
class FreqNode(object):

    def __init__(self, freq, pre, nxt):
        self.freq = freq
        self.pre  = pre
        self.nxt  = nxt
        self.cacheHead = None # 当前频率下的头结点
        self.cacheTail = None
    def count_caches(self):
        if not self.cacheHead and not self.cacheTail:
            return 0
        if self.cacheHead == self.cacheTail:
            return 1
        return '2+'

    def remove(self):
        if self.pre:
            self.pre.nxt = self.nxt
        if self.nxt:
            self.nxt = self.nxt.nxt
        pre = self.pre
        nxt = self.nxt
        self.pre, self.nxt, self.cacheHead, self.cacheTail = None, None, None, None
        return pre, nxt

    def pop_head_cache(self):
        # 当前频率下的cache为空
        if not self.cacheTail and not self.cacheHead:
            return None
        # 只有一个
        if self.cacheHead == self.cacheTail:
            cacheHead = self.cacheHead
            self.cacheHead, self.cacheTail = None, None
            return cacheHead
        # 两个以上
        cacheHead = self.cacheHead
        self.cacheHead = cacheHead.nxt
        self.cacheHead.pre = None
        return cacheHead

    def append_cache_to_tail(self, cacheNode:CacheNode):
        cacheNode.freqNode = self
        # 当前频率的cache node 为空
        if not self.cacheTail and not self.cacheHead:
            self.cacheHead = self.cacheTail = cacheNode
        else:
            cacheNode.pre = self.cacheTail
            cacheNode.nxt = None
            self.cacheTail.nxt = cacheNode
            self.cacheTail = cacheNode
    
    def insert_behind(self, freqNode):
        freqNode.pre = self
        freqNode.nxt = self.nxt
        if self.nxt:
            self.nxt.pre = freqNode
        self.nxt = freqNode

    def insert_before(self, freqNode):
        if self.pre:
            self.pre.nxt = freqNode
        freqNode.pre = self.pre
        freqNode.nxt = self
        self.pre = freqNode
```