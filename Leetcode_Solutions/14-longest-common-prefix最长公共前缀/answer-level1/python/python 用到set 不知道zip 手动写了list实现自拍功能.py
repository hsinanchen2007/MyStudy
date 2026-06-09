思路就是根据最短的字符串长度，进行查看 

先把每个字符串对应位置的字符提出来 如 【'fff','lll','ooi','wwg'】 也可以使用zip
然后 遍历这些字符 如果是一样的（set后元素个数为1），就放进前缀中； 不是就退出循环



```python []
class Solution(object):
    def longestCommonPrefix(self, strs):
       
        length = []
        #计算输入的多个字符串最短的字符串的长度 如：最短的字符是 flow 那么返回4
        for each in strs:    
            length.append(len(each))
        #取出每个字符串对应位置的字符 如 flower的f flow的f 存在panduan_l中 【“ff”，“ll”】
        #等同于zip操作
        panduan_l = []
        for i in range(min(length)):
            panduan = ""
            for each in strs:
                panduan = panduan+ each[i]
            panduan_l.append(panduan)

        #前缀字符串提取
        #如果【“ff”，“ll”】中的ff是一样的，那么他的集合元素只有1 就放进前缀字符串 否则就退出循环
        commonprefix = ""
        for each in panduan_l:
            if len(set(each)) == 1:
                commonprefix = commonprefix + each[0]
            else:
                break
        return(commonprefix)

```

