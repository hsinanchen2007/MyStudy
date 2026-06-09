题解：
i = 0~len(s)-1
0	存放  idx = i%(2*numRows-2) == 0		
1	存放  idx = i%(2*numRows-2) == 1 or 2*numRows-2-idx	
2	存放  idx = i%(2*numRows-2) == 2 or 2*numRows-2-idx	
3	存放  idx = i%(2*numRows-2) == 3

2*numRows-2 怎么得到的，只要用numRows=4和numRows=3解方程即可 numRows*s+n = xxxx，求x，n
![微信图片_20200113231807.jpg](https://pic.leetcode-cn.com/21811fd7e6a35ad066749137944dfd6777ee2af5dea223c7f6310015bc53dcee-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200113231807.jpg)
```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        result = {}
        if numRows == 1:
            return s
        for i in range(len(s)):
            idx = i % (2 * numRows - 2)
            # process 0,1,...,numRows-1
            if idx < numRows:
                if idx not in result.keys():
                    result.setdefault(idx, []).append(s[i])
                else:
                    result[idx].append(s[i])
            else:
                idx = 2 * numRows - 2 - idx
                result[idx].append(s[i])
        result = result.values()
        res = ""
        for str_str in result:
            res += "".join(str_str)
        return res
```




![捕获.JPG](https://pic.leetcode-cn.com/56291e095b7dc2a23335d808b805b6bf559032f8bc62ee49b4963062daf36148-%E6%8D%95%E8%8E%B7.JPG)
