```
public int[][] MatrixReshape(int[][] nums, int r, int c) {
        var w=nums[0].Length;
        var h=nums.Length;
        if(w*h!=r*c){
            return nums;
        }
        var res=new int[r][];
        for(var i=0;i<r;i++){
            res[i]=new int[c];
        }
        for(var i=0;i<h;i++){
        
            for(var j=0;j<w;j++){
                var t=i*w+j;
                res[t/c][t%c]=nums[i][j];
            }
        }
        return res;
    }
```
