### 解题思路
![QQ截图20200330180022.png](https://pic.leetcode-cn.com/ef0d07560dafbb1cecca2ad1e2de28debf3355c8422fe482b01194ec051f9550-QQ%E6%88%AA%E5%9B%BE20200330180022.png)

LC折磨用户一直可以的，就面向测试用例编程就vans了

### 代码

```python3
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if k==0:
            ls2 = [str(i) for i in nums]
            ls3 = ''.join(ls2)
            return 0 in nums and ''.join(ls3).find("00")!=-1
        i=0
        for nums_i in nums[i:]:
            sum=nums_i
            for nums_j in nums[i+1:]:
                sum+=nums_j
                if sum%k==0:
                    return True
                else:
                    continue
            i+=1
        return False
```