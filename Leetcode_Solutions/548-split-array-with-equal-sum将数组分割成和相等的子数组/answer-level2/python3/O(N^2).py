### 解题思路
1. 计算累加和数组prefix，prefix每一项等于数组前面所有所有数字的和
2. 找出所有的i,k对，使得前i项和等于后k项和
    - 可以把prefix中的和放到一个map中，通过遍历一边prefix就可以得到所有的i,k对
3. 对于每一个i，k对，在i，k中间查找是否有符合条件的j

找出i,k对的时间复杂度最坏是：O(N^2)
遍历i,k对时间复杂度：O(N^2)
总时间复杂度：O(N^2)

### 代码

```python3
class Solution:
    def splitArray(self, arr: List[int]) -> bool:
        prefix = arr[::]
        for i in range(1, len(arr)):
            prefix[i] += prefix[i-1]

        mapsum = collections.defaultdict(list)
        for i in range(len(prefix)):
            mapsum[prefix[i]].append(i)

        # find pairs
        pairs = []
        for k in range(5, len(arr)):
            val = prefix[-1]-prefix[k] 
            pairs += [(i+1, k) for i in mapsum[val] if i+5 <= k]
            
        for i, k in pairs:
            for j in range(i+2, k-1):
                if prefix[i-1] == prefix[j-1]-prefix[i] == prefix[k-1]-prefix[j]:
                    return True
        return False
```