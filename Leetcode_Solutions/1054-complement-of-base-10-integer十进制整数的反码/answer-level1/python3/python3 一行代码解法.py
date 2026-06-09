### 运行结果
![捕获.PNG](https://pic.leetcode-cn.com/38c374ed40418f42cfea9ec3991e2324cfca7fe8322737a3b3c8dff6ba079fc8-%E6%8D%95%E8%8E%B7.PNG)

### 解题思路
1. 转为2进制，取[2:]
2. 1，0 倒换
3. 转为10进制

### 代码

```python3
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        return int(bin(N)[2:].replace('1','#').replace('0','1').replace('#','0'),2)

```