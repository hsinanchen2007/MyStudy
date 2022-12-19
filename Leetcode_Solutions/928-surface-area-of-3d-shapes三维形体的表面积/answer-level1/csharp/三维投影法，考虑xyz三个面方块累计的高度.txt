执行用时 :140 ms, 在所有 C# 提交中击败了100.00%的用户
内存消耗 :24.6 MB, 在所有 C# 提交中击败了33.33%的用户

```
public int SurfaceArea(int[][] grid) {
        var w=grid[0].Length;
        var h=grid.Length;
        int sum=0,wH=0,hH=0;
        for(var i=0;i<h;i++){
            for(var j=0;j<w;j++){
                wH=j-1>=0?grid[i][j-1]:0;
                hH=i-1>=0?grid[i-1][j]:0;
                var val=grid[i][j];
                //计算底部xy平面投影
                if(val>0){
                    sum+=2;
                }
                //计算yz平面投影
                if(val>wH){
                    sum+=(val-wH);
                }else if(val<wH){
                    sum+=(wH-val);
                }
                if(j==w-1){
                    sum+=val;
                }
                //计算xz平面投影
                if(val>hH){
                    sum+=(val-hH);
                }else if(val<hH){
                    sum+=(hH-val);
                }
                if(i==h-1){
                    sum+=val;
                }
            }
        }
       
        return sum;
    }
```
