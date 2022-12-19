注意permutations是根据位置进行排列，所以若题目没有"无重复"条件的话需要先set

```
def permute(self, nums: List[int]) -> List[List[int]]:
        return list(itertools.permutations(nums, len(nums)))
```
