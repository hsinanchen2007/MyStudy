优点：思路简单直观
缺点：O(n)次if语句的比较，比较耗时
思路：
1.设置all_list存储numRows个列表，代表Z型的每一行
2.遍历s，遍历到的字符加入对应的all_list[index]中。注意：all_list[index]也是一个列表
3.现在得到all_list中每个元素是一个存放了Z型的一行元素的列表
4.小技巧：利用一个改变index的方向来对index进行增或者减，python中True和False可当作1和0参与运算

```python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        
        all_list = [[] for _ in range(numRows)]
        
        j = 0
        direct_down = True
        for i in range(len(s)):
            all_list[j].append(s[i])

            if j == 0: 
                direct_down = True
            elif j == numRows-1:
                direct_down = False
            j += direct_down*2-1 # 利用方向进行增减（True转为1，False转为-1）

        all_str = ''
        for i in range(numRows):
            all_str += ''.join(all_list[i])
        return all_str

```





