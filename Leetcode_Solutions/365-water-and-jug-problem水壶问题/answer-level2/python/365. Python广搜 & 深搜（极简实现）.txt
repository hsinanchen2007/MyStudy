### 解题思路
对于搜索问题当然想到的就是深搜和广搜，那么实现深搜或者广搜的重点在于找到**状态转移方法**，那么对于这道题的状态转移一共有6种：
（1）将1壶灌满
（2）将2壶灌满
（3）将1壶清空
（4）将2壶清空
（5）将1壶倒入2壶
（6）将2壶倒入1壶

在具体实现上想说明两点：
（1）为了防止死循环，应该记录所到达过的状态。因为本质上这个问题是图搜索，避免环的出现。有很多题解说这是为了剪枝，我觉得也可以这么理解。
（2）**不需要加入各种判断**。个人愚见 如果加入判断能够有效剪枝或者防止避免出现环，那么这个判断是必要的，但是加了这个判断并不会对运行时间有大幅减少的话，比如说像这道题，大量的判断使得代码又长又丑，显得很臃肿，而因为我们记录了之前的状态，所以即使不判断，也只会多一次递归并返回。

注：如果使用深搜会超时。

### 代码

```python
class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if z > x + y:
            return False
        queue = [(0, 0)]
        mem = set()
        while len(queue):
            if queue[0] not in mem:
                x_store, y_store = queue[0]
                if x_store == z or y_store == z or x_store + y_store == suoyiz:
                    return True
                mem.add((x_store, y_store))
                queue.append((x, y_store))
                queue.append((x_store, y))
                queue.append((0, y_store))
                queue.append((x_store, 0))
                queue.append((max(0, x_store - (y - y_store)), min(y, y_store + x_store)))
                queue.append((min(x, x_store + y_store), max(0, y_store - (x - x_store))))
            del queue[0]
        return False

        

    def canMeasureWater_2(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if z > x + y:
            return False
        mem = set()
        def get_res(x_store, y_store):
            if (x_store, y_store) in mem:
                return False
            print(x_store, y_store)
            if x_store == z or y_store == z or x_store + y_store == z:
                return True
            mem.add((x_store, y_store))
            res = get_res(x, y_store) or \
                  get_res(x_store, y) or \
                  get_res(0, y_store) or \
                  get_res(x_store, 0) or \
                  get_res(max(0, x_store - (y - y_store)), min(y, y_store + x_store)) or \
                  get_res(min(x, x_store + y_store), max(0, y_store - (x - x_store)))
            return res
        return get_res(0, 0)
```