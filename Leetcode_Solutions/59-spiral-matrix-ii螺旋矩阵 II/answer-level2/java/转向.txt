1、设置标志位， 按往右下左上顺序更改标记
2、转向条件：到数组边界或下一位上不为0（题目明确为1至n*n）


```
 public int[][] generateMatrix(int n) {
        int i=0,j=0;
        int[][] rs=new int[n][n];
        int  trun=0;
        for(int num=1;num<=n*n;num++){
            rs[i][j]=num;
            if(trun==0){
                j++;
                if(j>=n||rs[i][j]!=0){
                    j--;
                    trun=1;
                }
            }
            if(trun==1){
                i++;
                if(i>=n||rs[i][j]!=0){
                    i--;
                    trun=2;
                }
            }
            if(trun==2){
                j--;
                if(j<0||rs[i][j]!=0){
                    j++;
                    trun=3;
                }
            }
            if(trun==3){
                i--;
                if(i<0||rs[i][j]!=0){
                    i++;
                    j++;
                    trun=0;
                    
                }
            } 
        }
        return rs;
        
    }
```



