### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):

    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        #a[i][j] 表示从piles[i:j]的结果
        #其中a[i][j][0] 表示先取石头能得到的最多石头数, a[i][j][1]表示后取石头能得到的最多石头数
        # 最后的结果其实就是判断 a[0][len(piles)-1][0]-a[0][len(piles)-1][1]是否大于0
        a=[[[0,0] for _ in range(len(piles))] for _ in range(len(piles))]
        for i in range(len(piles)):
            a[i][i][0]=piles[i]
        for k in range(1,len(piles)):  #对角线斜着遍历
            for j in range(1,len(piles)):
                i=j-k
                left=piles[i]+a[i+1][j][1]  #先从最左边开始取最大
                right=piles[j]+a[i][j-1][1]
                if left>=right:
                    #如果先取左边, 还剩于piles[i+1:j], 对于剩余的相当于后取能拿到的最多石头数(要等对方先取)
                    a[i][j][0]=piles[i]+a[i+1][j][1]
                    #如果后取, piles[i]被取了, 那相当于从piles[i+1:j]先取 
                    a[i][j][1]=a[i+1][j][0]
                else:
                    a[i][j][0]=piles[j]+a[i][j-1][1]
                    a[i][j][1]=a[i][j-1][0]
        return a[0][len(piles)-1][0]>=a[0][len(piles)-1][1]
```