```
class Solution:
    def threeSumMulti(self, A: List[int], target: int) -> int:
        count = [0] * 101
        for a in A:
            count[a] += 1
        min, max = 0, 0
        for i in range(101):
            if count[i] != 0:
                min = i
                break
        for i in range(100, -1, -1):
            if count[i] != 0:
                max = i
                break
        res = 0
        for i in range(min, max + 1):
            head, tail = i, max
            while head <= tail:
                if count[head] == 0:
                	head += 1
                	continue
                elif count[tail] == 0:
                	tail -= 1
                	continue
                else:
                    a, b, c = i, head, tail
                    if b + c < target - a:
                        head += 1
                    elif b + c > target - a:
                        tail -= 1
                    else:
                        if a < b < c:
                            res += count[i] * count[head] * count[tail]
                        elif a == b < c:
                            res += count[i] * (count[i] - 1) // 2 * count[tail]
                        elif a < b == c:
                            res += count[head] * (count[head] - 1) // 2 * count[i]
                        else:
                            res += count[i] * (count[i] - 1) * (count[i] - 2) // 6
                        head += 1
                        tail -= 1
                        res %= 1000000007
        return res
```
