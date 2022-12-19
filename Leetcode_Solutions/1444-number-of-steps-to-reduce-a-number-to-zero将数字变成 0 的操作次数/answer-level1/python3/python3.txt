### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def numberOfSteps (self, num: int) -> int:
        ans = 0
        while num:
            if num%2==0:
                num//=2
            else:
                num-=1
            ans+=1
        return ans
```
![image.png](https://pic.leetcode-cn.com/3cdf5a44ff8a50a3ed92d9ad294e3d33b34ea745bb8f35f04069ea3fb4cafbed-image.png)
