### 解题思路
此处撰写解题思路   binary search 

### 代码

```java
import java.util.ArrayList;
import java.util.Collections;
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        ArrayList<Integer> array=new ArrayList<Integer>();
        int n=matrix.length;
        boolean a=false;
        if(n>=1){
        int m=matrix[n-1].length;
        if(m>0){
       for(int i=0;i<=n-1;i++){
           for(int j=0;j<=m-1;j++){
               int p=matrix[i][j];
               array.add(p);
           }
       }
       Collections.sort(array);
       int begin=0;int end=array.size()-1;
       int time=0;
       while(a==false&&time<=array.size()){
           time++;
       int mid=(begin+end)/2;
       if(target==array.get(mid)){
           a=true;
       }else if(target>array.get(mid)){
           begin=mid+1;
       }else if(target<array.get(mid)){
           end=mid-1;
       }
       }
        }else{
            a=false;
        }
        }else {
             a=false;
        }
      return  a;
    }
}
```