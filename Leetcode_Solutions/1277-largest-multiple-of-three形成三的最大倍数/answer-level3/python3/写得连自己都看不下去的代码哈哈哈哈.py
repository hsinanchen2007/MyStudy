```
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        digits.sort(reverse=True)
        n = len(digits)
        
        total = sum(digits)
        
        tail = total % 3
        # print(tail)
        if tail == 0:
            return str(int("".join(map(str, digits))))
        elif tail == 1:
            res2 = 0
            for i in range(n - 1, -1, -1):
                if digits[i] % 3 == 1:
                    # print(digits[i])
                    tmp = digits[:i] + digits[i + 1:]
                    if len(tmp) == 0: res2 = 0
                    else: res2 = (int("".join(map(str, tmp))))
                    break
            # print(res2)
            res1 = 0
            cnt = 0
            p, q = -1, -1
            for i in range(n - 1, -1, -1):
                if digits[i] % 3 == 2 and cnt == 0:
                    p = i
                    cnt += 1
                    continue
                if digits[i] % 3 == 2 and cnt == 1:
                    q = i
                    cnt += 1
                    break
            if p == -1 or q == -1: res1 = 0
            else:
                tmp = digits[:q] + digits[q + 1:p] + digits[p + 1:]
                if len(tmp) == 0: res1 = 0
                else: res1 = int("".join(map(str, tmp)))
            if res1 == 0 and res2 == 0: return ""
            if res1 > res2: return str(res1)
            if res2 > res1: return str(res2)
            if res2 == res1: return str(res2)
        elif tail == 2:
            res2 = 0
            for i in range(n - 1, -1, -1):
                if digits[i] % 3 == 2:
                    tmp = digits[:i] + digits[i + 1:]
                    if len(tmp) == 0: res2 = 0
                    else: res2 = int("".join(map(str, tmp)))
                    break
            res1 = 0
            cnt = 0
            p, q = -1, -1
            for i in range(n - 1, -1, -1):
                if digits[i] % 3 == 1 and cnt == 0:
                    p = i
                    cnt += 1
                    continue
                if digits[i] % 3 == 1 and cnt == 1:
                    q = i
                    cnt += 1
                    continue
            if p == -1 or q == -1: res1 = 0
            else:
                tmp = digits[:q] + digits[q + 1:p] + digits[p + 1:]
                if len(tmp) == 0: res1 = 0
                else: res1 = int("".join(map(str, tmp)))
            # print(res1, res2)
            
            if res1 == 0 and res2 == 0: return ""
            if res1 > res2: return str(res1)
            if res2 > res1: return str(res2)
            if res2 == res1: return str(res2)
                
        return ""
```
