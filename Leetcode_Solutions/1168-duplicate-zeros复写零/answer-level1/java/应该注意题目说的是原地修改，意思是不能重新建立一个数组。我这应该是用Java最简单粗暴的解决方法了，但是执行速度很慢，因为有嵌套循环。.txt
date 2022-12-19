```
class Solution {
    public void duplicateZeros(int[] arr) {
        for(int k = 0; k < arr.length-1; k++){
            if(arr[k] == 0){
                for(int j=arr.length-1; j > k+1 ; j--){
                    arr[j] = arr[j-1];
                }
                arr[k+1] = 0;
                ++k;
            }
        }
    }
}
```
