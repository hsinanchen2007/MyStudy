尝试把区域分成四块不相交的区域，如果不能分了，就直接求解该区域的船只数量；

如果能分，对于每一块区域，先调用sea的函数判断该区域是否有船，
如果有，递归调用，
如果无，则不理，
把每个递归调用的结果加起来，就是该区域的船只数量，返回给上层函数。代码如下:
```
class Solution {
    private Sea sea;
    public int countShips(Sea sea, int[] topRight, int[] bottomLeft) {
        this.sea = sea;
        return count(topRight,bottomLeft);
    }
    private int count(int[] topRight, int[] bottomLeft){

        int x1 = bottomLeft[0];
        int y1 = topRight[1];
        int x2 = topRight[0];
        int y2 = topRight[1];
        int x3 = bottomLeft[0];
        int y3 = bottomLeft[1];
        int x4 = topRight[0];
        int y4 = bottomLeft[1];
        int midx = (x1 + x2) >> 1;
        int midy = (y1 + y3) >> 1;
        if(x2 - x1 < 2 || y1 - y3 < 2){
            int res = 0;
            for(int i = x1; i <= x2; i ++){
                for(int j = y3; j <= y1; j ++){
                    int[] a = {i,j};
                    if(sea.hasShips(a,a)){
                        res ++;
                    }
                }
            }
            return res;
        }
        int res = 0;
        int[] a1 = {midx,y1};
        int[] a2 = {x1,midy};
        if(sea.hasShips(a1,a2)) res += count(a1,a2);
        int[] a3 = {x2,y2};
        int[] a4 = {midx + 1,midy};
        if(sea.hasShips(a3,a4)) res += count(a3,a4);
        int[] a5 = {midx ,midy - 1};
        int[] a6 = {x3,y3};
        if(sea.hasShips(a5,a6)) res += count(a5,a6);
        int[] a7 = {x4,midy - 1};
        int[] a8 = {midx + 1,y4};
        if(sea.hasShips(a7,a8)) res += count(a7,a8);
        return res;

    }


}
```
