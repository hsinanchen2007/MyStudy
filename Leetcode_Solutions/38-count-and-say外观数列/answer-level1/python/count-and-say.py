### 解题思路

函数next_num用来计算下一个数字，调用这个函数n-1次，就能计算出第n个数


### 代码

```python3

class Solution:
    def next_num(self, n:str):
        cnt = 0
        ret = ''
        for c in n: 
            if cnt==0: 
                last_c = c
                cnt = 1
            else: 
                if last_c==c: 
                    cnt += 1
                else: 
                    ret += "%d%c" % (cnt, last_c)
                    cnt = 1
                    last_c = c
        if cnt!=0: 
            ret += "%d%c" % (cnt, last_c)
        return ret

    def countAndSay(self, n: int) -> str:
        i = 1
        ret = "1"
        while i<n: 
            ret = self.next_num(ret)
            i += 1
        return ret




```