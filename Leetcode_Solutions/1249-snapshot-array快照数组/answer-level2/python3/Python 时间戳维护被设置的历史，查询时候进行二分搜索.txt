![image.png](https://pic.leetcode-cn.com/62452552a2abeb43d44b6ac1655d0f95edebab4103283e6e2faf8a836b1adfb1-image.png)


```
'''
时间戳维护数值被设置的历史过程，查询时候
根据时间戳二分查找
'''


class SnapshotArray:

    def __init__(self, length: int):
        self.__time_stamp = 0
        self.__snap_num = 0
        self.__snap = {}        # key是快照idx, value是快照的时间戳
        self.__data = {}        # key是数据的键， 值是数据的时间戳和数值二元组

        for i in range(length):
            self.set(i, 0)

    def set(self, index: int, val: int) -> None:
        self.__time_stamp += 1
        if index not in self.__data:
            self.__data[index] = []
        self.__data[index].append((self.__time_stamp, val))


    def snap(self) -> int:
        self.__time_stamp += 1
        self.__snap[self.__snap_num] = self.__time_stamp
        self.__snap_num += 1
        return self.__snap_num - 1


    def get(self, index: int, snap_id: int) -> int:
        self.__time_stamp += 1

        snap_time_stamp = self.__snap[snap_id]
        buf = self.__data[index]
        l, r = 0, len(buf)-1
        ans = 0
        while l <= r:
            mid = l + (r - l) // 2
            if buf[mid][0] <= snap_time_stamp:
                ans = buf[mid][1]
                l = mid + 1
            else:
                r = mid - 1
        return ans
```
