```
class Solution(object):
    def minimumAbsDifference(self, arr):
        """
        :type arr: List[int]
        :rtype: List[List[int]]
        """
        m = sorted(arr)
        result = [[m[0],m[1]]]
    
        i = 0
        min_ = abs(m[0] - m[1])
        k = [min_]
        while i < len(m)-1:
            temp = abs(m[i] - m[i+1])
            if temp < min_:
                k.pop()
                k.append(temp)
                result.pop()
                result.append([m[i],m[i+1]])
                min_ = temp
            elif temp == min_:
                result.append([m[i],m[i+1]])
                k.append(temp)

            i += 1
        min_ = min(k)
        l = k.index(min_)
        if l == 0:
            return result[l+1:]
        else:
            return result[l:]
```
