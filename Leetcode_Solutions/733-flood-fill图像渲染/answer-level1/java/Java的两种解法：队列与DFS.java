为防止对已上色的点再次上色，需要记录图片上点的旧颜色；   
对于新颜色与旧颜色一致的情况(毫无意义。。。)，直接返回image就行；   
**方法一**：使用队列：
```
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc]) return image;
        int h=image.length, w=image[0].length;  //记录image的长宽
        int[][] direct = {{0,1},{0,-1},{1,0},{-1,0}};  //移动方向的数组
        Queue<int[]> q = new LinkedList<>();  //队列
        q.offer(new int[]{sr,sc});  //队列保存的是位置坐标
        int oldColor = image[sr][sc];  //记录旧颜色
        while(!(q.size()==0)){
            int[] p = q.poll();  //取出队首元素
            image[p[0]][p[1]] = newColor;  //上色
            for(int[] d: direct){  //将四周相同颜色的点的位置入队
                int new_sr = p[0]+d[0];
                int new_sc = p[1]+d[1];
                if(new_sr>=0 && new_sr<h && new_sc>=0 && new_sc<w && image[new_sr][new_sc]==oldColor){
                    q.offer(new int[]{new_sr,new_sc});
                }
            }
        }
        return image;
    }
}
```
**方法二**：DFS:
```
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        coloring(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
    public void coloring(int[][] image,int x,int y,int oldColor,int newColor){
        if(x<0 || x>=image.length || y<0 || y>=image[0].length || image[x][y]!=oldColor){
            return ;  //坐标越界和不同色的情况
        }
        image[x][y] = newColor;  //上色
        coloring(image,x+1,y,oldColor,newColor);
        coloring(image,x-1,y,oldColor,newColor);
        coloring(image,x,y+1,oldColor,newColor);
        coloring(image,x,y-1,oldColor,newColor);
    }
}
```
