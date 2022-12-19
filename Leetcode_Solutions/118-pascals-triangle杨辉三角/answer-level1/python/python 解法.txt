观察得到，杨辉三角某行的中间元素 ``[1:-1]`` 为其上一行中每两个相邻元素相加得到，而``[0]``和``[-1]``位置都是1，那么，我们给其上一行元素的左右各添一个0，上一行每两相邻元素相加就刚好得到该行元素。如图所示：
![WeChat Screenshot_20200313121228.png](https://pic.leetcode-cn.com/71a62f851a4db6078f2ccf340204dddfda5351dc61214eaf26a66c702b8dc853-WeChat%20Screenshot_20200313121228.png)

代码如下：
```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0: return []
        ans = [[1]]
        for i in range(1, numRows):
            tmp = [0] + ans[i-1] + [0]
            ans.append([tmp[j] + tmp[j+1] for j in range(len(tmp) - 1)])
        return ans
```

