性能和内存并非最优，但是逻辑简单易懂
1. 变成一个set表
2. 从其中随机取一个数。
3. 先往后找是否存在。
4. 然后往前找是否存在。
5. 再比较max_ans即可
```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        all_set = set(nums)
        max_ans = cur_ans = 0

        while len(all_set)>0:
            node = all_set.pop()
            cur_ans = 1
            next_node = node + 1
            while next_node in all_set:
                all_set.remove(next_node)
                cur_ans += 1
                next_node += 1
            
            next_node = node -1 
            while next_node in all_set:
                all_set.remove(next_node)
                cur_ans += 1
                next_node -= 1
            
            max_ans = max(max_ans, cur_ans)
        
        return max_ans
```
