### 解题思路
### 简介
距离变换是图像处理领域的一种算法，最开始用于二值影像，是将原始影像转化为距离影像进行处理的一种变换，生成的距离影像其灰度值含义是像素点到最近背景点的距离，这个距离可以是欧式距离，也可以是曼哈顿距离，棋盘距离。距离越大，距离影像灰度值越大，也就越亮。
![image.png](https://pic.leetcode-cn.com/d6450a6e3c89af03e701819f73c2128efc3d400587397235e84f0a646ca4679c-image.png)
### 题解
海洋区域到离它最近的陆地区域的距离，就是像素点到最近背景（陆地）点的距离，与距离变换定义是一样的。
寻求距离陆地区域最远的海洋区域，就是找距离变换图像上灰度值最大的点。
### 算法
距离变换的实现算法有很多，感兴趣的可以上网搜，以下介绍并实现的算法来自[知乎某文章](https://zhuanlan.zhihu.com/p/38917770)。做了点细微改动。
以二值图像为例，其中区域块内部的像素值为1，其他像素值为0。距离变换给出每个像素点到最近的区域块边界的距离，区域块内部的距离变换结果为0。输入图像如图1所示，D4距离的距离变换结果如图2所示。
![image.png](https://pic.leetcode-cn.com/4334df9c9c6c7d82a368ac9be0b861d7aa2a59f1617e002ed33e0780571f2b23-image.png)
![image.png](https://pic.leetcode-cn.com/f2d58da043a2d5fb301c81c1d9841b1391772c83fbc3b6b029219bc8f6453108-image.png)
下面来讨论距离变换算法，其核心是利用两个小的局部掩膜遍历图像。第一遍利用掩模1，左上角开始，从左往右，从上往下。第二遍利用第二个掩模，右下角开始，从右往左，从下往上。掩模形状如下图所示：
![image.png](https://pic.leetcode-cn.com/c1d585ed989987fcbd59f43140c07a0ff4a83b1a17ba93a0aa55e92d722b17e0-image.png)
按照某种距离（如：D4距离（就是曼哈顿距离）或D8距离）对大小为N×N的图像中的区域块作距离变换，算法过程如下：
1、建立一个大小为N×N的数组F，作如下的初始化：将区域块中的元素设置为0，其余元素设置为200（方阵阶数最高100，距离最大200）；
2、利用掩模1（mask1），左上角开始，从左往右，从上往下遍历数组，将掩模中P点对应的元素的值作如下更新：
![image.png](https://pic.leetcode-cn.com/e13054111912b7eed13f452b42b1cf4f1cea03c673c4737b0440c3b63431deab-image.png)

3、利用掩模2（mask2），右下角开始，从右往左，从下往上遍历数组，将掩模中P点对应的元素的值作如下更新：
![image.png](https://pic.leetcode-cn.com/849488f9597764e759b02491d41092338b182673b1c1e2158be13bd21ab3afba-image.png)
最终得到的更新后的数组即为距离变换的结果。
这个算法过程在图像边界需要做出调整，因为在边界处，掩模不能全部覆盖图像，这时可以将掩模中没有对应元素的位置的值当作200来处理。简单来说就是越界了按最大值扩充。边界的处理大家应该都遇到很多了。
### 算法理解
正向遍历假设最近点在左上方，距离计算按照掩膜的最小值进行距离传递；反向遍历假设最近点在右下方，计算方式同理。遍历方向与掩膜形状是匹配的。
### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> distance(n,vector<int>(n,200));
        //两个掩膜互成相反数，实际只需要定义一个
        int mask_i[4]={-1,-1,0,1};
        int mask_j[4]={0,-1,-1,-1};
        int mask_d[4]={1,2,1,2};
        //初始化+特殊判定
        int sum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j])
                {
                    distance[i][j]=0;
                    sum+=grid[i][j];
                }
        if(sum==0||sum==n*n)
            return -1;
        //正向遍历
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<4;k++)
                {
                    int ni=i+mask_i[k];
                    int nj=j+mask_j[k];
                    //没有对应元素的地方，应以最大值处理
                    int fp=200;
                    if(ni>=0&&ni<n&&nj>=0&&nj<n)
                        fp=distance[ni][nj];
                    distance[i][j]=min(distance[i][j],mask_d[k]+fp);
                }
        //反向遍历
        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--)
                for(int k=0;k<4;k++)
                {
                    int ni=i-mask_i[k];
                    int nj=j-mask_j[k];
                    int fp=200;
                    if(ni>=0&&ni<n&&nj>=0&&nj<n)
                        fp=distance[ni][nj];
                    distance[i][j]=min(distance[i][j],mask_d[k]+fp);
                }
        //在距离图像中获取最大值
        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                res=max(res,distance[i][j]);
        return res;
    }
};
```