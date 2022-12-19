题目确实没有讲得特别清楚，所以我开始也不明白。题目意思是指定一个点image[sr][sc],需要找到与其颜色相同的连成一整块的点，值相等的点颜色相等，上下左右的关系代表相连接
![image.png](https://pic.leetcode-cn.com/36dcd1e880ff7a51c0bbb01fc888681a070b1dcbf50f0a8e593082d1d2c5d7d2-image.png)
指定点(1,1)检查此坐标位置上下左右与之相同的点

![image.png](https://pic.leetcode-cn.com/221269c5bd35d0dc6d225bbe8bbc107f5949091ed3cefa132be6878308bbae21-image.png)

找到的点坐标位置是(0,1)和(1,0)的点，再重复上述操作
![image.png](https://pic.leetcode-cn.com/f7c3420d2fa863a3c6e0ac511538246aeabcd55e225ca3905a2a5006196141da-image.png)
所有的点找到了，将这些点改为指定颜色就行了。

![image.png](https://pic.leetcode-cn.com/c86d8c0cb49663d1e764711324b1cecae2b344c279a8df95e6e24bd547d1a5c2-image.png)
其实就是找连续的周围相同的的点，它们颜色一样，是一个整体，用递归可以简单解决

```
class Solution {
    public void helper(int[][] image,int sr,int sc,int oldColor,int newColor){
        if(image.length<=sr||sr<0||image[0].length<=sc||sc<0)return;//如果检索的点处于矩阵边界，遇到其上下左右点不存在
        if(oldColor==image[sr][sc]&&image[sr][sc]!=newColor){//当前颜色与指定颜色相同，且不等于新颜色
            image[sr][sc]=newColor;
            helper(image,sr-1,sc,oldColor,newColor);//上
            helper(image,sr+1,sc,oldColor,newColor);//下
            helper(image,sr,sc-1,oldColor,newColor);//左
            helper(image,sr,sc+1,oldColor,newColor);//右
        }
        
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        helper(image,sr,sc,image[sr][sc],newColor);
        return image;    
    }
}

```
