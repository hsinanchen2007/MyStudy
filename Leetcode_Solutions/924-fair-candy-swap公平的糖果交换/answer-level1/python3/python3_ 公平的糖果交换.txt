```python
def fairCandySwap(A, B):
    # 求得A和B交换元素的差值
    sum_a, sum_b = sum(A), sum(B)
    v = (sum_a + sum_b) // 2 - sum_a
    # 将B设为set, 则可提高查询速度
    setB = set(B)
    for a in A:
        if a + v in setB:
            # 定位到差值为v的两个数
            return [a, a + v]
        
print(fairCandySwap([1,1], [2,2]))
print(fairCandySwap([1,2], [2,3]))
print(fairCandySwap([2], [1,3]))
print(fairCandySwap([1,2,5], [2,4]))
```