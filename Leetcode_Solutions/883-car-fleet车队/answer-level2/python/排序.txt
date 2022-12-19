后车到达时间>前车到达时间则形成新的车队，为方便处理，将
```
def carFleet(self, target, position, speed):
    """
    :type target: int
    :type position: List[int]
    :type speed: List[int]
    :rtype: int
    """
    if not position:
        return 0
    # 车位置和速度匹配，并排序前后车
    cars = [i for i in zip(position, speed)]
    cars.sort(key=lambda x: x[0], reverse=True)
    
    count = 0
    front_arrive_time = float('-inf')
    # 前车先出发，到达时间大于后车到达时间，则形成一个车队
    # 否则更新到达时间，count+1
    for car in cars:
        behind_arrive_time = float(target - car[0]) / car[1]
        if behind_arrive_time > front_arrive_time:
            count += 1
            front_arrive_time = behind_arrive_time

    return count
```
