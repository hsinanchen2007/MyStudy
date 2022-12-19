### 解题思路
看完题目有key有value有put有get，以我薄弱的知识储备，首先想到的是用dict。一开始想的是构建一个key_val_dict，然后访问key的时候得val；然后构建一个key_freq_dict，访问key的时候得frequency；然后构建一个freq_key_dict，访问freq的时候得到同一个frequency下访问过的key的list，用以判断哪个是最近最少使用的key（p.s. 我总觉得这个最近最少读起来真的很恶心，是不是我的语文理解能力有问题？总觉得应该描述为最早最少）。
然后一顿操作下来，把自己烦死了。时间关系，就参考了一下题解和评论有没有用类似我这种思路解决问题的，确实还是有的。如果用我一开始的这种构建dict的做法，肯定还是做得出来的，但是会多很多不必要的麻烦，然后把自己作死。

**本题关键思路**：按照题意直接用dict暴力解决，这个dict的key就是输入的key，然而对应这个key的value就包装在了一个list里面，[value, frequency, time]，frequency就是访问过的次数，time这里指的是对这个Cache访问操作了第几次。关键就是这个time了，这里是为了方便的找到哪个key是最少使用的里面，最早使用的那个。如果我们每get一次，或者put一次，都给这个time+=1，那time小的就是最早的那个了。

### 代码

```python3
class LFUCache:
    # 根据上述解释，这里就把dict命名为key_val_freq_time_dict，方便记忆，也就是key对应val_freq_time的list的意思
    def __init__(self, capacity: int):
        self.key_val_freq_time_dict = {}
        self.capacity = capacity
        self.__time = 0
    # get相对简单，如果key不在这个dict里面，返回-1
    # 如果在的话，我们返回key所对应的list中的第0个也就是value，然后第1个也就是frequency就要+1，第2个也就time就更新为本次get操作的time
    def get(self, key: int) -> int:
        self.__time += 1
        if key in self.key_val_freq_time_dict:
            self.key_val_freq_time_dict[key][1] += 1
            self.key_val_freq_time_dict[key][2] = self.__time
            return self.key_val_freq_time_dict[key][0]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        self.__time += 1
        # 这里题目没说capacity不可以是0，把这个删掉的话，0的用例就会错
        if self.capacity == 0:
            return None
        # 首先考虑如果key已经存在，那就更新key对应的value，并且key的访问次数+1，key的访问time更新
        if key in self.key_val_freq_time_dict:
            self.key_val_freq_time_dict[key][0] = value
            self.key_val_freq_time_dict[key][1] += 1
            self.key_val_freq_time_dict[key][2] = self.__time
        else:
            # 如果key第一次见，当dict的大小还小于capacity的话，就直接给dict插入新元素
            if len(self.key_val_freq_time_dict) < self.capacity:
                self.key_val_freq_time_dict[key] = [value, 0, self.__time]
            else:
                # 如果不够放了，那我们就按题意先找访问次数最少的freq能有多少
                min_freq = self.key_val_freq_time_dict[min(self.key_val_freq_time_dict, key=lambda x: self.key_val_freq_time_dict[x][1])][1]
                # 然后我们找出访问次数为最少的都有哪些key，并放在一个新的dict里面
                min_key_dict = {}
                for k in self.key_val_freq_time_dict:
                    if self.key_val_freq_time_dict[k][1] == min_freq:
                        min_key_dict[k] = self.key_val_freq_time_dict[k]
                # 然后我们找出这些访问最少的key，最早访问的key值是多少，然后就把原dict的这个key删掉
                min_time_key = min(min_key_dict, key=lambda x: min_key_dict[x][2])
                self.key_val_freq_time_dict.pop(min_time_key)
            # 删完就可以放心的key了
            self.key_val_freq_time_dict[key] = [value, 0, self.__time]

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

```