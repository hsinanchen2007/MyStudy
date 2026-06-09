利用自动状态机来判断求解:
只用遍历一次
```
class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        max_range = -1
        current_range = 0
        for i in range(len(seats)):
            if i == 0:
                if seats[i] == 0:
                    state = '1'
                    counter = 1
                    continue
                else:
                    state = '2'
                    continue
            if state == '1':
                if seats[i] == 0:
                    counter += 1
                    continue
                else:
                    current_range = counter
                    counter = 0
                    if current_range > max_range:
                        max_range = current_range
                    state = '2'
                    continue
            if state == '2':
                if seats[i] == 0:
                    state = '3'
                    counter = 1
                    continue
                else:
                    continue
            if state == '3':
                if seats[i] == 0:
                    counter += 1
                    continue
                else:
                    current_range = int(math.ceil(counter/2))
                    counter = 0
                    if current_range > max_range:
                        max_range = current_range
                    state = '2'
                    continue
        if state == '3':
            current_range = counter
            if current_range > max_range:
                max_range = current_range
        return max_range
```
图片如下,字体还请不要吐槽
![Leetcode 2.png](https://pic.leetcode-cn.com/83d9798ceab5fb94b76d48a27642015be1dcd226ddebc618714eae43240502aa-Leetcode%202.png)
