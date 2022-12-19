#### 思路
奖赏的条件：不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到)。
反过来，只要超过一个“A”，或者超过两个连续的“L”，就不奖赏（`False`）。A可以不连续，因此利用`str.count()`方法；L必须连续，那至少有“LLL”或更多。
#### 代码
于是有了以下代码：
```python
def checkRecord(s):
    if s.count("A")>1 or "LLL" in s:
        return False
    return True
```
也可以一行搞定：
```python
# 正难则反思想
def checkRecord(s):
    return False if s.count("A")>1 or "LLL" in s else True

# 正面解决
def checkRecord(s):
    return s.count("A")<=1 and "LLL" not in s
```
#### 结果
执行用时：28ms，打败96.32%
内存消耗：12.7MB，打败100%