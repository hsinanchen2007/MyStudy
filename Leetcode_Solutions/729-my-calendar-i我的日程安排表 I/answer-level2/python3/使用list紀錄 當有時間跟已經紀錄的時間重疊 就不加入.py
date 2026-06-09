### 解题思路
使用list紀錄 當有時間跟已經紀錄的時間重疊 就不加入

### 代码

```python3
class MyCalendar:

    def __init__(self):
        self.vec = list()

    def book(self, start: int, end: int) -> bool:
        end -= 1
        for i in self.vec:
            # print(self.vec)
            item1 = i[0] <= start <= i[1] or i[0] <= end <= i[1]
            item2 = start <= i[0] <= end or start <= i[1] <= end
            if item1 or item2 :
                return False
        self.vec.append([start, end])
        return True                


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
```