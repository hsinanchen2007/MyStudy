方法一：递归

```python
def numberOfSteps(num):
    if num == 0:
        return 0
    if num%2 == 0:
        return 1 + numberOfSteps(num/2)
    esle:
        return 1 + numberOfSteps(num-1)
```

方法二：迭代
```python
def numberOfSteps(num):
    count = 0
    while num>0:
        num = num/2 if num%2 == 0 else num-1
        count += 1
    return count
```

分析：以上两个算法时间复杂度均为O(log n)，空间复杂度为O(1)

方法三：二进制（变成0的操作方法和变成二进制的辗转相除法很相近）
```python
def numberOfSteps2(num):
    return bin(num)+num.bit_length()-1
```