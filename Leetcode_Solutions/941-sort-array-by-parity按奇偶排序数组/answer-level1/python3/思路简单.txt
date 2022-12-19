### 解题思路
扫描列表，偶数插入新列表的第一个位置，基数append到另一个空列表，最后整合
![WeChat Screenshot_20191205135712.png](https://pic.leetcode-cn.com/e9961b00372b498e4a1f02295a0d3d7d671cec3dacd3512667980f523ef11f4d-WeChat%20Screenshot_20191205135712.png)


### 代码

```python3
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        ret = []
        _ret = []
        for num in A:
            if num % 2 == 0:
                ret.insert(0, num)
            else:
                _ret.append(num)
        ret.extend(_ret)
        return ret
```