不枉我研究生学图像出身哈哈
其实非常简单：先镜像，再转置即可。
1. 镜像利用swap函数直接搞定，第一行和最后一行对调，第二行和倒数第二行，一次类推。
2. 转置则更简单： swap(mat[i][j], mat[j][i]) 即可，需要注意只能遍历主对角线分开的上三角或者下三角，全遍历的话相当于啥都没做。
code:
```
class Solution {
public:
    /* 学过图像的话就非常简单了，先上下交换再转置就ok了 */
    void MySwap(int &x, int &y)
    {
        int tmp=x;
        x=y;
        y=tmp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int sz= matrix.size();
        for(int i=0; i<sz/2; i++) {
            swap(matrix[i] ,matrix[sz-1-i]); 
        }
        for (int i=0;i<sz;i++) {
            for (int j=0;j<i;j++) {
                MySwap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
```

另外如果真的对旋转任意角度感兴趣：
https://www.jianshu.com/p/f1c8e3299029
### 图像旋转的变换公式。
这个实际上很简单，主要是一些三角函数方面的推导：

![](https://pic.leetcode-cn.com/9dcede7878cb0260ffa055b2000b3f8b8280aa564891eca198f1719e2ca873c3-file_1576765668253)

假设`(x1,y1)`旋转`a`到达`(x2,y2)`，那么根据上图可以写出下面的式子：

![](https://pic.leetcode-cn.com/324d994a108b5380c7211ec3933738ccf3093995d422dc92020b265331cb5e99-file_1576765668269)

展开：

![](https://pic.leetcode-cn.com/c2ca341b3a842c9d5bae7cac99252c852c0a3801b27f4ad79c0fcfecc7e6e028-file_1576765668272)

替换，得到后向映射公式：

![](https://pic.leetcode-cn.com/b4addfb1502f2ed8263eb29eed5fb028b4083b550d347e89e48b9249a9a24d2c-file_1576765668275)

由这个式子也很容易解出前向映射的公式：

![](https://pic.leetcode-cn.com/b16aaa515e685b28a10e2c4f2be426e89a72b0a4c0fe99c91d8036b424272a0c-file_1576765668276)

这便是全部的公式了，图像旋转是可以用矩阵来表示的，我们把后向映射表示出来：

![](https://pic.leetcode-cn.com/f6e2619ca41ac66d5bd0dbe96d3374afa253ed9f2560978e31da0b12248a80b2-file_1576765668278)

### 图像旋转实现的思路。
其实只要是图像变换，无论是旋转还是放大缩小，思路都是基本相同的，就是要寻找一种映射关系，前向映射是由原图映射到目标图，后向映射是从目标图映射到原图，就写程序和复杂度来说，后向映射的复杂度更低，写起来也更容易理解。

后向映射的主要思路：
* 建立目标图。
* 对于目标图中的每一点，映射到原图中的一个点，这个点可能是不存在的（比如小数坐标)，所以需要进行插值处理。
* 插值重建目标图。

对于旋转来说，一般我们习惯绕着中心点进行旋转，所以还要进行坐标变换。

#### C++实现。
借助了opencv的Mat数据类型，主要的还是希望用到其索引的方式，把重点放在旋转本身，如果给定的是数组类型的图像，那么只需要根据行，列，通道这三参数进行变换即可。
* 读入图像，并且进行坐标变换。
```
	Mat img = imread("2.jpg");
	cout << "原图尺寸：" << img.size() << endl;
	imshow("source_img", img);
 
	double angle =-10/180.0f*PI;         //这里就是除的180少写个f，以至于两个int相除肯定是不对的
	int height = img.rows;
	int width = img.cols;	

	//四个定点在旋转坐标系中的位置
	//  1  2
	//  3  4
	int SrcX1 = -width / 2;
	int SrcY1 = height / 2;
	int SrcX2 = width / 2;
	int SrcY2 = height / 2;
	int SrcX3 = -width / 2;
	int SrcY3 = -height / 2;
	int SrcX4 = width / 2;
	int SrcY4 = -height / 2;
	
	double cosAn = std::cos(angle);
	double sinAn = std::sin(angle);
```
这个坐标变换是为了计算目标图像的最小尺寸,这里使用前向映射，由原图映射到目标图：
* 计算目标尺寸并开辟存储空间。
```
	int DstX1 = (int)(SrcX1*cosAn - SrcY1*sinAn +0.5);
	int DstY1 = (int)(SrcX1*sinAn + SrcY1*cosAn +0.5);

	int DstX2 = (int)(SrcX2*cosAn - SrcY2*sinAn +0.5);
	int DstY2 = (int)(SrcX2*sinAn + SrcY2*cosAn +0.5);

	int DstX3 = (int)(SrcX3*cosAn - SrcY3*sin(angle)+0.5);
	int DstY3 = (int)(SrcX3*sinAn + SrcY3*cosAn +0.5);

	int DstX4 = (int)(SrcX4*cosAn - SrcY4*sinAn + 0.5);
	int DstY4 = (int)(SrcX4*sinAn + SrcY4*cosAn + 0.5);

	int DstWidth = max(abs(DstX1 - DstX4), abs(DstX2 - DstX3))+1;
	int DstHeight = max(abs(DstY1 - DstY4), abs(DstY2 - DstY3))+1;
	
	//旋转后的最合适的宽度和高度

	Mat Dst=Mat::zeros(DstHeight,DstWidth, img.type());
	
	//Dst.create(DstHeight, DstWidth, img.type());    //创建DST图像
```
加0.5的目的是四舍五入。

* 后向映射，插值处理，为了简单这里直接用的最邻近插值。
坐标变换是重点：
```
D2S_x = round(double(i - DstWidth / 2.0f)* cosAn  +  double(j - DstHeight / 2.0f)*sinAn + width / 2.0f);
D2S_y = round(-double(i - DstWidth / 2.0f)*sinAn  +  double(j - DstHeight / 2.0f)* cosAn + height / 2.0f);
```
四步走：
1. 变换原点到中心。
2. 后向映射找对应原图中的坐标(可能是小数，也是原点在中心)
3. 映射后的点变换原点到原图左上角。
4. 插值，这里直接用的round取四舍五入，就是最邻近插值了。

```

	//映射回去的原图中的坐标
	int D2S_x=0;     
	int D2S_y=0;

	for (int i = 0; i < DstWidth; i++)
	{
		for (int j = 0; j < DstHeight; j++)
		{
			D2S_x = round(double(i - DstWidth / 2.0f)* cosAn  +  double(j - DstHeight / 2.0f)*sinAn + width / 2.0f);
			D2S_y = round(-double(i - DstWidth / 2.0f)*sinAn  +  double(j - DstHeight / 2.0f)* cosAn + height / 2.0f);
		

			if (Dst.channels() == 1)
			{
				if (D2S_x < 0 || D2S_x >= width || D2S_y < 0 || D2S_y >= height)
					Dst.at<uchar>(j, i) = 0;
				else
					Dst.at<uchar>(j, i) = img.at<uchar>(D2S_y,D2S_x);
			}
			else if (Dst.channels() == 3)
			{
				if (D2S_x < 0 || D2S_x >= width || D2S_y < 0 || D2S_y >= height)
					Dst.at<Vec3b>(j, i) = Vec3b(0, 0, 0);
				else
					Dst.at<Vec3b>(j, i) = img.at<Vec3b>(D2S_y,D2S_x);
			}
		}
	}
```

### 遇见的坑。
* 整型除整型得到的还是整型。
这种错误按理说不该犯，但是matlab写多了就是会犯这种错误。如果需得到double型的数据，记得加上`.f`。
* Mat数据坐标系统。
`at`操作符里面的是先行后列而不是坐标
Mat的坐标系统是横轴为x,纵轴为y，分别对应列和行。
这些东西不确定的时候一定要查一下定义，要不还是很容易出错。