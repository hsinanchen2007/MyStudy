嘿嘿
 ```
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        """
        :type sx: int
        :type sy: int
        :type tx: int
        :type ty: int
        :rtype: bool
        """
        while 1:
            if tx==sx and ty==sy:
                return True
            if tx<sx or ty<sy:
                return False
            if tx==sx:
                if (ty-sy)%tx==0:
                    return True
            if ty==sy:
                if (tx-sx)%ty==0:
                    return True
            if tx>ty:
                tx=tx-ty*((tx-ty)//ty+1)
            else:
                ty=ty-tx*((ty-tx)//tx+1)
```