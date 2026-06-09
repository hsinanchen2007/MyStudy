
开始没有想明白, 其实就是先排序，在根据排序内容对比原始数据

```
def heightChecker(heights):
  checker = []
  # 先排序, 再对两个数据进行数值比较
  sortHeights = sorted(heights)
  for i, d in enumerate(sortHeights):
    if d != heights[i]:
      checker.append(d)
  return len(checker)
```
