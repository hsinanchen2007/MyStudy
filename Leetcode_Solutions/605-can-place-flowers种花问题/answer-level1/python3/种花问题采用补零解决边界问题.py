### 解题思路
（1）参考大佬的首尾补零可以有效解决边界问题
（2）再对每个单位两侧判断是否存在间隔即可

### 代码

```python
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        # 前后补零解决边界问题
        nums=[0]+flowerbed+[0]
        cnt=0
        i=1
        while i<len(flowerbed)+1:
            if nums[i-1]==0 and nums[i]==0 and nums[i+1]==0:
                cnt += 1
                # 可以种花，则需要间隔一个位置，所以+2
                i += 2
            else:
                i+=1
                
        return cnt>=n

```