### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        for(int i=0;i<matrix.length;i++){
            boolean flag=false;
            flag=binarySearch(matrix[i],0,matrix[i].length,target);
            if(flag)return true;
        }
        return false;
        

    }
    public static boolean binarySearch(int[] A,int lo,int hi,int val){
        
        while(lo<hi){
            int mid=(hi+lo)/2;
            if(val < A[mid])hi=mid;
            else if(val>A[mid])lo=mid+1;
            else return true;
        }
        return false;
    }

}
```