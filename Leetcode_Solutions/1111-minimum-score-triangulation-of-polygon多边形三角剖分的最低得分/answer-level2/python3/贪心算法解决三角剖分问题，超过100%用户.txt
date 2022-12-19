![捕获.PNG](https://pic.leetcode-cn.com/1937667525a46cda3cad1416b5b47bd722dc2ca6c5ac80aeb2a054530355851e-%E6%8D%95%E8%8E%B7.PNG)

通过观察可以发现对任意一个多边形的最优三角剖分，其子多边形（其子多边形是指最优三角剖分中去掉一些端点形成的多边形）的三角剖分也必然达到最优，因此我开始考虑时间复杂度更低的贪心算法。

对任意一个n边形（n>=5）,必存在一个端点x,令A[x]=min(A),除去x以及x的相邻端点，在剩余端点中再取最小值,记为y


命题：边(x,y)必然在该n边形的最优三角剖分中。

反证：假设(x,y)不在最优三角剖分中。由n>=5,除去x，y及x的两个相邻端点后，至少剩余一个端点,从中任取一个记为i，再在x,y,i之外任取一点j(取点j时令x,y,i,j四点构成一个以(x,y)为对角线的四边形),有x<=y<=i,x<=j(为了简便用x代替A[x])。由假设，在四边形xiyj中,yix+xjy>xji+yij(四边形的三角剖分只有两种)，xjy-xji+yix-yij>0,xj(y-i)+yi(x-j)>0，由y<=i,x<=j,矛盾。
**所以只要按以上方法找到一条最小边，就可以将原多边形分解为两个小多边形。**

![image.png](https://pic.leetcode-cn.com/a8bf8343aaf398c42d81f0e4cff35af5918ada5344a7b51fa65a72d33b24d4fe-image.png)

需要注意的是，在多边形中，可能发生一些边界情况:
(1)只有两个最小值点且它们连续：如[1,3,5,5,1],这时从A[0]出发得到最小边是(1,5),而我们实际需要的是(1,3)
(2)只有三个最小值点且它们连续的情况，如[2,2,7,3,2]，这时从A[0]出发得到最小边是(2,3),而我们需要的最小边其实是(2,2),因此必须进行特殊的处理

当多边形边数为3，4时，只要花费O(1)的时间就能判别最小三角剖分。

该算法每次寻找最小边花费O(n)的时间，最坏情况下时间复杂度为O(N^2),当[A]形如[1,2,3,4....]时,F(n)=F(n-1)+O(n)。而在各端点的值随机分布情况下，其平均时间复杂度应该比较优秀，可能达到了O(nlgn),但是由于我能力所限无法证明。

```
class Solution:
    def __init__(self):
        self.result=0
    def _find(self,A,m,length):  ###寻找最小边的两个端点，需要处理许多边界情况
        if m == 0:
            n = A[2:-1].index(min(A[2:-1])) + 2
        elif m==1:
            n=A[3:].index(min(A[3:]))+3
        elif m == length - 1:
            n = A[1:-2].index(min(A[1:-2])) + 1
        elif m==length-2:
            n=A.index(min(A[:-3]))
        else:
            minimum=min(min(A[:m - 1]), min(A[m + 2:]))
            n=A[:m-1].index(minimum) if minimum in A[:m-1] else A[m+2:].index(minimum)+m+2
        return (m, n)
    def find_element(self,A):  ###区分一些边界情况，包括两个和三个连续最小值
        length=len(A)
        minimum=min(A)
        if A.count(minimum) == 2:
            for i in range(-1, length - 1):
                if (A[i], A[i + 1]) == (minimum, minimum):
                    y = self._find(A, i + 1, length)
                    i = length - 1 if i == -1 else i
                    x = self._find(A, i, length)
                    return x if A[x[1]] < A[y[1]] else y
            else:
                return self._find(A,A.index(minimum),length)
        elif A.count(minimum)==3:
            for i in range(-2,length-2):
                if (A[i],A[i+1],A[i+2])==(minimum,minimum,minimum):
                    return (i,i+2) if i>0 else (i+2,length+i)
            else:
                return self._find(A,A.index(minimum),length)
        else:
            return self._find(A,A.index(minimum),length)
    def _execute(self,A):
        if len(A)==3:  ##三角形只有一种情况
            self.result+=(A[0]*A[1]*A[2])
        elif len(A)==4: ##四边形只有两种情况
            self.result+=min(A[0]*A[1]*A[2]+A[0]*A[2]*A[3],A[0]*A[1]*A[3]+A[1]*A[2]*A[3])
        else:
            m,n=self.find_element(A)
            a=min(m,n)
            b=max(m,n)
            self._execute(A[a:b+1])  ##分解为两个子多边形
            self._execute(A[:a+1]+A[b:])
    def minScoreTriangulation(self, A) -> int:
        self._execute(A)
        return self.result
```

