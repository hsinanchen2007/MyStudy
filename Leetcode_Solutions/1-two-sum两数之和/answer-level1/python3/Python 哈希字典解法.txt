# 利用 Hash 快速查找的解法
1. 生成以列表值为 key，下标为 value 的 dict
2. 判断字典中是否存在 target - num 值的存在，如果存在，返回其下标，不存在返回Null
3. 判断返回的值是否为真，并且不能与当次循环的 index 相等（排除同一个数的情况）

# 时间空间复杂度分析
时间复杂度:O(n)
我们把包含有 n 个元素的列表遍历的两边，由于哈希表将循环内部查找时间缩短到了O(1)，所以时间复杂度为 O(n)

空间复杂度：O(n)，
所需的额外空间取决于哈希表中存储的元素数量，该表中存储了 n 个元素。

```
def twosum(li,target):
    hashdict = dict()
    for index,num in enumerate(li):
        hashdict[num] = index

    for index,num in enumerate(li):
        value = hashdict.get(target-num)
        # 如果存在，获取该数下标，如果不存在返回Null
        if value and value != index:
            # 该数值存在，且不是同一个数
            return [value, index]
```

# 优化版
1. 在构造 hashdict 的循环中，同时判断本次循环中 target - num 是否存在 hashdict，如果存在返回对应下标
2. 因为是在循环构造 hashdict 时，就开始判断是否存在 target - num ，所以排除了同一个数的可能，因为判断是在 hashdict[num] = dict 之前，此时 hashdict 中还不存在 num
```
def twosum(li,target):
    hashdict = dict()
    for index,num in enumerate(li):
        if target - num in hashdict:
            return [index, hashdict[target-num]]
        hashdict[num] = index
```

# 时间空间复杂度分析
时间复杂度:O(n)
我们把包含有 n 个元素的列表遍历的一边，由于哈希表将循环内部查找时间缩短到了O(1)，所以时间复杂度为 O(n)

空间复杂度：O(n)，
所需的额外空间取决于哈希表中存储的元素数量，该表中存储了 n 个元素。
