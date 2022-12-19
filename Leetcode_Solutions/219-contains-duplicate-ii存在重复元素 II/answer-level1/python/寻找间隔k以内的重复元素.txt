### 解题思路
下面拿样例的数据说明思路：
nums = [1,2,3,1], k = 3
首先我的第一思路是切片，当i=0时，切片索引是[i+1:i+k+1]，但是这种方式的时间复杂度比较高，后台的最后两组样例的数据集非常大，无法满足需要。
接下来尝试建哈希表的方式，其实用key-value对的形式就可以建立哈希表。
1. 首先排除特殊情况，当k==0或者len(nums)==0时，直接返回False；
2. 然后从首元素开始逐个判断元素值是否存在于key-value中的keys里面，如果不存在，创建新的key-value对，key是元素值，value是当前索引；
3. 如果存在keys与当前元素值相等，并且当前元素值的索引与key-value中的value(存的是前一个相等值对应的下标索引)的绝对差值小于等于k，直接返回T
4. 否则（绝对差值大于k），**更新key-value对中当前元素值的最新下标索引**，继续往后找

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        if k==0 or len(nums)==0:
            return False
        for i in range(len(nums)):
            if nums[i] not in d.keys():
                d[nums[i]] = i
            elif nums[i] in d.keys() and abs(d[nums[i]] - i)<=k:
                return True
            elif nums[i] in d.keys() and abs(d[nums[i]] - i)>k:
                d[nums[i]]=i
        return False


```