```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.se=set()
        self.hasdone=set()
        kk=[]
        for x in wordDict:
            if x not in self.se:
                self.se.add(x)
                kk.append(x)
        p=q=0
        # 函数，DFS,timeout
        # 加上一个hasdone的set将判断过的串记录以免以后再判断，能运行了，但是效果还是不好
        def func(s):
            if s in self.hasdone:return False
            self.hasdone.add(s)
            print(s)
            max=0
            for x in self.se:
                if len(x)>max:max=len(x)
            if s in self.se:return True
            p=q=0
            while q<len(s) and p-q<=max:
                while s[p:q] not in self.se:
                    if q-p>max:break
                    q+=1
                    if q==len(s):break
                # print(q,len(s))
                if q!=len(s) and s[p:q] in self.se:
                    if func(s[q:])==True:return True
                q+=1
            return False
        # 先遍历se中，如果有冗余的先删去
        for x in kk:
            self.se.remove(x)
            if func(x):continue
            self.se.add(x)
        # print(self.se)
        self.hasdone.clear()
        return func(s)
```
方法二：动态规划，当前位置满足条件则变为1，不满足还是0，只对是1的位置继续往后伸展，配合适当的剪枝。我知道我表达的不明白，你也看不明白。
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        lens=len(s)
        dp=[0 for _ in range(lens+1)]
        dp[0]=1
        <!-- 子串用set存更好一点 -->
        se=set()
        <!-- 这个lenli是保存子串有的长度，比如223，最后指对当前数组之后的2，3位置判断是否在set中，在的话dp变为1，之后继续往后判断 -->
        lenli=[]
        for x in wordDict: 
            se.add(x)
            lenli.append(len(x))
        lenli.sort()
        lenli=list(set(lenli))
        for i in range(lens+1):
            if dp[i]==1:
                for j in lenli:
                    if i+j>lens:break
                    if dp[i+j]==0:
                        if s[i:i+j] in se:dp[i+j]=1
        return False if dp[-1]==0 else True
```
