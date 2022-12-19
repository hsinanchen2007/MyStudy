```python
class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        dic = collections.defaultdict(set)

        for point in points:
            x, y = point
            dic[y].add(x)
        axis = None
        # Time complexity : O(NlogN)
        # Space complexity: O(N)
        def getReflectAxis(x_arr):
            x_arr = sorted(x_arr)
            l, r = 0, len(x_arr) - 1
            axis = None
            while l <= r:
                tmp_axis = (x_arr[l] + x_arr[r]) / 2
                if axis is None: axis = tmp_axis
                elif tmp_axis != axis: 
                    return (False, 0)
                l += 1
                r -= 1
            return (True, axis)

        for key in dic:
            flag, tmp_axis = getReflectAxis(dic[key])
            if not flag: return False
            if axis is None: axis = tmp_axis
            elif tmp_axis != axis: return False
        return True



```