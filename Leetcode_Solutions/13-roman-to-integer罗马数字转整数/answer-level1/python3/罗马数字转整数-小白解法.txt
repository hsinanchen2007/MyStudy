### 解题思路
执行用时 :64 ms 内存消耗 :12.8 MB

思路：
列表和字典的使用相结合
对特例的判断条件过于简单粗暴，重复内容过多，待优化

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        romanstrlist = []
        for i in str(s):
            romanstrlist.append(i)
        rawstr = ["I","V","X","L","C","D","M"]
        rawvalue = [1,5,10,50,100,500,1000]
        trans_dict = dict(zip(rawstr,rawvalue))
        value = 0
        for i in range(len(romanstrlist)):
            if i + 1 < len(romanstrlist):
                if trans_dict[romanstrlist[i]] >= trans_dict[romanstrlist[i+1]]:
                    value += trans_dict[romanstrlist[i]]
                elif romanstrlist[i] == "I" and romanstrlist[i+1] == "V" or "X":
                    value += ~trans_dict[romanstrlist[i]] + 1
                elif romanstrlist[i] == "X" and romanstrlist[i+1] == "L" or "C":
                    value += ~trans_dict[romanstrlist[i]] + 1
                elif romanstrlist[i] == "C" and romanstrlist[i+1] == "D" or "M":
                    value += ~trans_dict[romanstrlist[i]] + 1
            else:
                value += trans_dict[romanstrlist[i]]
        return value
```