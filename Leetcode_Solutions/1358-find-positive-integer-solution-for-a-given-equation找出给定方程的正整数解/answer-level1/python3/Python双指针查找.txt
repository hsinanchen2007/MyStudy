题目给的条件是1 <= x, y <= 1000，但是感觉这个范围太大了，看其他人也都是用的这个范围，就试着把右端的值改为z，然后发现能够运行，并且提交四次都是32ms，超过95.31%……
同时，代码中有两个注意点：
        1.循环终止条件需要为：x <= z and y >= 1，本来想用 x <= y的，但是发现好几个测试案例都不通过。
        2.ret.extend([[x, y]]) 之后要 x += 1, y += 1， 否则会出现死循环。
```
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        ret = []
        x, y = 1, z
        while x <= z and y >= 1:
            temp = customfunction.f(x, y)
            if temp < z:
                x += 1
            elif temp > z:
                y -= 1
            else:
                ret.extend([[x, y]])
                x += 1
                y -= 1
        return ret
```
