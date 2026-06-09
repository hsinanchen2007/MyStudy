```
class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        if not values or not labels or not num_wanted or not use_limit:
            return 0

        # 将label对应的value存到一个数组
        dict_label = collections.defaultdict(list)
        for i in range(len(values)):
            dict_label[labels[i]].append(values[i])

        # 先将label中的value进行排序
        # 根据use_limit，依次将label中相应数量的value取出来
        tmp_list = []
        for label in dict_label.keys():
            label_values = sorted(dict_label[label], reverse=True)
            for val in label_values[:use_limit]:
                tmp_list.append(val)
        
        # 最终将取出的value从大到小排序，并取前num_wanted即可
        return sum(sorted(tmp_list, reverse=True)[:num_wanted])
```
