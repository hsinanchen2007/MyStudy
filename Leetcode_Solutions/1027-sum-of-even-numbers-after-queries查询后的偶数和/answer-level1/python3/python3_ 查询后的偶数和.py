```python
def sumEvenAfterQueries(A, queries):
    r = []
    # 求得偶数和
    _sum = sum(list(filter(lambda a: a % 2 == 0, A)))
    for q in queries:
        # 元素为偶数
        if A[q[1]] % 2 == 0:
            # 查询的为偶数
            if q[0] % 2 == 0:
                r.append(_sum + q[0])
                _sum += q[0]
            # 查询的为奇数, 则需要减去查询的值
            else:
                r.append(_sum - A[q[1]])
                _sum -= A[q[1]]
        else:
            # 查询的为奇数
            if q[0] % 2 == 1:
                r.append(_sum + A[q[1]] + q[0])
                _sum += A[q[1]] + q[0]
            else:
                r.append(_sum)
        A[q[1]] += q[0]
    
    return r

print(sumEvenAfterQueries([1,2,3,4], [[1,0],[-3,1],[-4,0],[2,3]]))
```