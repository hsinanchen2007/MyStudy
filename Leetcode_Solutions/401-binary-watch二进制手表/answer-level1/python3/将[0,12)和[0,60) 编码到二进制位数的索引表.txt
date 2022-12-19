### 代码
![深度.JPG](https://pic.leetcode-cn.com/ed4aed36369f4116b3ec8e2e81eee88b45eb0469d082f8b346ec49e7cbd092b5-%E6%B7%B1%E5%BA%A6.JPG)

```python3
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        # Hour: 8 4 2 1
        # range from 0000 to 1011 means 0 to 11
        hset = [[] for _ in range(4)]
        hset[0].append(0)
        for i in range(1, 12):
            cnt = 0
            icopy = i
            while i:
                cnt += i & 1
                i >>= 1
            (hset[cnt]).append(icopy)
        
        # Min : 32 16 8 4 2 1
        # range from 000000 to 111100 means 0 to 59
        mset = [[] for _ in range(6)]
        mset[0].append(0)
        for i in range(1,60):
            cnt = 0
            icopy = i
            while i:
                cnt += i & 1
                i >>= 1
            (mset[cnt]).append(icopy)  
        # total = 4 + 6 digits
        output = []
        if num > 9: return None
        # num = 3 = 3 + 0,2 +1,1+2,0+3
        index = min(num + 1, 4)
        for hd in range(index):
            md = num - hd
            if md <= 5:
                # HD = 0,1,2,3  ^  [0,num]
                # MD = 0,1,2,3,4,5  ^ [0,num]
                for hnum in hset[hd]:
                    for mnum in mset[md]:
                        timestr = str(hnum) + ':' + str(mnum // 10) + str(mnum % 10)
                        output.append(timestr)
        return output
```