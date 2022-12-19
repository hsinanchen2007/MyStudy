### 解题思路

首先，最大元素肯定是最后的调用了加法的，所以最大元素减去target当中的其他元素，一定是中间的某个过程。
排序后取最后的元素使用这种方法，生成的差加入到原来target的后面，
如果能够恢复成全为1的状态，那么就可以变，否则不行

### 代码

```python3
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        target = sorted(target)
        while target[-1]>1:
            v = target[-1]
            diff = v - sum(target[:-1])
            if diff<=0:
                return False
            target[-1] = diff
            target = sorted(target)
        return True
```