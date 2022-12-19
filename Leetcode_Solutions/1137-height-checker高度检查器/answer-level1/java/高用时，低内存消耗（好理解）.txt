```
class Solution {
    public int heightChecker(int[] heights) {
//         拷贝一份数组
        int [] a=heights.clone();
//         冒泡排序
      for(int i=0;i<heights.length;i++){
        for(int j=0;j<heights.length;j++){
             if(heights[i]<heights[j]){
                  int tem=0;
                 tem=heights[i];
                 heights[i]=heights[j];
                 heights[j]=tem;
             }
         }           
      }
        
        // 比较相同索引处的不同
        int xp=0;
    for(int m=0,x=0;m<heights.length;m++,x++){
            if(heights[x]!=a[m]){
                 xp++;
            }
        
    }
   return xp;      
    }
}
```
