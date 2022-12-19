### 解题思路
![image.png](https://pic.leetcode-cn.com/a26fbc8a9e2231187c394538bace2d08424dd2774786914c7ca34631fcb793e0-image.png)

tail head 用来判断头尾是不是 0
用累计计数的方法判断 1 与 1 之间有几个零
如果头是 0，则第一遍的计数方法就是 count 值
最后判断如果尾部是 0，则再判断一次最大 dis count 值

### 代码

```python3
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        count = 0
        dis = 0
        head = not seats[0]
        tail = not seats[-1]
        for s in seats:
            if s == 1:
                if head:
                    dis = max(dis, count)
                    head = False
                dis = max(dis, (count + 1) // 2)
                count = 0
            else:
                count += 1
        if tail: dis = max(dis, count)

        return dis

```