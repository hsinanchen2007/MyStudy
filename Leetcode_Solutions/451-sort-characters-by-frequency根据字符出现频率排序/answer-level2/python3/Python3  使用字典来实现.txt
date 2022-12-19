
思路: 使用字典统计字符出现的频率, 在对字典的value进行排序, 最后组合到一块输出, 复杂度分析,见注释
```
    def frequencySort(self, s: str) -> str:
        if s is None or len(s) == 1: return s
        counter = collections.defaultdict(int)
        
        # 遍历时间复杂度为 O(N) 因为要建立一个字典存储元素, 此时空间复杂度最坏为O(N) N为字符长度
        for c in s:
            counter[c] = counter[c] + 1
        
        # 排序 平均最好的时间复杂度为O(Klog(K)) 最坏时间复杂度为O(K^2) K为字典键的数量
        sorted_array = sorted(counter.items(), key=itemgetter(1), reverse=True)
        
        # 遍历排好序的数组 时间复杂度O(K) 空间复杂度O(N)
        string = ''
        for key, value in sorted_array:
            string += key * value   
        return string 
```
