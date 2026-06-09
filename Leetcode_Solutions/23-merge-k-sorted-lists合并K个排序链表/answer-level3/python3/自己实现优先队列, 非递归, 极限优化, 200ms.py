```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法4, 自己实现优先队列, 非递归形式
    去掉各种冗余计算, 看看到底能优化到多少
    普通优先队列560ms
    用dequeue替换list, 变成360
    插入元素有自己单独的上浮路线, 且有终止条件, 变成260
    递归改成非递归, 存储size, last索引等, 最终变成200ms
"""
from typing import List
from collections import deque
from math import floor


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class PriorityQueue:
    def __init__(self, queue=None):
        self.queue = deque(queue) if queue else deque()
        self.size = len(self.queue)
        self.last = floor(self.size/2-1)
        self.sort()

    def sort(self):
        i = self.last
        while i >= 0:
            self.heapify(i)
            i -= 1

    def heapify(self, i):
        start = i
        while i <= self.last:
            r, im = 2*i+2, i
            l = r-1
            if r < self.size and self.queue[r][0] < self.queue[im][0]:
                im = r
            if self.queue[l][0] < self.queue[im][0]:
                im = l

            if im != i:
                self.queue[im], self.queue[i] = self.queue[i], self.queue[im]
                i = im
            else:
                if i == start:
                    return False
                else:
                    break

        return True

    def resort(self):
        i = self.last
        while i >= 0:
            is_swap = self.heapify(i)
            if not is_swap:
                break
            else:
                i = int((i-1)/2)

    def push(self, val, item):
        self.queue.append((val, item))
        self.size = len(self.queue)
        self.last = floor(self.size/2-1)
        self.resort()

    def pop(self):
        ans = self.queue[0]
        self.queue[0], self.queue[-1] = self.queue[-1], self.queue[0]
        self.queue.pop()
        self.size = self.size-1
        self.last = floor(self.size/2-1)
        self.heapify(0)
        return ans

    def empty(self):
        return True if not self.queue else False


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        pos = ans = ListNode(-1)

        vals = [(l.val, l) for l in lists if l]
        pq = PriorityQueue(vals)
        while not pq.empty():
            v, l = pq.pop()
            pos.next, pos = l, l
            if l.next:
                pq.push(l.next.val, l.next)
        return ans.next
```
