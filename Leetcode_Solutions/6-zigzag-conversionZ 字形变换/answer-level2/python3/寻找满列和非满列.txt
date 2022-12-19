竖列每一列都是numRows个元素, 而其它列都是只有一个元素, 因此每次更新到满列时，从s中取numRows个元素,
而到非满列时只取一个元素
使用一个level记录更新到哪一列, i标记运行到了s中的哪个元素
```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        """
           下面的算法时间复杂度是O(N), 空间复杂度也是O(N)
           
        """
        if numRows == 0 or numRows == 1:
            return s
        if len(s) <= numRows:
            return s
        dp = [[] for _ in range(numRows)]
        # 第一层元素先安排满
        for k in range(numRows):
            dp[k].append(s[k])
        
        # 后面每一次都是从第二列开始统计
        level = 2
        i = numRows
        while True:
            # 停止循环的条件
            if i >= len(s):
                break
            # 当用到满列时，取numRows元素
            if level == numRows:
                for k in range(numRows):
                    dp[k].append(s[i])
                    i+=1
                    if i >= len(s):
                        break
                # 这里要记得更新level,使得重新从非满列开始算
                level = 2
            else:
                dp[numRows-level].append(s[i])
                i += 1
                level += 1
        
        final_str = ""
        for i in range(numRows):
            final_str += "".join(dp[i])
        
        return final_str
```
