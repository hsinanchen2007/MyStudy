### 解题思路
描述的比较晦涩，给出的列表可以看做是，被开的灯的编号需要的答案是要给出亮出灯都是蓝灯的次数。每一个值都是一次操作

>>1.仍然是一个动态规划问题，迭代考虑左右的情况，为了方便code做一个对应列表设置-1,0,1三个flag分别对应off,on,blue.loop 的时候分别改变可能受影响的灯的情况.    第一个思路比较清晰但是超时了.
>>2.最后一个是看了一下，别人的思路逆向思维，观察可知如果已开灯的编号不是连续的那么一定，有已开灯并且未变蓝色的情况，
>>实现就是编号和已开灯数目比较，相等则满足
### 代码


```python3
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
            light_list = [-1 for _ in light]
            light_list.append(2)
            index_list = [i-1 for i in light]
            count = 0
            # 注意一个问题i是编号，先转化为索引
            # 局部最优解就是整体最优解，一盏灯亮了检查前一栈和后一盏
            # 为了遍历的方便差个尾值？
            for i in index_list:
                light_list[i] = 1 if i == 0 or light_list[i-1] >= 0 else 0
                light_list[i + 1] = 1 if light_list[i+1] == 0 else light_list[i + 1]
                if light_list.count(1) == light_list.count(1)+light_list.count(0):
                    count += 1
            return count
```
```python3
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        light_list = [-1 for _ in light]
        light_list.append(2)
        index_list = [i-1 for i in light]
        count = 0
        # 注意一个问题i是编号，先转化为索引
        # 局部最优解就是整体最优解，一盏灯亮了检查前一栈和后一盏
        # 为了遍历的方便差个尾值？
        sum_of_light = 0
        sum_of_blue = 0
        for i in index_list:
            sum_of_light += 1
            if i == 0 or light_list[i-1] >= 0:
                light_list[i] = 1
                sum_of_blue += 1
            else:
                light_list[i] = 0
            if light_list[i+1] == 0:
                light_list[i + 1] = 1
                sum_of_blue += 1
            if sum_of_light == sum_of_blue:
                count += 1
        return count
```

```python3
class Solution:
    def numTimesAllBlue(self, light: [int]) -> int:
        now_sum = cnt = max_num = 0
        for i, v in enumerate(light):
            now_sum += 1
            max_num = max(v, max_num)
            if max_num == now_sum:
                cnt += 1
        return cnt
```
