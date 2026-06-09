### 解题思路
根据每次选完大礼包剩余的needs表示状态 （也可能不选择大礼包）

### 代码
```python3
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        #记忆化搜索
        dicts={}
        lenn=len(needs)
        def getA(needs):
            if needs in dicts:
                return dicts[needs]
            #初始化needs 
            cost=0
            for p in range(lenn):
                cost=cost+price[p]*needs[p]
            #不需要判断needs in dicts 从顶向下的访问 肯定是不存在的 
            #需要明确的一点是 方法结束时对应的needs在map中是状态的最优解
            dicts.update({needs:cost})
            
            #记录下每种状态的最优值 不存在就放入map
            for s in special:
                t_need=[]
                for inx in range(lenn):
                    t=needs[inx]-s[inx]
                    #礼包有一个条件不符合就跳出
                    if t<0:
                        t_need=None
                        break
                    t_need.append(t)
                #t_need 不为空 表示选择了这个礼包 对应的是当前的s
                if  t_need:
                    t_cost=s[-1]
                    dicts[needs]=min(dicts[needs],t_cost+getA(tuple(t_need)))
                    t_need.clear()
            return dicts[needs]
        return  getA(tuple(needs))   
`内联代码`
```