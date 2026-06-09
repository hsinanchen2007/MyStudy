  这道题其实跟那个踩阶梯的题很相似：“假如有10步台阶,一次可走一步或两步，那么要走到达台阶顶,有几种走法”。 
  我们可以这么解，假设最后一格是a[m][n],那么能到达a[m][n]的只有a[m-1][n]和a[m][n-1]。同理，要到达a[m-1][n],也只能从a[m-1-1][n]和a[m-1][n-1]；
要到达a[m][n-1],也只能从a[m-1][n-1]和a[m][n-1-1]，这是个递归问题。直到a[i][j]中i=1或者j=1,当i=1时，就只可以能时从a[i][j-1]到达，当j=1时，同样，也只能从a[i-1][j]到达；
于是，递归的边界找到了。
  可能上面说的不直观，请看下面:

```
           r(m,3)的值       r(m,4)的值   r(m,4)-r(m-1,4)的差值

            r(1,3)=1         r(1,4)=1         3
            r(2,3)=3         r(2,4)=4         6  
            r(3,3)=6         r(3,4)=10       10 
            r(4,3)=10        r(4,4)=20       15   
            r(5,3)=15        r(5,4)=35       21   
            r(6,3)=21        r(6,4)=56       28   
            r(7,3)=28        r(7,4)=84       36   
            r(8,3)=36        r(8,4)=120      45   
            r(9,3)=45        r(9,4)=165

        有没有发现
        r(9,4)=r(8,4)+45=r(8,4)+r(9,3)=r(7,4)+r(8,3)+r(8,3)+r(9,2)
        r(8,4)=r(7,4)+36=r(7,4)+r(8,3)=r(6,4)+r(7,3)+r(7,3)+r(8,2)
        .
        .
        .
        .
        .
```
于是我们很快想到了递归函数怎么写：
```
    public int uniquePaths1(int m, int n) {
        if (m == 1) {
        return 1;
        }
        if (n == 1) {
        return 1;
        }
        return uniquePaths1(m - 1, n) + uniquePaths1(m, n - 1);
    }
```

运行一下：

![image.png](https://pic.leetcode-cn.com/2cb3315f38029c0140fcc1ed6d72385de1fe420cc12e2d1b6f5d5a2a1aa4bc40-image.png)

结果对了，现在把参数值变大一点：

![image.png](https://pic.leetcode-cn.com/ff51e1677f815f79db629bd7f2a293e7c1c7b92193ee3d071e7a5821d8b25793-image.png)

时间还凑合，再变大，这次运行时间有点久了：

![image.png](https://pic.leetcode-cn.com/61cb6de16555f2c05b0f5ba3e7d4fba77bb639371cc6386f0222320993afca81-image.png)

超过了两分钟！
为什么呢，请看上面的发现那里：在我们计算r(9,4)的时候是不是中间会计算两次r(8,3),并且r(8,4)和r(9,4)中间都会有r(7,4)的计算，而这些重复计算是很浪费时间的。
于是，为了避免重复计算，这个函数需要改写，我们可以这样，在计算r(8,3)的时候把r(8,3)的值保存起来，这样下次计算r(8,3)的值的时候可以直接获取，不需要再计算了，根据这个思路，把算法改良一下：
```
public int uniquePaths3(int m, int n) {
        int[][] all = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    all[i][j] = 1;
                } else {
                    all[i][j] = all[i - 1][j] + all[i][j - 1];
                }
            }
        }
        return all[m - 1][n - 1];
}
```

再看看运行结果：

![image.png](https://pic.leetcode-cn.com/2044d1d618683671c73dfc547817c2df35e4f93e8c40ea6391192989fe7598a6-image.png)

快了好多是不是！

