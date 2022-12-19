### 解题思路

找到每一行需要做计算的每一列，每一列的值为上一行相同列与前一列的值之和，每一行首列与尾列均为1。
![WeChat Screenshot_20191212145754.png](https://pic.leetcode-cn.com/4488e1648eacbb3e673aed2cfc619e999a82ef02bf8e67035b8d22bc93d8434f-WeChat%20Screenshot_20191212145754.png)

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows<3:
            return [[1]* n for n in range(1,numRows+1)] #小于3则没有需要单独做加法的列

        res = [[1], [1, 1]] #创建不需要做计算的前两行
        for n in range(1, numRows-1):# 每一行需要做计算的列数（大于3）
            lst = [1]#第一列
            for x in range(1, n+1):#需要添加的每一列的索引
                num = res[n][x]+res[n][x-1]#上一行x列与x-1列的和即为下一列x列的值
                lst.append(num)#添加至临时列中
            lst.append(1)#添加尾列
            res.append(lst)#添加拼接好的行
        return res
        
```