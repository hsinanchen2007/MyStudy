### 解题思路
这道题看起来很难，其实如何找对了理解的方法就会非常地容易。
我这里是用了画格子的方法来解题的，废话不多说，直接上图！
[[1,1,1][1,0,1][1,1,1]]
![表面积.PNG](https://pic.leetcode-cn.com/2dc1e90750d954a91ea30fd87562960e15a859c71a17d516d423b53365b6e8f3-%E8%A1%A8%E9%9D%A2%E7%A7%AF.PNG)

(由于没钱买pad,所以是用鼠标画的，线条会比较扭曲，不要介意。。。)

由图，根据例子，可以得到一个3X3的方格（行列的最大值确定）
在每一格都标注这个对应位置叠加的方块数量，可知，只要是这个位置存在方块，那么，就贡献一个
上表面积和一个下表面积。位置（1，1）数值为0,即没有方块，此处对上表面积和下表面积没有贡献。
再者，每个方块有四个单位的侧面积，我们研究的就是如何计算遮挡的面积，结果减掉就可以了。
如图，（0，0）位置上，其上侧边和右侧边已经标出，其对应的邻居格子数值均为1，遮挡的面积
是两个邻居格子较小的那一个的值的两倍（可以自己画三维图来验证）；遍历每个格子，将其上邻居格子和右
邻居格子之间遮挡的表面积求出，在之后的总表面积减去就行了。

### 代码

```cpp
class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int count1 = 0,count2=0, original_area = 0, subtract_area = 0;//count1在所有的格子里，
		//有几个格子值不为0，count2统计方块总数
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j])
					count1++;//格子是0，不计数
				count2 += grid[i][j];
				if ( j + 1 < grid[i].size()) 
					subtract_area += (min(grid[i][j], grid[i][j + 1]) * 2); //上邻居格子之间的遮挡面积
				if(i + 1 < grid.size())
					subtract_area += (min(grid[i][j], grid[i + 1][j])*2);  //右邻居格子之间的遮挡面积
				
			}
		}
		original_area = count1*2 + count2 * 4;  //总面积是格子不为0的数*2+总的方块数*4
		int result_area = original_area - subtract_area;  //所求既是总面积减去遮挡的面积
		return result_area;
	}
};
```