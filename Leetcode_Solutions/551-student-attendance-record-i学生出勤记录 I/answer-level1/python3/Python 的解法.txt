### 解题思路
为Fasle 的情况
 ‘A’ 大于1 的情况为False  或则  ‘L’连续出现3次或则3次以上
1. 统计‘A’ 出现的次数
2. 'LLL' in s 判断是否包含2个以上的'L'

### 代码

```python3
class Solution:
    def checkRecord(self, s: str) -> bool:
        ca = 0
        for i in s:
            if i == 'A':
                ca +=1
        if 'LLL' in s or ca >1:
            return False
        else:
            return True
```
![屏幕快照 2020-02-11 21.27.44.png](https://pic.leetcode-cn.com/d8e1a5e38b2545e2a57a64db36d5f2d606e1b46028501671d585f7fb0dd5e017-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-11%2021.27.44.png)
