```
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr_length = len(arr)
        if arr_length < 2:
            return True

        count, ret, arr = 1, [], sorted(arr)
        for i in range(1, arr_length):
            if arr[i] == arr[i-1]:
                count += 1
            else:
                if count in ret:
                    return False
                ret.append(count)
                count = 1
            
        return count not in ret
