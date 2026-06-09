```
class Solution {
    public int missingNumber(int[] arr) {
        int delta = (arr[arr.length-1]-arr[0])/(arr.length);
        if(delta == 0){
            return arr[0];
        }
        for(int i=0;i<arr.length-1;++i){
            if(arr[i+1]-arr[i]!=delta){
                return arr[i]+delta;
            }
        }
        return -1;
    }
}
```
