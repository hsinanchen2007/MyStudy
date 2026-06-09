#### 参考了官方解法，结合限制性条件与回溯
```
#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/6/14 21:04
# @Author  : liuhu
# @Site    : 
# @File    : 0093复原IP地址.py
# @Software: PyCharm
# @github  :https://github.com/Max-Liuhu


class RestoreIpAddress(object):

    def __init__(self, s):
        """
        output为最终符合要求的列表
        segments为存储符合要求的截取部分的列表
        """
        self._s = s
        self.length = len(s)
        self.output, self.segments = [], []

    def is_valid(self, segment):
        """
        1. 截取的部分的整数必须小于或者等于255
        2. 截取部分除非是0否则不可以以0开头
        3. 返回bool
        """
        return int(segment) <= 255 if segment[0] != '0' else len(segment) == 1

    def update_output(self, curr_pos):
        """
        :param curr_pos:
        :return:
        """
        # 最后一个点放置完成后，针对剩余截取部分是curr_pos+1开始
        segment = self._s[curr_pos + 1:self.length]
        # 判断最后剩余部分是否符合
        if self.is_valid(segment):
            self.segments.append(segment)
            print(self.segments)
            self.output.append(".".join(self.segments))
            # 将最后部分删除，然后移动curr_pos，这里需要很好的理解递归
            self.segments.pop()
        # 最后一部分验证不合格，则最为一种递归出口

    def backtrack(self, pre_pos=-1, dots=3):
        """
        1. 有限制条件可知，'.'符号不可以放在头部或尾部之后或者距离上一个'.'三个字符以上，
        所以range(pre_pos + 1, min(self.length - 1, pre_pos + 4))

        """
        for curr_pos in range(pre_pos + 1, min(self.length - 1, pre_pos + 4)):
            segment = self._s[pre_pos + 1:curr_pos + 1]
            if self.is_valid(segment):
                self.segments.append(segment)
                # 这个点为最后一个点则判断是output否可以更新
                if dots - 1 == 0:
                    self.update_output(curr_pos)
                else:
                    # 递归，尝试放入下一个"."
                    self.backtrack(curr_pos, dots - 1)
                # 1. 当update_output中最后一部分验证失败时，回溯时删除截取的部分
                # 2. 在backtrack中验证失败，回溯时，删除截取的部分
                self.segments.pop()

    def result(self):
        self.backtrack()
        return self.output
```