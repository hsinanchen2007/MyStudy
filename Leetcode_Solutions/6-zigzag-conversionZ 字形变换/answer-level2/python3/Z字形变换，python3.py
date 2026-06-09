### 解题思路
定义一个列表res存储每一行的结果
定义变量line=0来存储当前字符应该往哪一行后面加
定义plus=True来确定当前时刻line是该增加还是该减少
遍历输入字符串s
- 如果plus==True:
1. 现在res中的第line后添加当前字符
2. 把line加一
3. 如果line已经超过了res的索引范围
4. 就把line减二，即定位到line中的倒数第二个元素，plus修改为False，倒着修改res
- 如果plus==False：
1. 现在res中的第line后添加当前字符
2. 把line减一
3. 如果line已经超过了res的索引范围
4. 就把line加二，即定位到line中的正数第二个元素，plus修改为True，正着修改res

最后返回res中元素的累加

时间O(N)
空间O(N)



### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        res = ['' for _ in range(numRows)]
        line = 0
        plus = True
        for i in s:
            if plus:
                res[line] += i
                # print(line)
                line += 1
                if line >= numRows:
                    line -= 2
                    plus = False
            else:
                res[line] += i
                # print(line)
                line -= 1
                if line < 0:
                    line += 2
                    plus = True
        k = ""
        # print(res)
        for j in res:
            k += j
        return k
            
```