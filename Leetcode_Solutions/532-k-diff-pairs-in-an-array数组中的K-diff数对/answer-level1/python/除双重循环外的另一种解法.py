双重循环方法很简单，一个游标固定，另一个向后走就行了，但是容易在测试案例过大的时候超出时间限制.....
这次我想说一下我的这个使用map表的常规解法。
代码如下：
```
    if k < 0:
        return 0 # 小于0为负数的不符合题目要求，直接返回0即可
    num_map = {} # 创建map表，map表速度比较快嘛
    count = 0
    for item in nums:
        if item not in num_map:
            num_map[item] = 0
        num_map[item] += 1 # 主要计算每个元素出现的次数
    # 一种特殊情况就是k==0,这种情况上面的元素次数就有用处了，大于1次的就算一个
    if k == 0:
        for value in num_map.itervalues():
            if value > 1:
                count += 1
        return count
    # 这个地方有一点要注意，这边只算了key + k的情况，是因为一个循环，一定会遇到key-k和key+k两种情况，例如4+1=4, 5-1=4，其实
    # 只算一种就可以了，两种的话后面还需要去重啥的，增加了复杂度
    for key in num_map.iterkeys():
        if key + k in num_map:
            count += 1
    return count
```
