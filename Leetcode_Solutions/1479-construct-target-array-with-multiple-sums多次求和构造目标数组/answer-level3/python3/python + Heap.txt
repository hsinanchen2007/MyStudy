```python
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        # [1,1,1] => [9, 3, 5]
        # target.length <= 5 * 10 ** 4
        # [9, 5, 3]
        # 9 => [1, 5, 3]
        # 5 => [1, 1, 3]
        # 3 => [1, 1, 1]

        # [8, 5]
        # 8 => [3, 5]
        # 5 => [3, 2]
        # 3 => [1, 2]
        # 2 => [1, 1]

        heap = []
        for num in target:
            if num != 1: heapq.heappush(heap, -num)
        sum_arr = sum(target)
        while heap:
            top = abs(heapq.heappop(heap))
            new_node = 2 * top - sum_arr
            if new_node < 1: return False
            sum_arr = sum_arr - top + new_node
            if new_node != 1:
                heapq.heappush(heap, -new_node)
        return True


```