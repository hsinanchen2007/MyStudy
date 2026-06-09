```
class Solution {
    public int[] replaceElements(int[] arr) {
        if(arr.length == 0) return arr;
        int lastMaxVal = arr[arr.length-1];
        arr[arr.length-1] = -1;
        for(int i = arr.length-2; i >= 0; i--){
            int tmp = arr[i];
            arr[i] = lastMaxVal;
            lastMaxVal = Math.max(tmp,lastMaxVal);
        }
        return arr;
    }
}
```
