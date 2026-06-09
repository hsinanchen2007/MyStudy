1.要熟悉map的用法 s[i]只表示I,V那些 我们只需要数字 
  所以有关s[i]的全部要套上rela的外衣
2 if的判断 一定是i的长度在前面 它不符合后面的and就不跑
  跑了一定会越界 比如i已经到了最后一个 哪来的s[i+1]


class Solution:
    def romanToInt(self, s: str) -> int:
        # 先定义一个map 找出对应关系
        rela={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        sum=0
        for i in range(0,len(s)) :
            if i<(len(s)-1) and rela[s[i+1]]>rela[s[i]]  :
                sum-=rela[s[i]]
            else :
                sum+=rela[s[i]]
            
        return sum
        