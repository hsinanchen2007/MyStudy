
```
import collections
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if(not A):
            return 0
        # 统计各数字出现次数
        dic = collections.Counter(A) 
        # 步骤计算
        count = 0
        # 将字典中的键从小到大排列
        temp = sorted(list(dic.keys()))
        # 初始化上一个值，保存上一个增加后的数, 即前面出现过的最大值
        last = temp[0] - 1
        for each in temp:
            # 当前数要增加到前面没有出现过的值的增量
            dis = 0  
            # 判断each是否大于last
            # 若大于，说明前面没有出现过each，否则将each增加到前面没有出现过为止   
            if(each <= last):
                dis = last+1-each
                # 将所有each加到之前没有出现过为止所用的增量
                count += dis * dic[each]
                # 更新last值
                last = last+1           
            if(dic[each] > 1):
                # 若each数量大于1，则将从第二个each开始增加到前面没有出现过为止，用高斯定理计算步骤
                count += dic[each] * (dic[each]-1) // 2
                # 更新last为当前位置的最大值
                last = each + dic[each] - 1 + dis
        return count
```
