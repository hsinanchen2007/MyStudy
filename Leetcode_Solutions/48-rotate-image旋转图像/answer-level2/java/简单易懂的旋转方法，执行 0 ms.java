
![image.png](https://pic.leetcode-cn.com/48038c58cba560611471ad47663a7e5373bc47f287797cb2cbc4f5ce30a20fe0-image.png)

**思路分析:**
    
例如：
        
![image.png](https://pic.leetcode-cn.com/a44c2c19760f69d2e068340680ae3027c987483f38fef6e83b2ca1f3c821f805-image.png)
观察上面数组可知，图形的四个角数字为```1,4,16,13```，对应二维数组下标为```[0,0],[0,3],[3,0],[3,3]```，图形旋转90°相当于：
```
[0,0]->[0,3]
[0,3]->[3,3]
[3,3]->[3,0]
[3,0]->[0,0]
```
![image.png](https://pic.leetcode-cn.com/bd3924c84cb3539d1f99ce50da4e1186537d884194c6beff2d67e0ed015cc8fa-image.png)
所以根据下标的转换可以得出规律：

```
[0,0]->[0,3] 列坐标依次++
[0,3]->[3,3] 行坐标依次++
[3,3]->[3,0] 列坐标依次--
[3,0]->[0,0] 行坐标依次--
```
以上就是最外圈旋转，然后再用相同方法内圈旋转，只需要重新选定左上角和右下角点的下标（得知左上角和右下角就可知左下角和右上角）。


```Java []
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix==null|| matrix.length==0){
            return;
        }
        //左上角下标x,y
        int xl=0;
        int yl=0;
        //右下角下标x,y
        int xr=matrix.length-1;
        int yr=matrix.length-1;
        while(xl<xr){
            //遍历圈数
            realRotate(matrix,xl++,yl++,xr--,yr--);
        }
    }

    public void realRotate(int[][] nums,int xl,int yl,int xr,int yr){
        //实际内部旋转
        int length=yr-yl;
        int temp=0;
        for(int i=0;i<length;i++){
            temp=nums[xl][yl+i];
            //左下角换到左上角
            nums[xl][yl+i]=nums[xr-i][yl];
            //右下角换到左下角
            nums[xr-i][yl]=nums[xr][yr-i];
            //右上角换到右下角
            nums[xr][yr-i]=nums[xl+i][yr];
            //左上角到右上角
            nums[xl+i][yr]=temp;
        }
    }
}
```


