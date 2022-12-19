先确定二进制数最多能到几位（n表示位数），再找到小于等于n的所有质数，组成列表l，在依次判断每一个数的二进制数的1的数量即可。
```
class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        n = len(bin(R))-2
        count = 0
        l = list(filter(lambda x: not [x%i for i in range(2, int(math.sqrt(x))+1) if x%i ==0], range(2,n+1)))
        for i in range(L,R+1):
            s = bin(i)[2:]
            a = s.count('1')
            if a in l:
                count += 1
        return count
```

也可以这样，题目最多只有20位的二进制数，直接找出20以内的质数也行
```
def countPrimeSetBits(L, R):
    count = 0
    zhishu = [0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1]
    for i in range(L,R+1):
        s = bin(i)
        a = s.count('1')
        if zhishu[a] == 1:
            count += 1
    return count

```
