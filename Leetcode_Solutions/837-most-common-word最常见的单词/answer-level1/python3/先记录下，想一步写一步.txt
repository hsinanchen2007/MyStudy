```
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        p = "!?',;."
        #将段落中所有符号替换成空格
        for i in p:
            paragraph = paragraph.lower().replace(i,' ')
        #以空格分隔成列表
        par = paragraph.split()
        par_set = set(par)
        dic = {}
        #单词为键、出现次数为值构建字典
        for val in par_set:
            dic[val] = par.count(val)
        #对字典按照值降序排列
        dic_sort = sorted(dic.items(),key=lambda x:x[1],reverse=True)
        #遍历找出符合条件的单词
        i = 0
        while i <=len(dic_sort)-1:
            if dic_sort[i][0]  in banned:
                i +=1
            else:
                return dic_sort[i][0]
```
