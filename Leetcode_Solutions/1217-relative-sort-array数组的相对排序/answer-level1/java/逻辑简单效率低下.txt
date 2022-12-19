

换就完事了

```
class Solution {
    public void swap(int[] A,int a,int b){
        int t=A[a];
        
        A[a]=A[b];
        A[b]=t;
    }
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int count=0;
        for(int j=0;j<arr2.length;j++){
            
            for(int i=0;i<arr1.length;i++){
                if(arr1[i]==arr2[j]){
                    swap(arr1,i,count++); 
                }
            }
        }
        Arrays.sort(arr1,count,arr1.length);
        return arr1;
               
    }
}
```
