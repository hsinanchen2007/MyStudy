```
class Solution:
    '''
    num_wanted:  限制选中的个数
    use_limit: 同种标签能使用的个数
    '''
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        key_value = sorted(zip(values,labels),reverse=True)
        cur={}  #记录当前label的数量
        res=0
        count=0
        for  i in range(len(values)):
            if cur.get(key_value[i][1])==None:
                cur[key_value[i][1]] = 1
                res+=key_value[i][0]
                count+=1
            else:
                if cur[key_value[i][1]]<use_limit:
                    res,cur[key_value[i][1]],count = res+key_value[i][0],cur[key_value[i][1]]+1,count+1
            if count==num_wanted:
                return res
        return res
```
