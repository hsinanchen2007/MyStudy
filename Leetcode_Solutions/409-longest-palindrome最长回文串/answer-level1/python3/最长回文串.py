```
    def longestPalindrome(self, s: str) -> int:
        """
        给定语料库,构造一个最长回文字符串,区分大小写
        1. 遍历一遍,存入dict
        2. 遍历的同时若值为偶数,像结果中加2(回文字符长度应等于偶数键值的和+以及奇数键值减1的和+res<len(s)?1:0,))
        3. 若res小于所给字符串长度,可以在中间再插入一个字符,故加一
        """
        if len(s)==0:
            return 0
        if len(s)==1:
            return 1
        dict1={}
        num=0
        for i in s:
            if i not in dict1:
                dict1[i]=1
            else:
                dict1[i]+=1
                if dict1[i]%2==0:
                    num+=2
        if num<len(s) :
            return num+1
        return num
```
