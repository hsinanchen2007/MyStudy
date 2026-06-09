class MyCalendar:

    def __init__(self):
        self.l = []

    def book(self, start: int, end: int) -> bool:
        index_s = bisect.bisect_right(self.l, start)
        index_e = bisect.bisect_left(self.l, end)
        if index_s == index_e and index_s % 2 == 0:
            self.l.insert(index_s, end)
            self.l.insert(index_s, start)
            return True
        return False

使用一个有序list存储，每次成功插入都是成对插入（start end）
使用bisect查询要插入的位置，start重复取右，end重复取左
能成功插入的条件为：index_start = index_end = 偶数（即在某start end对后）