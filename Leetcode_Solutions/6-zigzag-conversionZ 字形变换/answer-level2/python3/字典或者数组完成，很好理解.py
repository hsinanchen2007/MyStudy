发现其中的规律，求余数来判断究竟应该在哪里。
仔细细心，耐心推导
```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s
        res = [0 for _ in range(len(s))]
        # 判断这个字符应该在哪个位置
        # numRows+2 为一组
        n = 2*numRows-2
        from collections import defaultdict
        tmp = defaultdict(list)
        tmp = [[] for _ in range(numRows+1)]
        for k,v in enumerate(list(s)):
            # k=k+1
            # print(k,v)
            if k %n>numRows-1:
                # print(k,v,2*numRows-k%n)
                tmp[2*numRows-2-k%n].append(v)
            else:
                tmp[k%n].append(v)
        res = []
        for i in tmp:
            res+=i
        # for i,j in tmp.items():
        #     print(i,j)
        #     res+=j
        return "".join(res)
```
