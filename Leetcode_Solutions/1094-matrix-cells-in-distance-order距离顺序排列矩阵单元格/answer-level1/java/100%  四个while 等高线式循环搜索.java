【题目】:按Manhattan距离长短顺序依次输出坐标

【思路】:首先注意到这道题思路是按照距离顺序输出的。

我们肯定不能先遍历所有的曼哈顿距离，然后排序，再找对应的输出。这样需要两次遍历(一次算距离，一次找对应的点)+一次排序，太费时间。

由于题目需要的是按照曼哈顿距离，我们知道，与某个点具有相同曼哈顿的所有点是正方形，状如等高线。因此，每次我们遍历正方形，在考察范围内的保留。下一次后再外移一格，再遍历对应的等高线正方形，直到矩阵被填满为止。

主要是遍历的时候四条边四个方向，需要四个while。注意边界[0,R-1]和[0,C-1]的判定。

代码如下：

![image.png](https://pic.leetcode-cn.com/ffbbb562c4b1e66371d8c21e368943570c79dd76a02078077b1425f7b3b08215-image.png)

```
public static int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] ans=new int[R*C][2];
        int order=0;//当前顺序
        int point_x=r0,point_y=c0;
        ans[order][0]=r0;ans[order][1]=c0;order++;
        while(order<R*C) {
        	//先上移一格,现在在上侧
        	point_x--;
        	while(point_x<r0) {//从上侧到右侧
        		if(point_x>=0&&point_y<=C-1) {
        			ans[order][0]=point_x;
        			ans[order++][1]=point_y;
        			System.out.println(ans[order-1][0]+","+ans[order-1][1]);
        		}
        		point_x++;point_y++;
        	}
        	
        	while(point_y>c0) {//从右侧到下侧
        		if(point_x<=R-1&&point_y<=C-1) {
        			ans[order][0]=point_x;
        			ans[order++][1]=point_y;
        			System.out.println(ans[order-1][0]+","+ans[order-1][1]);
        		}
        		point_x++;point_y--;
        	}
        	
        	while(point_x>r0) {//从下侧到左侧
        		if(point_x<=R-1&&point_y>=0) {
        			ans[order][0]=point_x;
        			ans[order++][1]=point_y;
        			System.out.println(ans[order-1][0]+","+ans[order-1][1]);
        		}
        		point_x--;point_y--;
        	}
        	
        	while(point_y<c0) {//从左侧到上侧
        		if(point_x>=0&&point_y>=0) {
        			ans[order][0]=point_x;
        			ans[order++][1]=point_y;
        			System.out.println(ans[order-1][0]+","+ans[order-1][1]);
        		}
        		point_x--;point_y++;
        	}
     	
        }
        return ans;
    }
```
