重要的观察,记字符串为`s`
- 若利用`cnt[i]`来表示`s[:i]`的左括号的数目-右括号的数目
- 则对任意一个**合法**的括号匹配串`s`,一定有`cnt[i]>=0,0<=i<len(s)`

从而有以下思路:
- 1.从左向右扫描字符串,用cnt来记录左括号数目-右括号数目
    - 若`cnt<0`,说明右括号太多了,需要删除,记录对应下标,同时`cnt`**清0**
    - 做完步骤1.之后,有以下两个可能:
        - s已经合法
        - s不合法,但是存在`k`,`s[:k]`是合法的,`s[k:len(s)]`中的括号字符只有左括号
- 2.接着判断cnt是否大于0,若大于0,说明,左括号太多了,需要删除
    - 注意这儿删除是**从右向左**进行的

举个例子
"()((()",先从左向右,算出最终cnt=2,说明多了两个左括号,若从左向右删除"(",得到")(()",错误.而从右向左删除"(",得到"()()"
代码如下
```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        n=len(s)
        delete=[False]*n
        cnt=0
        for i in range(n):
            if s[i]=='(':
                cnt+=1
            elif s[i]==')':
                cnt-=1
                # 若右括号多就删除
                if cnt<0:
                    cnt=0
                    delete[i]=True
        if cnt>0:
            # 从右向左删除多余的左括号
            for i in range(n-1,-1,-1):
                if cnt>0 and s[i]=='(':
                    cnt-=1
                    delete[i]=True
                if cnt==0:
                    break
        ans=[]
        for i in range(n):
            if not delete[i]:
                ans.append(s[i])
        return ''.join(ans)

```