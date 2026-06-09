### 解题思路
方法1：从后往前遍历。第一位单独判断，若carry=1，则结果+1。
判断思路及图表（非严格真值表，方便理解，加了状态列）如下
其中操作通过异或（^）进行判断，进位通过或（or）进行判断：
1.有进位，当前为1，则变成0，操作+1，进位为1；
2.有进位，当前为0，则变成1，操作+2，进位为1；
3.无进位，当前为1，则不变1，操作+2，进位为1；
4.无进位，当前为0，则不变0，操作+1，进位为0；
![image.png](https://pic.leetcode-cn.com/0b98523a8836dcbeda874df748d1afd57221ba9b223391a12bc5859d107b3cc1-image.png)

方法2：转成数字，再做判断，末尾为0，操作数为1；末尾为1，操作数为2。然后，直接+1，移位进入下次判断。

### 代码

```python3
class Solution:
    def numSteps(self, s: str) -> int:
        carry, res = 0, 0
        for i in range(len(s)-1, 0, -1):
            res = res+2 if carry ^ (s[i] == '1') else res+1
            carry = 1 if carry or (s[i] == '1') else 0
        return res+1 if carry else res


        
        # #转数字
        # n = int(s, 2)
        # count = 0
        # while n != 1:
        #     if n&1:
        #         count += 2
        #     else:
        #         count += 1
        #     n = (n+1)>>1
        # return count
```