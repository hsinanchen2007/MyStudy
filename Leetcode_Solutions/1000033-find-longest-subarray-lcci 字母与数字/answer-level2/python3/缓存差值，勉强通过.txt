### 解题思路
此处撰写解题思路
![14.png](https://pic.leetcode-cn.com/3bfb11b34cecc8805de0b141e76e115cbfd482a822f8acf2b6e28dbc528712b3-14.png)
buff[0] 存字母数量
buff[1] 存数字数量
每一位存 0到j 的字母数量与数字数量的差值
差值为0即为字母数字数量相同
0~j 位差值减去 0~i 位差值 即为 i~j位的差值

### 代码

```python3
import bisect
class Solution:
    def findLongestSubarray(self, array: List[str]) -> List[str]:
        ret = list()
        size = len(array)
        if size <= 0:return ret
        buff = [0,0]
        arr = []
        iarr = []
        for i in range(size):
            n = 1 if array[i].isdigit() else 0
            iarr.append(n)
            buff[n] += 1
            arr.append((buff[0]-buff[-1],i))
        if buff[0]== 0 or buff[-1] == 0:return []
        arr.sort()
        pos = 0
        mxlen=0
        for j in range(size-1,-1,-1):
            if j+1 < mxlen:break
            ca = buff[0]-buff[-1]
            idx = bisect.bisect_left(arr,(ca,0))
            i = 0 if ca == 0 else arr[idx][1]+1
            ca = 0 if ca==0 else ca-arr[idx][0]
            ijlen = j-i+1
            if ijlen >= mxlen and ca == 0:
                pos = i
                mxlen = ijlen
            buff[iarr[j]] -= 1
        return array[pos:pos+mxlen]
```