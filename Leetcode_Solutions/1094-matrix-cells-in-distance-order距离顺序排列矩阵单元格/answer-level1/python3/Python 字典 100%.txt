执行时间：188 ms    84%
内存消耗：16.8 MB  100%

基本思路：将距离作为键，将坐标保存在对应的值里面。后将字典中的键排序后输出坐标即可。


```Python
class Solution:
    def allCellsDistOrder(self, R, C, r0, c0):
        dic = {}
        # 以距离大小作为键
        for i in range(R):
            for j in range(C):
                distance = abs(i - r0) + abs(j - c0)
                if distance not in dic:
                    dic[distance] = []
                    dic[distance].append([i, j])
                else:
                    dic[distance].append([i, j])

        result_list = []
        # 对字典键进行排列
        for index in sorted(dic.keys()):
            result_list.extend(dic[index])

        return result_list

```
