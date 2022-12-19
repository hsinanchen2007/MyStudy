找出每个数的唯一标识即可，写的比较繁琐
```
class Solution:
    def originalDigits(self, s: str) -> str:
        res = {}
        for i in s:
            if res.get(i):
                res[i] += 1
            else:
                res[i] = 1
        if res.get('z'):             #0 : z
            res['r'] -= res['z']
            res['o'] -= res['z']
        if res.get('w'):             #2 : w
            res['t'] -= res['w']
            res['o'] -= res['w']
        if res.get('u'):             #4 : u; 1 : o; 3 : r; 5 : f; 
            res['f'] -= res['u']
            res['o'] -= res['u']
            res['r'] -= res['u']
        if res.get('o') and res['o'] > 0:
            res['n'] -= res['o']
        if res.get('f') and res['f'] > 0:   #7 : v
            res['v'] -= res['f']
        if res.get('r') and res['r'] > 0:   #8 : t
            res['t'] -= res['r']
        if res.get('v') and res['v'] > 0:   #6 : s; 9 : n
            res['s'] -= res['v']
            res['n'] -= res['v']
        num = ''
        if res.get('z'):
            num += '0'*res['z']
        if res.get('o'):
            num += '1'*res['o']
        if res.get('w'):
            num += '2'*res['w']
        if res.get('r'):
            num += '3'*res['r']
        if res.get('u'):
            num += '4'*res['u']
        if res.get('f'):
            num += '5'*res['f']
        if res.get('s'):
            num += '6'*res['s']
        if res.get('v'):
            num += '7'*res['v']
        if res.get('t'):
            num += '8'*res['t']
        if res.get('n'):
            num += '9'*(res['n']//2)
        return num
```
