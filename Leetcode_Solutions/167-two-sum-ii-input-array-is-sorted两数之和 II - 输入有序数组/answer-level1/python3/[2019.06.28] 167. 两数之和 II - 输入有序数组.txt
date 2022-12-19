(1) Brute Force
时间 O(n^2) 空间 O(1）

(2) Hash Table
时间 O(n) 空间 O(n）
```
def twoNum(numbers, target):
  # dictionary
  _Dict = {}
  for i, element in enumerate(numbers):
    if _Dict.get(target - element) is not None:
      return [_Dict.get(target - element) + 1, i + 1]
    
    _Dict[element] = i

print(twoNum([-3, 0, 2, 4, 5], 1))
```
(3) 双指针 - 一定要利用到已排序特性
该方法是看解答想到的 ！！！
时间 O(n) 
每个元素最多被访问一次，共有 n个元素
空间 O(1）
只是用了两个指针

```
def twoNum(numbers, target):
  i = 0
  j = len(numbers) - 1
  while(i < j):
    Sum = numbers[i] + numbers[j]
    if Sum == target:
      return [i, j]
    elif Sum < target:
      i += 1
    else:
      j -= 1

print(twoNum([-3, 0, 2, 4, 5], 1))
```
