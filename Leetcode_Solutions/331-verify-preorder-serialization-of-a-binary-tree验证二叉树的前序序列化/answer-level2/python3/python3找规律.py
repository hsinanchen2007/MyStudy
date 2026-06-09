### 解题思路
从后往前遍历一个有效节点消耗两个#节点，同时自身也相当于一个#节点，所以综合来说就消耗一个#节点
所以直接用一个变量num储存#的数量即可，从后往前遍历，遇到数字节点num-1,遇到#节点num+1，如果中途num<2，那么直接返回false，最后根据前面的理论num应该等于1
![UC截图20191214214324.png](https://pic.leetcode-cn.com/e6cba31347909e19c380a101c968b5211ce7a97f7da5674ea76a8a19650cc17b-UC%E6%88%AA%E5%9B%BE20191214214324.png)


### 代码

```python3
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        preorder = preorder.split(',')
        num = 0
        for i in range(len(preorder)-1  ,-1,-1):
            if preorder[i] == '#':
                num += 1
            else:
                if num >= 2:
                    num -= 1
                else:
                    return False
        if num != 1:
            return False
        return True
```