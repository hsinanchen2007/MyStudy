__排序__
题目要求非递减顺序即升序排序，直接使用python中内置排序函数sorted()
```
right_list = sorted(heights)
```

__两个数组比较计数__
```
# 初始化计数器
count = 0

# 利用for循环以及python的内置函数enumerate()进行两个数组元素的比较
for i, element in enummerate():
  if right_list != element:
    count += 1
return count
```
这里时间复杂度主要是在for循环里面O(n)
