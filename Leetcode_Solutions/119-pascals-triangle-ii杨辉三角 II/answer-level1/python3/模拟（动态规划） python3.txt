# 题解
$O(k)$空间复杂度，我们在[118.杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/solution/mo-ni-fa-dong-tai-gui-hua-po-shi-de-xie-fa-python3/)基础上进行优化，仅保存上一行。
## 模拟法（动态规划）

 1. 特判，若$k==0$，返回$[1]$
 2. 初始化$dp=[1,1]$，表示第二行
 3. 遍历区间$[3,k+2)$，表示从第三行开始遍历：
 	* 初始化$cur=[1,0,...,0,1]$，长度为当前行数
 	* 从$cur$第二个元素到倒数第二个元素，利用动态规划：$cur[j]=dp[j-1]+dp[j]$
 	* 将$dp$更新为$cur$
 5. 返回$dp$

### 复杂度分析
 - 时间复杂度：$O(k^{2})$，等差数列求和。
 - 空间复杂度：$O(k)$。

### Python

```python
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if(rowIndex==0):
            return [1]
        dp=[1,1]
        for i in range(3,rowIndex+2):
            cur=[0]*(i)
            cur[0]=cur[-1]=1
            for j in range(1,i-1):
                cur[j]=dp[j-1]+dp[j]
            dp=cur
        return dp
```