### 解题思路
用哈希表存储数字及出现的次数，然后从0查起（此处存疑，如果输出的数字是比较大的数，花费的时间会比较多），提取k个值

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        count=collections.Counter(arr)

        i=0
        j=0
        results=[]
        while j<k:
            if count[i] != 0:
                results+=[i]
                count[i] -= 1
                j+=1
            else:
                i+=1

        return results

```