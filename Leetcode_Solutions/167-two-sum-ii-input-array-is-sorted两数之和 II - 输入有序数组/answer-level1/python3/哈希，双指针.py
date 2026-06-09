双指针：
```python
def twoSum(numbers, target):
    i = 0
    j = len(numbers ) -1
    while i < j:
        if numbers[i] + numbers[j] > target:
            j = j - 1
        elif numbers[i] + numbers[j] < target:
            i = i + 1
        else:
            return [ i +1 , j +1]
    return False

```
哈希表：
```python
  hashmap = {}
    for index, i in enumerate(numbers):
        j = target - i
        if j in hashmap:
            return [hashmap[j]+1, index + 1]
        hashmap[i] = index