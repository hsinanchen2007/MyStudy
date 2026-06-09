### 解题思路
分析可知，LRU的数据结构满足以下三个条件：
- 在末尾加入一项
- 去除最前端一项
- 将队列中某一项移到末尾
时间复杂度均需要为`O(1)`；

比较好的方法是利用字典，可以用`O(1)`的时间进行读取及删除，但由于字典是无序的，没有末尾及最前端一说；因此最好的方法是利用有序字典`from collections import OrderedDict`[参考链接](https://leetcode-cn.com/problems/lru-cache/solution/lru-huan-cun-ji-zhi-by-leetcode/)；

我这里用的是辅助列表进行排序，只能完成功能，无法满足`O(1)`的时间要求；

### 代码

```python3
class LRUCache:
    
    def __init__(self, capacity: int):
        self.max_capacity = capacity
        self.lru_dict = dict()
        self.lru_list = []
        
    def _edit(self, key):
        try:
            self.lru_list.remove(key)
            self.lru_list.append(key)
        except:
            pass

    def get(self, key: int) -> int:
        # 更改lru_list
        self._edit(key)
        
        try:
            return self.lru_dict[key]
        except:
            return -1
    
    def put(self, key: int, value: int) -> None:        
        try:
            tmp = self.lru_dict[key]
            self.lru_dict[key] = value
            # 更改lru_list
            self._edit(key)
        except:
            if len(self.lru_list) == self.max_capacity:
                # 删除操作
                tmp = self.lru_list.pop(0)
                self.lru_dict.pop(tmp)

            self.lru_dict[key] = value
            self.lru_list.append(key)
            
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```