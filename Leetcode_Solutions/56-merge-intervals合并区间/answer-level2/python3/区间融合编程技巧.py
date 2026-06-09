```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        '''
        思路：融合时强烈建议不要用前后指针传统脑路（例如后指针先往前探索，然后再位移前后指针。
             这种思路容易在边界条件搞混！！）
             建议后指针往前探索：例如本题，先创建一个merge列表，这个列表其实先存下前指针的内容，
             后指针和merge列表进行比较，相当于与一个后指针往前探索的思路!这样可以减少很多边界条
             件的探讨，思路也能更清晰！
        '''
        # 先按每个区间的左边界进行排序
        intervals = sorted(intervals, key=lambda x:x[0])
        # 创建一个融合列表
        merge = []
        # 遍历每个区间，判断每个区间是否能与merge的最后一个区间是分隔，融合，还是包含关系
        for val in intervals:
            # 如果merge为空或者是和merge最后一个区间的右边界是分隔关系，就直接加入
            if not merge or val[0] > merge[-1][1]:
                merge.append(val)
            # 如果和merge最后一个区间的右边界是融合关系，就进行融合
            elif val[1] > merge[-1][1]:
                merge[-1][1] = val[1]
            # 如果是包含关系，就什么都不用做。
        return merge
```
