class Solution:
    def reverse(self, x: int) -> int:
        t = abs(x)
        y = str(t)
        z = y[::-1]
        if z[0] == 0:
            z = z[1::1]
        else:
            z = z
        if x >= 0:
            z = eval(z)
        else:
            z = -1 * eval(z)
        if z < -2**31 or z > 2**31-1:
            return 0
        else:
            return z 