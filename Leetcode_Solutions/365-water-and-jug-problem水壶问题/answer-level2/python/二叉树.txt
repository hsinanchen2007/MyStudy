### 解题思路
代码没做优化

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z== x or z==y:
            return True
        small = (x if x<=y else y)
        big = (x if x>y else y)
        root = big - small
        rs = set()
        rs.add(0)
        rs.add(small)
        rs.add(big)
        rs.add(root)
        rs.add(small+big)
        rs.add(small+root)
        rs.add(big+root)
        while 1:
            tmp1 = abs(small - root)
            tmp2 = abs(big - root)
            if tmp1 == z or tmp2 == z:
                return True
            else:
                if tmp1 not in rs:
                    rs.add(tmp1)
                    rs.add(tmp1+small)
                    rs.add(tmp1+big)
                    root = tmp1
                    continue
                if tmp2 not in rs:
                    rs.add(tmp2)
                    rs.add(tmp2+small)
                    rs.add(tmp2+big)
                    root = tmp2
                    continue
                break
        print(rs)
        return (z in rs)
            

```