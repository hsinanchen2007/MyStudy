## 思路：

对于两个小猪，喝完毒药`15min` 死去，在`1h`最多能检验多个水桶?答案是`25`桶，如下图所示：

![image-20200406172720861.png](https://pic.leetcode-cn.com/f9efb2484b94561b2d69d36c1c15a0aa9a309ef67615ab6692739be0275b044d-image-20200406172720861.png)


对于一只猪，可以在`1h`之内最多喝 `4`次水(`60/15`)，但是可以检验5个桶，如果前四次没死，说明第5个桶有毒。

对于2只猪，现在可以让一只猪一下喝`5`桶水，如图所示的一只猪喝**行**的五个，一只猪喝**列**的五个，这样就可以确定哪个桶有毒。

对于3只猪，就是三维的 5 X 5 X 5 ，可以检测125个桶；

。。。。

## 代码：

```python
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        pigs = 0
        while (minutesToTest // minutesToDie + 1) ** pigs < buckets:
            pigs += 1
        return pigs
```

