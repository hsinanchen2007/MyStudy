执行结果：
通过
显示详情
执行用时 :
120 ms
, 在所有 python3 提交中击败了
36.42%
的用户
内存消耗 :
13.2 MB
, 在所有 python3 提交中击败了
100.00%
的用户


```
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        if len(trips) == 0:
            return True
        path_end = max([data[2] for data in trips])
        now_passanger = 0
        trips_num = len(trips)
        trips_start = copy.deepcopy(trips)
        trips_end = copy.deepcopy(trips)
        trips_start.sort(key=lambda x: x[1])
        trips_end.sort(key=lambda x: x[2])
        s_id = 0
        e_id = 0
        for now_location in range(path_end + 1):
            for i in range(e_id, trips_num):
                if trips_end[i][2] == now_location:
                    now_passanger = now_passanger - trips_end[i][0]
                elif trips_end[i][2] > now_location:
                    e_id = i
                    break
            for i in range(s_id, trips_num):
                if trips_start[i][1] == now_location:
                    now_passanger = now_passanger + trips_start[i][0]
                elif trips_start[i][1] > now_location:
                    s_id = i
                    break
            if now_passanger > capacity:
                return False
        return True
```
