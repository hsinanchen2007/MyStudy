### 解题思路
这道题一开始摸不到头绪，后来根据一个大佬的题解（https://leetcode-cn.com/u/ma-dong-dong/），把每个格变为3*3的小格，就可以轻松用dfs、bfs算出连通分量也就是最后的答案。

但是好不容易发现一道稀缺的并查集的题，就想练练并查集，但是发现官方对于这道题的题解并不是非常的详细，所以在基于官方题解的基础上，说一说自己理解。
（以下内容参考于博客：https://blog.csdn.net/qq_17550379/article/details/85262219）

1.我们可以通过/和\将一个区域划分为四块，然后我们按照顺时针自顶开始的顺序标记划分后的区域为1、2、3和4。我们此时就可以开始遍历输入的grid。
2.如果碰到'/'，我们就将0和3进行归并。如果碰到'\\'，我们就将1和2归并。如果碰到' '， 我们就将1、2、3和4全部归并。
（此处请注意：官方题解中是上0下3左1右2，与此处不同，但是对理解思想没影响）
![2018_12_26_1.png](https://pic.leetcode-cn.com/7d2703f6233869a81011a4c55e7d7f5cf8059195e99f102a635b57552f6b1da1-2018_12_26_1.png)
![2018_12_26_2.png](https://pic.leetcode-cn.com/c7b339712c51c2643fe7a03db97a2d7cab86d815d6d407e4eb3fd7169f33ee62-2018_12_26_2.png)
![2018_12_26_3.png](https://pic.leetcode-cn.com/4e942503378df75e49fc0280d35fb2853bbb5ea0baea0d140808e1964885d00c-2018_12_26_3.png)
例：我们首先碰到'/'，所以我们就将第一个方格中的03和12分别归并。
![2018_12_26_4.png](https://pic.leetcode-cn.com/d7f0429892990ef599b5b51e5b2fe920aedee22895219cbf864815c2df331e11-2018_12_26_4.png)
同理接着将后面碰到的'/'和' '一次归并。
![2018_12_26_5.png](https://pic.leetcode-cn.com/03cfba1966214d50f131dea57eb88f3ed8b22ed72eb8861716675867decd8be0-2018_12_26_5.png)
最后，再使每个小组合与接邻四方归并，比如第一大格中的1与第二大格的3归并（不管是'/'还是'\\'，每个点总是与相邻大格中的相邻点在同一组），第一大格中的2与第三大格中的0归并。这样我们就把中间这个部分归并为了一个集合。对于下方的三角形区域做同样的操作。
![2018_12_26_6.png](https://pic.leetcode-cn.com/9586a26ed92384b2100401a71ce7ad05f200d7e38c9275a452a3acefd908cdd0-2018_12_26_6.png)

ps:其实上右下左四个归并不用全左，比如光写右下归并也是可以跑成功的，可能官方题解为了易于理解，就都写上了。
ps：写的可能有点乱，全是自己想的大白话。如果有什么问题，欢迎留言。
### 代码

```java
/*
作者：LeetCode
链接：https://leetcode-cn.com/problems/regions-cut-by-slashes/solution/you-xie-gang-hua-fen-qu-yu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


class Solution {
    public int regionsBySlashes(String[] grid) {
        int N = grid.length;
        DSU dsu = new DSU(4 * N * N);  //这是自己定义的并查集的类，可以先看下这个类。
                                        //创建类，类里面有一个4 * N * N的并查集数组

        for (int r = 0; r < N; ++r) //row代表行
            for (int c = 0; c < N; ++c) { //col代表列  两个for遍历grid的每个字符
                int root = 4 * (r * N + c);
                char val = grid[r].charAt(c); //字符

                if (val != '\\') {    //如果为 ’/‘或者’ ‘则组合（0，1），（2，3）.
                    dsu.union(root + 0, root + 1);
                    dsu.union(root + 2, root + 3);
                }
                if (val != '/') {    //如果为 ’\\‘或者’ ‘则组合（0，2），（1，3）
                    dsu.union(root + 0, root + 2);
                    dsu.union(root + 1, root + 3);
                }

                if (r + 1 < N)   // 如果不是最后一行，则向下归并 ：3 归并下行的0      0         0
                    dsu.union(root + 3, (root + 4 * N) + 0);                //     1    2    1    2
                if (r - 1 >= 0)  //如果不是第一行，则向上归并：0归并上行的3           3         3
                    dsu.union(root + 0, (root - 4 * N) + 3);                  //      0        0
                                                                           //       1   2    1    2
                if (c + 1 < N)//如果不是最后一列，则向右归并：2归并右邻的1            3         3
                    dsu.union(root + 2, (root + 4) + 1);
                if (c - 1 >= 0)//如果不是第一列，则向左归并：1归并左邻的2
                    dsu.union(root + 1, (root - 4) + 2);
            }

        int ans = 0;
        for (int x = 0; x < 4 * N * N; ++x) { //最后在使每个点的值为最高级主人，再计数一共有几个主人。就得出结果
            if (dsu.find(x) == x)
                ans++;
        }

        return ans;
    }
}

class DSU { //并查集的类
    int[] parent; 
    public DSU(int N) {
        parent = new int[N];//创建并查集数组，每个下标的值是自己（自己是自己的主人）。
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }

    public int find(int x) {//查找自己的主人，并更新自己的值为最高级的主人。
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    public void union(int x, int y) {//归并。x的主人归并y的主人。
        parent[find(x)] = find(y);
    }
}



```