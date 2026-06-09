
感觉这题是比较简单的，这里给出我思考的3个思路和提交代码时遇到的1个坑，给大家参考一下。

# 思路：
1 什么样的数组满足**三等分**的条件。
2 问题拆解：一共有3个部分，如何确定找到了1个部分。
3 是否需要完全遍历数组。

# 坑：
1 保证3部分的数组非空(我第一次提交时倒在这)

# 代码：
```python
def canThreePartsEqualSum(self, A):
    if sum(A) % 3 != 0:  # 思路1：选择满足三等分条件的数组
        return False
    avg = sum(A) // 3
    n_part = _sum = 0  # 使用一个变量记录找到了几部分

    for idx,a in enumerate(A):
        _sum += a
        if _sum == avg:  # 思路2：如果列表子串和等于3等分均值，则说明找到了1部分
            _sum = 0
            n_part += 1  
        if n_part == 2 and idx < len(A)-1:  # 坑1：保证数组非空
            return True  # 思路3：无需遍历全部数组，找到两部分即可返回
    return False
```


