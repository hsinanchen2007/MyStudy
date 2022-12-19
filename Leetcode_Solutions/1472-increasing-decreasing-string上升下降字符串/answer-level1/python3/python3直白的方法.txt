此方法内存占用少，但是时间复杂度高
1、把s变成list类型
2、将s去重排序
3、取去重排序后的s_uniq进行遍历，然后去对比s_list中的元素
4、如果相同删掉s_list中的，并加入result中
```
class Solution:
    def sortString(self, s: str) -> str:
        result = ""
        s_list = [_ for _ in s]
        s_uniq = sorted(list(set(s)))
        while s_list:
            for tmp_str in s_uniq:
                i = 0
                while i < len(s_list):
                    if s_list[i] == tmp_str:
                        s_list.pop(i)
                        result += tmp_str
                        break
                    else:
                        i += 1
            for tmp_str in s_uniq[::-1]:
                i = 0
                while i < len(s_list):
                    if s_list[i] == tmp_str:
                        s_list.pop(i)
                        result += tmp_str
                        break
                    else:
                        i += 1
        return result
```
