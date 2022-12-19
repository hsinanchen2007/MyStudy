![Screenshot from 2020-03-29 13-30-56.png](https://pic.leetcode-cn.com/4cf4cf1fa021e7f73b5e1d6d71f81e2a24747a830e1b109d45e391b3d4eb3dbd-Screenshot%20from%202020-03-29%2013-30-56.png)

```
"""
0. leetcode. 182.周赛03, 5370. 设计地铁系统
1. 这道题在比赛期间没有做出来。比赛结束之后，才写出来的。
2. 第一次提交的时候，没有注释掉print()语句，超时，然后注释掉再提交。双 100%.
 
    首先，看看最后需要的是什么样的结果。
    然后再分析怎样涉及自己的数据结构。
    返回从地铁站 startStation 到地铁站 endStation 的平均花费时间。

user1 = {start_time: 1, end_time: 2, start_pos： a, end_pos: b}
user2 = {start_time: 3, end_time: 4, start_pos： c, end_pos: d}
user3 = {start_time: 3, end_time: 4, start_pos： c, end_pos: d}

    ||
    ||
    ||  # 就变成这个熊样子了。这就类似json了。。。 
    \/

users = {
    user1_id:  {start_time: 1, end_time: 2, start_pos： a, end_pos: b},
    user2_id:  {start_time: 1, end_time: 2, start_pos： a, end_pos: b},
    user3_id:  {start_time: 1, end_time: 2, start_pos： a, end_pos: b},
    user4_id:  {start_time: 1, end_time: 2, start_pos： a, end_pos: b},
}

"""

class UndergroundSystem:
    def __init__(self):
        # 这里是不能给参数的 只能自己来涉及数据结构。
        # 可以自己来设计一种id
        self.users = {}
        self.trip = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        # 记录当前的出发时间。
        if id not in self.users:
            self.users[str(id)] = {"start_pos": stationName, "start_time": t}
            # print(self.users)     # 这里可以显示出所有的出行记录。。。。
        else:
            # 如果这个用户再来的话，那就刷成它的数据。
            self.users[str(id)] = {"start_pos": stationName, "start_time": t}

    # 他一到达，这里就计算它这趟花了多少时间。
    def checkOut(self, id: int, stationName: str, t: int) -> None:  
        trip_name = self.users[str(id)]["start_pos"] + stationName
        trip_cost = t - self.users[str(id)]["start_time"]
        if trip_name not in self.trip:
            self.trip[trip_name] = [trip_cost]     # 用一个元组来保存。
        else:
            self.trip[trip_name].append(trip_cost)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        return sum(self.trip[startStation+endStation]) / len(self.trip[startStation+endStation])


# ************** test start Now!!! ************
u = UndergroundSystem()
u.checkIn(45, "Leyton", 3)
u.checkIn(32, "Paradise", 8)
u.checkIn(27, "Leyton", 10)
u.checkOut(45, "Waterloo", 15)
u.checkOut(27, "Waterloo", 20)
u.checkOut(32, "Cambridge", 22)
x = u.getAverageTime("Paradise", "Cambridge")
print("x", x)

y = u.getAverageTime("Leyton", "Waterloo")
print("y", y)

u.checkIn(10, "Leyton", 24)
t = u.getAverageTime("Leyton", "Waterloo")
print("t", t)

u.checkOut(10, "Waterloo", 38)
z = u.getAverageTime("Leyton", "Waterloo")
print("z", z)
```
