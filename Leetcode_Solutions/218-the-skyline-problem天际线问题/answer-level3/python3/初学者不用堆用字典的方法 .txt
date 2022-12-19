### 解题思路
Main idea：线性扫描每一个关键点,判断是左端点还是右端点
Steps:  1.初始化两个字典，一个字典用于记录右关键点，另一个用于记录答案。为什么用字典，因为对于每一个坐标x，应该只记录一个高度, i.e., 最高的。
        2.首先把每个关键点都记下来，简单明了，左端点标记left，右端点标记right，并按照左端点排序
        3. 初始化高度0，目前高度cur=0，开始扫描：
            如果这个点为左端点，把他我们把他右端点这样记录在字典里 dic[右端点]=高度：
                如果这个点的右端点已经在字典里，存入最高的。
                并检查字典的最高高度， 如果高度改变，说明这是一个天际线点，并把左端点和高度存入答案，如果已经被存入左端点，用最高高度覆盖
            如果这个点是右端点，把其对应高度值从字典里删掉，并检查高度是否改变，如果改变，把其和新的高度存入。 因为在存入右端点时已经检查过重复，所以不用再次检查。
                



### 代码

```python3
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        ans = {}
        dic = {}
        points = []
        for L,R,H in buildings: #初始化所有关键点
            points.append((L,'left',H,R))
            points.append((R,'right',0,0))
        points.sort()
        dic[0] = 0
        cur = 0
        for x,s,H,R in points:
            if s =='left': #这个关键点是左端 
                if R in dic.keys(): #把其右端点和高度存入高度字典
                    dic[R] = max(dic[R],H)
                else:
                    dic[R] = H
                new = max(dic.values()) #如果高度改变，这就是天际线点
                if new != cur:
                    if x in ans.keys(): ans[x] =  max(ans[x],H)
                    else: ans[x] = H                   
                    cur = new
            else: #这个关键点是右端 
                if x not in dic.keys():  #前面已经被删除了，所有没有，跳过
                    continue
                del dic[x] #删除右端点及其高度，检查高度是否改变
                new = max(dic.values())
                if new != cur:
                    ans[x] = new
                    cur = new                
        return ans.items()



```