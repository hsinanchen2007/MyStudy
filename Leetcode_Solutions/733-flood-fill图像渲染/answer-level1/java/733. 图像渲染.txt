/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/10
 *
 * 解题思路: 使用oldColor 记录需要更改的像素点的值 然后进行递归处理 (四个方向)
 *
 * 注意: 题目中会出现有像素点本身为1 要更改为1 需要特殊判断 不然会出现递归栈溢出
 *
 */
```
class Solution {
    int oldColor = -1;
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        //像素点本身为1 要更改为1 (本身的值和更改目标值相同) 需要特殊判断 不然会出现递归栈溢出
        if(image[sr][sc] == newColor) return image;
        
        oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        return fill2(image,sr,sc,newColor);

    }
    public int[][] fill2(int[][] image, int sr, int sc, int newColor){
        if(sr - 1 >= 0){
            if(image[sr - 1][sc] == oldColor){
                image[sr - 1][sc] = newColor;
                fill2(image,sr - 1,sc,newColor);
            }
        }

        if(sr + 1 <= image.length - 1){
            if(image[sr + 1][sc] == oldColor ){
                image[sr + 1][sc] = newColor;
                fill2(image,sr + 1,sc,newColor);
            }
        }

        if(sc - 1 >= 0){
            if(image[sr][sc - 1] == oldColor){
                image[sr][sc - 1] = newColor;
                fill2(image,sr,sc - 1,newColor);
            }
        }

        if(sc + 1 <= image[0].length - 1){
            if(image[sr][sc + 1] == oldColor){
                image[sr][sc + 1] = newColor;
                fill2(image,sr,sc + 1,newColor);
            }
        }

        return image;
    }
}
```