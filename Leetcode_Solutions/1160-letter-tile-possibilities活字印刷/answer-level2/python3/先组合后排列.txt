思路：按所使用的元素个数分类，依次计算各个情况的排列组合数，相加得最后结果。比如'ABC'：使用一个元素的情况为'A','B','C'；两个元素的情况为'AB','AC','BC'，每种情况分别有2种排列方式；使用三个元素的情况为'ABC'，有6种排列方式。相加返回结果3+6+6=15

```
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        
        #将字符串统计为字典
        dic = {}
        for letter in tiles:
            if letter not in dic.keys():
                dic[letter]=1
            else:
                dic[letter]+=1
        
        #定义函数来计算字典所有元素都用上的全排列情况，用的递归，懒得改了，可以用排列组合知识简化        
        def numDic(dic:dict)->int:
            res = 0
            if not dic:
                return 0
            if not sum(dic.values()):
                return 0

            end=0
            for i in dic.keys():
                if dic[i]:
                    end+=1
                    res=1
            if end==1:
                return res
                
            res=0
            for i in dic.keys():
                if dic[i]:
                    dic_cp = dic.copy()
                    dic_cp[i]-=1
                    #print(dic_cp)
                    res+=numDic(dic_cp)
                    #print(res)
            return res
        
        #枚举所有子集的字典形式，用列表形式存储
        #子集列表初始化
        dic_all=[]
        dic_all_lenth = 1
        for key in dic.keys():
            dic_all_lenth *= (dic[key]+1)
        for i in range(dic_all_lenth):
            dic_all.append({})
                       
        #形成子集
        for i in range(dic_all_lenth):
            j=1
            for key in dic.keys():
                dic_all[i][key]=((i//j)%(dic[key]+1))
                j*=(dic[key]+1)
                
        #遍历子集计算最终结果
        result = 0
        for dic_res in dic_all:
            result += numDic(dic_res)
        
        return result

```