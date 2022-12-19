把两个List合并成一个，每个元素都是一个[value,label]
然后将新List按照value排序

接下来就是循环，从做向右取满足条件的值，因为已经排序过，所以结果必然是最大的
条件有两个：
    一个是num_wanted，计数器
    一个是use_limit，这个其实是标签的使用次数，用一个字典记录使用标签的次数


```
class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        together = [[values[i],labels[i]] for i in range(len(values))]
        together.sort(key= lambda x: x[0], reverse=True)
        res = 0
        i = 0
        label_dict = {}
        while i < len(together) and num_wanted:
            if together[i][1] not in label_dict:
                label_dict[together[i][1]] = 1
                num_wanted -= 1
                res += together[i][0]
            else:
                if label_dict[together[i][1]] < use_limit:
                    label_dict[together[i][1]] += 1
                    num_wanted -= 1
                    res += together[i][0]
            i += 1
        return res
```

虽然是python，总感觉写的代码很丑陋，从java转的python