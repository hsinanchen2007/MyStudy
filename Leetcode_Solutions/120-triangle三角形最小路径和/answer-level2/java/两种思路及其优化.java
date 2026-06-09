## 前提条件

题目给的图是一个等腰三角形，输入是一个二维数组，所以我们在思考问题时首先要把这个三角形变成一个垂直等腰三角形。
![Annotation.png](https://pic.leetcode-cn.com/424a4659e7eadefc3160a3ccac3b583d9f0ac11d793a12250edd7390a1f114b4-Annotation.png) --------------------------------------> ![Annotation (1).png](https://pic.leetcode-cn.com/6b375bf3e6cd1b1115a1028c2a53dc955c883d623ab65cad130f7765e5a48e75-Annotation%20\(1\).png)

## 解题思路
### 1. 从顶向下求解
这是题目上说的顺序，从顶向下走，求出最小路径和。
按照正常的思路，我不知道哪一条是从顶层到底层的最短路径，所以我会一条条的去尝试，直到找到最短的那一条。很显然的是，从某一点往下走，只有两种情况，往左下和右下两种选择。这样的话，就是一个递归的样子。但是，递归占用空间大，所以舍去。

从上面分析来看的话，从一点x往下走一行选择一个点y，这条路径L1的值就要加上这两个点的和，如果有其他路径L2也走到y这个点，那么此时就要进行抉择，因为从y往下走，就跟L1和L2没有关系了，这是一个全新的开始，所以我要从L1和L2中选择一个值小的作为y点上面的路。所以，我令dp[i][j]为三角形从顶点到第i行第j列这个点的路径最小值。因为要考虑边界问题，所以递推公式分三种情况：
- 如果此时走到某一行的最左端，此时dp[i][j] = dp[i-1][j]+curValue，最左边的点只能从上一行中最左边的点经过。(curValue为当前点的值，i为行，j为列，以下一致)
- 如果此时走到某一行的最右端，此时dp[i][j] = dp[i-1][j-1]+curValue，最右边的点由上一行中最右边的点经过。
- 其他情况，dp[i][j] = Math.min(dp[i-1][j-1],dp[i-1][j])+curValue，当前点(i,j)会由上一行中的左上的点(i-1,j-1)和右上的点(i-1,j)经过。

以上三种情况，请对照前提条件中的等腰直角三角形思考。最终求得的结果就是一个二维数组，只要找出最后一行的最小值即是最终答案。然后就可以很轻松的AC了。

#### 优化
可以对空间进行优化，只需要O(n) 的额外空间。(我一开始不知道可以优化QAQ，我是看到题目说可以...)
那么定义一个一维数组，长度为三角形底边的长度，dp[j]]表示某一行中第i列的最小路径和。
对于上述的三种情况，在这个条件限制下，变为：
- 如果此时走到这一行的最左端，此时dp[j] =  dp[j] (这个是上一行的计算出的结果) + curValue;
- 如果此时走到这一行的最右端，此时dp[j] = dp[j-1] (这个是上一行的计算出的结果) + curValue;
- 其他情况，dp[j] = Math.min(dp[j-1],dp[j])（此时dp[j-1]和dp[j]都为上一行的计算结果）+curValue;

按照上述的推断，那么只需要保留两个值即可算出dp[j]，即上一行的dp[j-1]和上一行的dp[j]。

``` Java
public int minimumTotal(List<List<Integer>> triangle) {
        int[] dp = new int[triangle.size()];
        int ans = 0;
        dp[0] = triangle.get(0).get(0);
        int temp,prev = 0,cur;// prev为上一行的dp[j-1],cur为上一行的dp[j]
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                temp = triangle.get(i).get(j);
                cur = dp[j];
                if (j == 0) dp[j] = cur + temp;
                else if (j == triangle.get(i).size() -1) dp[j] = prev+temp;
                else dp[j] = Math.min(prev,cur) + temp;
                prev = cur;
            }
        }

        for (int i = 1; i < dp.length; i++) {
            if (dp[ans] > dp[i]) ans = i;
        }
        return dp[ans];
    }
```
### 2. 从底向上求解
这个思路跟从顶向下求解的思路一致，区别就是这种方式没有边界限制，而且最终的结果不需要排序，直接返回dp[0]即是答案。

``` Java
public int minimumTotal(List<List<Integer>> triangle) {
        int[] dp = new int[triangle.size()];
        for (int i = 0; i < triangle.size(); i++) {
            dp[i] = triangle.get(triangle.size()-1).get(i);
        }

        for (int i = triangle.size()-2; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                dp[j] = Math.min(dp[j],dp[j+1])+triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
```

## 总结
好像没啥好总结的，有写的不对的地方欢迎指正~
emm感jio字有点多，有好心人推荐好用的画图软件么，万分感谢q(≧▽≦q)