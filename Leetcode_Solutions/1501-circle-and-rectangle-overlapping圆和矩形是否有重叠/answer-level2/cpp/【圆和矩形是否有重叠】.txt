
![图片.png](https://pic.leetcode-cn.com/4da31cb5f04a1d88ae8b625f0b06788b9294ee59c57ff1be7a57228a3a07728b-%E5%9B%BE%E7%89%87.png)

### 思路
1. 计算矩形的中心点 `(x0, y0)`
    11. 将这个点定义为坐标轴原点

2. 计算矩形的中心点到圆心的向量 `p`
    21. 通过绝对值，将圆心转移至第一象限
    22. 在哪个象限并不重要，他们之间是相对关系

3. 计算矩形的中心点到矩形右上角的向量 `q`

4. 通过 `p - q` 得到从矩形右上角到圆心的向量 `u`
    41. 将分量为负数设置为 0 
    42. 分量为负，说明可以找到更短的距离，设置为 0 相当于做垂线
    43. 当 x 和 y 都为负，说明圆心在矩形内

5. 比较 `u` 和圆形半径 `radius` 的长度

### 图解
<![图片.png](https://pic.leetcode-cn.com/0e11a5be63b2f3457d0d83ea6831079bf045a664e8f5f147aac0886863a1728a-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/b8ab501b3b43b9251b202f98d7881c737ad3427eaba50655c46cb5dea4a2a332-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/3a6ab2e4629c0cd1de381677ce787be01cec555787e2092ad2ba44c842b7e04c-%E5%9B%BE%E7%89%87.png)>


### 答题
```C++ []
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) 
    {
        double x0 = (x1 + x2) / 2.0;
        double y0 = (y1 + y2) / 2.0;

        vector<double> p = { abs(x_center - x0) , abs(y_center - y0) };
        vector<double> q = { x2 - x0, y2 - y0 };
        
        vector<double> u = { max(p[0] - q[0], 0.0), max(p[1] - q[1], 0.0) };

        return sqrt(u[0] * u[0] + u[1] * u[1]) <= radius;   
    }
```



### 致谢

学习自 [怎样判断平面上一个矩形和一个圆形是否有重叠？](https://www.zhihu.com/question/24251545)  


感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

