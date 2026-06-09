![image.png](https://pic.leetcode-cn.com/c9fa384371fd3a4a29df864b2b6e62399d7ffcefe3775a86a59a7b6b134e3d2c-image.png)


```
'''
自己维护一个数据缓存即可
'''

def read4(self, buf):
    return 0

class Solution:

    def __init__(self):
        self.data_buf = []

    def read(self, buf, n):
        target = min(len(buf), n)
        data = ['' for _ in range(4)]

        while len(self.data_buf) < target:
            read_num = read4(data)
            self.data_buf.extend(data[:read_num])

            if read_num < 4:
                break

        if len(self.data_buf) >= target:
            for i in range(target):
                buf[i] = self.data_buf[i]
            self.data_buf = self.data_buf[target:]
            return target
        else:
            ret = len(self.data_buf)
            for i in range(len(self.data_buf)):
                buf[i] = self.data_buf[i]
            self.data_buf = []
            return ret

```
