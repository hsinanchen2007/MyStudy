```
class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        # 进位是-,借位是+
        if len(arr1) < len(arr2):
            arr1, arr2 = arr2, arr1
        len1 = len(arr1)
        len2 = len(arr2)
        arr1 = list(reversed(arr1))
        arr2 = list(reversed(arr2))
        i = 0
        c = 0
        result = []
        while i < len1 and i < len2:
            tmp = arr1[i] + arr2[i] - c
            if tmp >= 0:
                result.append(tmp % 2)
                c = tmp // 2
            else:
                result.append((2+tmp) % 2)
                c = -1
            i += 1
        while i < len1:
            tmp = arr1[i] - c
            if tmp >= 0:
                result.append(tmp % 2)
                c = tmp // 2
            else:
                result.append((2+tmp)%2)
                c = -1
            i += 1
        while c != 0:
            tmp = -c
            if tmp >= 0:
                result.append(tmp % 2)
                c = tmp // 2
            else:
                result.append((2+tmp)%2)
                c = -1
        while len(result) > 0 and result[-1] == 0:
            result.pop()
        if len(result) == 0:
            result = [0]
        return reversed(result)
```
