```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        array = [i for i in range(1,n+1)]
        if k == 1:
            return ''.join([str(i) for i in array])
        def core(array, k):
            if k == 1:
                return array
            l = len(array)
            mlt = 1
            left_rest = 1
            while not mlt < k <= mlt*(left_rest+1):
                left_rest += 1
                mlt *= left_rest
            first = 1
            while mlt*first < k:
                first += 1
            tmp = array[-(left_rest+1):]
            t = tmp[0]
            tmp[0] = tmp[first-1]
            tmp[first-1] = t
            return array[:-(left_rest+1)] + tmp[:1] + core(sorted(tmp[1:]), k-mlt*(first-1))
        return ''.join([str(i) for i in core(array, k)])
```
