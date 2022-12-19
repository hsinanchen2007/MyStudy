话说刷Leetcode还真是有用的，我参见微软校招的时候真的遇见过这个题！一毛一样！
反过来说，微软真的喜欢出《剑指offer》上的题？

**来观察下正方形矩阵旋转90度时究竟发生了什么。**

观察图中颜色相同的四个位置，当旋转90度后，对应位置的元素发生了顺时针的交换。
![rotate.gif](https://pic.leetcode-cn.com/194630bf90343475a07278a0840d93ad891206acd50be1b81e75eb357d1e2c07-rotate.gif)
而相隔的两个位置是中心对称的，基于此可以计算出发生交换的四个元素**位置关系**。
设四个位置中，位于**左上角区域**的位置坐标为 (i,j)，
则按顺时针顺序，四个位置分别为(i,j), (j, n-i-1), (n-i-1,n-j-1), (n-j-1,i)。
其中 n 为 matrix.size(), i, j 分别为matrix的行列下标，从 0 开始。

整个矩阵的旋转可以理解为**起点都在左上角区域，然后依次顺时针移动**，如下图示：

<![](https://pic.leetcode-cn.com/9875ffc38d29c0aa96718f40505cf1199c5a14b1e526d8e90e0e080df9344489-rotate1.png),![](https://pic.leetcode-cn.com/7e52bf58105ad0e3d3283456d3aa0bbc217185b1296818f261d3ce5cf94418ef-rotate2.jpg),![](https://pic.leetcode-cn.com/ba7456dfb13e32b14983665ecd64399a72c5b513f7fdb785f3b0695a42a8f299-rotate3.png),![](https://pic.leetcode-cn.com/3160030cf1b5901a502e2434bf94ebd8012fcc639c6c3411e952da71957a4e92-rotate4.png)>

matrix.size() 为奇数时，位置的对应关系相同，但左上角区域并**不是整个矩阵的四分之一**，如下图示：
![image.png](https://pic.leetcode-cn.com/a2a3d0691e9979fee19e5f69f12b8b5205fd1b955d27661d36168f51aa0ba796-image.png)
其实就是**多了中间列的上半部分**。

那么现在捋一下如何**原地操作元素**：
枚举左上区域的所有位置，然后通过上面总结的位置关系直接交换元素。
对于一个位置 (i,j)，需要**交换三次**：
1. swap(matrix[i][j], matrix[j][n-i-1]);
2. swap(matrix[i][j], matrix[n-i-1][n-j-1]);
3. swap(matrix[i][j], matrix[n-j-1][i]);

综上，整个过程的时间复杂度为O(n^2)；空间复杂度为(1)。
当时我给出这个答案时，面试官还是很满意的~ (虽然在第四轮的时候挂掉了o(TヘTo)

有小伙伴对坐标推导过程感兴趣，那我尝试讲一下：
![image.png](https://pic.leetcode-cn.com/90a72746b7f6e5ce246a9235352cfa612a82d94340b35f40333f34d5b1e0baab-image.png)

**关于纵轴对称两个位置，到纵轴的距离相等，又因为第 0 列和第 n-1列到纵轴的距离相等**。所以关于纵轴对称的两个位置到 0 列和n-1列的位置相等，所以两点的纵坐标有 $y_0 - 0 = (n-1)-y_1$,即 $y_1 = n-1-y_0$，横坐标相等, 即 $x_1 = y_0$
关于横轴对称有相似的性质，可得 $x_3 = n-1-x_0$，纵坐标相等，即 $x_3 = x_0$。

中心对称，**就是先纵轴对称，然后横轴对称**，所以有
$y_2 = n-1-y_0, x_2 = n-1-x_0$。

这样就得到了其中一对位置的坐标对应关系，另一对和该对是根据**对角线对称**的，证明过程类似，不再赘述啦。

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) { return; }
        int r = (n>>1)-1; //左上角区域的最大行下标，
        int c = (n-1)>>1; //左上角区域的最大列下标，行列下标从 0 开始。
        for(int i = r; i >= 0; --i) {
            for(int j = c; j >= 0; --j) {
                swap(matrix[i][j], matrix[j][n-i-1]);
                swap(matrix[i][j], matrix[n-i-1][n-j-1]);
                swap(matrix[i][j], matrix[n-j-1][i]);
            }
        }
    }
};
```
# 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5x1f8_258.jpg)👏
* **分享周赛题解**
* **分享计算机专业课知识**
* **分享C++相关岗位面试题**
* **分享专业书籍PDF**