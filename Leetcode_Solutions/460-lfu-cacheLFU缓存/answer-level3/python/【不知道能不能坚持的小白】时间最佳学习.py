### 解题思路
学习结果里面的时间最佳方法。
之前的解法用到了dict，defaultdict和OrderedDict很少用，趁这个机会好好学学。
defaultdict就是一个给不同类型的key直接赋予了默认val的dict。举个例子，如果在一个defaultdict里面寻找一个不存在的int的key，不会报错而是返回默认值0。
OrderedDict顾名思义就是有order的dict，就是按赋予key的顺序给dict排序，当然这个顺序也可以用lambda去调整为value的值等等。用这个的目的不用看代码都知道可以省掉之前解法的count。
https://leetcode-cn.com/problems/lfu-cache/solution/bu-zhi-dao-neng-bu-neng-jian-chi-de-xiao-bai-mei-2/

**本题核心思路**：基本上还是离不开要给key赋值value和freq，毕竟还是要统计使用频率。利用OrderedDict来免除count来判断哪个是最早入dict的key。

### 代码

```python3
from collections import defaultdict, OrderedDict


class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        # cache_dict为普通dict，用来放key和对应的value和freq
        self.cache_dict = {}
        # 建立一个有序字典的defaultdict
        self.order_dict = defaultdict(OrderedDict)

    def get(self, key: int) -> int:
        if key not in self.cache_dict:
            return -1

        value, freq = self.cache_dict.get(key)
        # 如果看代码直接从上到下先看这里可能会不太理解，能走到这一步是建立在已经put了某个key进去
        # 然后既然是要访问这个key，那就要更新一下这个key对应的freq，所以先把存在order_dict里面旧freq对应的key给pop了
        # 这里要注意，freq才是键，key是在order_dict里面以freq为键对应的value，别搞混了
        # 其实这里做的就是原先我想做的，弄一个dict专门放访问频率对应key，只要查找某个访问频率就能知道有哪些key的访问频率是这个数，这样就可以删掉最早访问的那个了
        self.order_dict[freq].pop(key)
        # 如果这个久freq里面没别的key了，那就把这个旧freq给pop了
        if not self.order_dict[freq]:
            self.order_dict.pop(freq)
        freq += 1
        self.cache_dict[key] = (value, freq)
        # 由于order_dict已经是有序的，所以并不需要另外给freq的key做记号
        self.order_dict[freq][key] = ''

        return value

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return -1
        # 当这个key已经存在，那就更新一下value和freq
        if key in self.cache_dict:
            temp_value, freq = self.cache_dict.get(key)
            self.order_dict[freq].pop(key)
            if not self.order_dict[freq]:
                self.order_dict.pop(freq)
            freq += 1
            # 这里原作者多写了一步，self.cache_dict[key] = (temp_value, freq)，应该是复制粘贴的时候放了删掉，是不需要的
            self.order_dict[freq][key] = ''
            self.cache_dict[key] = (value, freq)
            return
        # 如果要满了，就删掉
        if len(self.cache_dict) == self.capacity:
            # order_dict里面键freq最小的是哪个找出来
            min_freq = min(self.order_dict)
            # 这里就是为什么用OrderedDict了，last=False会让popitem把最早放进dict里的那个pop出来
            del_key, _ = self.order_dict[min_freq].popitem(last=False)
            if not self.order_dict[min_freq]:
                self.order_dict.pop(min_freq)
            self.cache_dict.pop(del_key)

        self.cache_dict[key] = (value, 0)
        self.order_dict[0][key] = ''

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

```