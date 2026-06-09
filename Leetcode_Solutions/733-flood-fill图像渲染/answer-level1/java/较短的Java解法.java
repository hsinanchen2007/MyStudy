想了一下觉得还是最好用helper function
然后就是很简单的操作了
先处理一个位置 然后前后左右四个位置 注意比较的条件

执行用时 : 2 ms, 在所有 Java 提交中击败了 98.68% 的用户 内存消耗 : 42.1 MB , 在所有 Java 提交中击败了 95.15% 的用户
```
class Solution {
    int oldColor = 0;
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        oldColor = image[sr][sc];
         fFill(image, sr, sc, newColor);
        return image;
}
    
    public void fFill(int[][] image, int sr, int sc, int newColor) {
    if(sr>=0&&sr<image.length&&sc>=0&&sc<image[0].length){
            if(image[sr][sc]!=newColor&&image[sr][sc]==oldColor){
                image[sr][sc]=newColor;
                fFill(image, sr, sc+1, newColor);
                fFill(image, sr-1, sc, newColor);
                fFill(image, sr+1, sc, newColor);
                fFill(image, sr, sc-1, newColor);
            }
        }
    
    }
    
}
```
