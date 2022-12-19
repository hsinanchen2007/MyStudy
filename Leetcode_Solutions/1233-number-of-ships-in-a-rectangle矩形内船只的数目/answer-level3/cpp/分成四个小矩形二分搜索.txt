**附上代码**
```
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int solve(Sea sea,int lx,int ly,int rx,int ry){    
        if(lx>rx||ly>ry)return 0;
        if(!(sea.hasShips({rx,ry},{lx,ly})))  return 0;
        
        int x1=(rx+lx)>>1,y1=(ry+ly)>>1;
        int sum=0;
        if(x1==lx&&y1==ly)return 1;
        
        sum+=solve(sea,lx,ly,x1,y1);
        sum+=solve(sea,lx,y1+1,x1,ry);
        sum+=solve(sea,x1+1,y1,rx,ry);
        sum+=solve(sea,x1+1,ly,rx,y1-1);
        //
        return sum;
    }
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        //二分搜索:分成四个小矩形在分别判断
        //二分横坐标&&二分纵坐标：
        int rx=topRight[0],ry=topRight[1];
        int lx=bottomLeft[0],ly=bottomLeft[1];
        return solve(sea,lx,ly,rx,ry);
    }
};
```

