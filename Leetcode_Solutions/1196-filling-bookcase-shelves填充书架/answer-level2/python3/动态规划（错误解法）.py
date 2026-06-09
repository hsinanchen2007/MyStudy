**input:
books = [[1,1],[1,1],[2,3],[1,1],[1,2],[1,1],[2,1]],shelf_width = 4**

**output:
错误答案z1=[0, 1, 1, 3, 4, 5, 5, 6]，
正确答案z2=[0, 1, 1, 3, 4, 4, 5, 5]**

总结：该方法是错误的，将每本书分成两种情况，放入该层和放入下一层。
当**width<=shelf_width**时，直接放入该层而不考虑前面的dp是错误的。
显然每次放入下一本书i时都要对比前面所有**min{dp[0:i-1]+max(books[(i:0):i])}**

**错误解法代码如下：**
```
def minHeight(books,shelf_width):
    n=len(books)
    width=shelf_width
    dp=[0]*(n+1)
    k=0
    for i in range(0,n):       # 从头到尾遍历每一本书
        if books[i][0]<=width: # 本层放的下这本书
            dp[i+1]=dp[k]+max([x[1] for x in books[k:i+1]])
            width-=books[i][0]
        else:                  # 本层放不下这本书，另开一层
            width=shelf_width  # 初始化宽度
            min_h=float('inf')
            tmp_w=0
            for j in range(i,0,-1): # 把第i本书前面的0-(i-1)本书拿下来，计算最小高度
                tmp_w+=books[j][0]
                if shelf_width<tmp_w:
                    break
                tmp_h=dp[j]+max([x[1] for x in books[j:i+1]])
                if min_h>tmp_h:
                    min_h=tmp_h
                    width=shelf_width-tmp_w
                    k=j
            dp[i+1]=min_h
    return dp[-1]
```
