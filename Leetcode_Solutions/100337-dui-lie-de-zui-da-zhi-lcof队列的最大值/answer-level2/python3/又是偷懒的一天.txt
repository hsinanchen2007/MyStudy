#我做的有点不符合题意，应该用一个下标记录下最大值得位置，实时更新就可以了。额，好吧，就这样
class MaxQueue:

    def __init__(self):
        self.ls=[]
        self.max_v=-1


    def max_value(self) -> int:
        return self.max_v


    def push_back(self, value: int) -> None:
        if( value > self.max_v):
            self.max_v=value
        self.ls.append(value)


    def pop_front(self) -> int:
        #这边也要实时更新max的值
        if(self.ls == []):
            return -1
        else:
            if(self.ls[1:] == []):
                self.max_v = -1
            else:
                self.max_v=max(self.ls[1:])
            return self.ls.pop(0)




# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()