思路：
1、先将paragraph转成小写
2、将paragraph中的符号用空格代替，并用split分隔paragraph
3、用Counter统计个数
4、对banned中的词进行判断
```
class Solution:
    def mostCommonWord(self, paragraph, banned) -> str:
        banned = set(banned)
        #1、转成小写
        paragraph = paragraph.lower()
        #2、将paragraph中符号用空格代替，然后split分隔
        str_list = ["!","?","'",",",";","."]
        for i in str_list:
            paragraph = paragraph.replace(i," ")
        paragraph = paragraph.split()

        #3、使用Collection中的Count统计个数
        from collections import Counter

        s = dict(Counter(paragraph))
        ss = sorted(s.items(),key=lambda x:x[1],reverse=True) ##按照items进行排序
       
        #4、对banned中的词进行判断
        if len(banned)==0:
            return ss[0][0]
        else:
            for i in ss[:]:   ##注意:这个冒号很重要：表示对ss复制了一份，不然会报错，因为再删除的过程中ss的长度在变化
                print("ss:",ss)
                print("i[0]",i[0])
                if i[0] in banned:
                    ss.remove(i)
      
        return ss[0][0]
```
