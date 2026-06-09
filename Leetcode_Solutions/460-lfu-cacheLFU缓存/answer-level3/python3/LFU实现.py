### 解题思路
此处撰写解题思路
有两个关键点，
1. 不管put还是get，都可以增加元素使用频次
2. put和get都要更新元素的update_time
print_all_element()是用来调试的
### 代码

```python
# -*- coding: utf-8 -*-
class CacheObject(object):
    def __init__(self, key, value, update_time=0):
        self.frequency = 0
        self.update_time = update_time
        self.object_key = key
        self.object_value = value


class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.element_map = {}

        self.global_update_time = 0

    def get_update_time(self):
        self.global_update_time += 1
        return self.global_update_time

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.element_map:
            cache_obj = self.element_map[key]
            cache_obj.frequency = cache_obj.frequency + 1
            cache_obj.update_time = self.get_update_time()
            return cache_obj.object_value
        else:
            return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if self.capacity <= 0:
            return
        if key in self.element_map:
            # 之前存在的，只是更新
            cache_obj = self.element_map[key]
            cache_obj.update_time = self.get_update_time()
            cache_obj.object_value = value
            cache_obj.frequency += 1
        else:
            if len(self.element_map) >= self.capacity:
                # 淘汰
                self.eliminate()

            self.element_map[key] = CacheObject(key=key, value=value, update_time=self.get_update_time())
        # self.print_all_element()

    def print_all_element(self):
        for item in self.element_map:
            cache_obj = self.element_map[item]
            print("键：%s, 频次%s, 更新时间%s" % (item, cache_obj.frequency, cache_obj.update_time))
        print("__________________________________")

    def eliminate(self):
        # 需要按使用频率排序，去除频率最低的
        element_list = [self.element_map[item] for item in self.element_map]
        element_list = sorted(element_list, key=lambda i: i.frequency, reverse=True)

        # 要看次后元素的update_time
        last_one = element_list[-1]
        to_delete_key = last_one.object_key
        if self.capacity > 1:
            # 找出频率和最后一个元素相同的所有元素
            # 按更新时间排序
            frequency_equal_list = [item for item in element_list if item.frequency == last_one.frequency]
            frequency_equal_list = sorted(frequency_equal_list, key=lambda i: i.update_time, reverse=True)
            update_time_min_element = frequency_equal_list[-1]
            # update_time_min_element = frequency_equal_list[0]
            to_delete_key = update_time_min_element.object_key
        self.element_map.pop(to_delete_key)


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

# LFU，要有一个频率，

if __name__ == '__main__':
    cache = LFUCache(2)
    cache.put(2, 1)
    cache.put(3, 2)
    assert cache.get(3) == 2
    assert cache.get(2) == 1
    cache.put(4, 3)
    assert cache.get(2) == 1
    assert cache.get(3) == -1
    assert cache.get(4) == 3

```