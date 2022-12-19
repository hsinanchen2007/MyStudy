```python
"""
1. dp问题, 答案来自:
https://leetcode.com/problems/ugly-number-ii/discuss/69373/Short-and-O(n)-Python-and-C%2B%2B
"""
def nthUglyNumber(n):
    ugly = sorted(2**a * 3 ** b * 5 ** c
                 for a in range(32) for b in range(20) for c in range(14))
    return ugly[n - 1]

def nthUglyNumber1(n):
    ugly = [1]
    # 定位2, 3, 5的索引
    i2 = i3 = i5 = 0
    while len(ugly) < n:
        # 找到需要*2, *3, *5的最小索引(i2, i3, i5不会越界)
        while ugly[i2] * 2 <= ugly[-1]: i2 += 1
        while ugly[i3] * 3 <= ugly[-1]: i3 += 1
        while ugly[i5] * 5 <= ugly[-1]: i5 += 1
        ugly.append(min(ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5))
    
    return ugly[-1]

print(nthUglyNumber(100))
print(nthUglyNumber1(100))
```